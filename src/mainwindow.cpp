#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    data=nullptr;
    cellInfo=nullptr;
    rules=new Rules;
    winnerWindow = new WinnerWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
}

Data *MainWindow::getData()
{
    return data;
}

void MainWindow::receiveData(int players,int bots,std::vector<QString> names){
    //Принять данные от стартового окна
    data=new Data(players,bots,names);
    startSettings();
    cellInfo=new CellInfo(nullptr,this);
    cellInfo->startSettings();
    connections();
}

void MainWindow::connections()
{
    //Метод соединяет кнопки с сигналами и слотами
    Node<Cell*>*temp=data->getField().getFirst();
    QAbstractButton*button;
    QGridLayout*grid=qobject_cast<QGridLayout*>(ui->gridLayout);
    QVBoxLayout*vlayout;
    connect(this,&MainWindow::openCellInfo,cellInfo,&CellInfo::open);
    for(int i=0;i<40;i++){
        vlayout=qobject_cast<QVBoxLayout*>(grid->itemAtPosition(temp->value->getPosX(),temp->value->getPosY())->layout());
        button=qobject_cast<QAbstractButton*>(vlayout->itemAt(0)->widget());
        button->installEventFilter(this);
        button->setStyleSheet(data->getImages()[i][0]);
        connect(button,&QAbstractButton::clicked,this,[=](){
            emit openCellInfo(temp);
        });

        connect(button,&QAbstractButton::clicked,cellInfo,&QWidget::show);
        temp=temp->next;
    }
    vlayout=qobject_cast<QVBoxLayout*>(ui->verticalLayout_2->layout());
    for(int i=0;i<5;i++){
        button=qobject_cast<QAbstractButton*>(vlayout->itemAt(i)->widget());
        button->installEventFilter(this);
    }

    connect(ui->rollButton,&QAbstractButton::clicked,this,&MainWindow::rollPressed);
    connect(ui->finishButton,&QAbstractButton::clicked,this,&MainWindow::finishPressed);
    connect(ui->rerollButton,&QAbstractButton::clicked,this,&MainWindow::rerollPressed);
    connect(ui->forfeitButton,&QAbstractButton::clicked,this,&MainWindow::forfeitPressed);
    connect(ui->aboutButton, &QAbstractButton::clicked,rules,&QWidget::show);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    //Метод обрабатывает вхождение курсора на кнопки
    Node<Cell*>*temp=data->getField().getFirst();
    QGridLayout*grid=qobject_cast<QGridLayout*>(ui->gridLayout);
    QVBoxLayout*vlayout;
    QAbstractButton* target=qobject_cast<QAbstractButton*>(object);
    QAbstractButton*button;
    for(int i=0;i<40;i++){
        vlayout=qobject_cast<QVBoxLayout*>(grid->itemAtPosition(temp->value->getPosX(),temp->value->getPosY())->layout());
        button=qobject_cast<QAbstractButton*>(vlayout->itemAt(0)->widget());
        if(target==button){
            if(event->type()==QEvent::Enter){
            button->setStyleSheet(data->getImages()[i][1]);
            return true;
            }
            else if(event->type()==QEvent::Leave){
            button->setStyleSheet(data->getImages()[i][0]);
            return false;
            }
        }
        temp=temp->next;
    }
    vlayout=qobject_cast<QVBoxLayout*>(ui->verticalLayout_2->layout());
    for(int i=0;i<5;i++){
        button=qobject_cast<QAbstractButton*>(vlayout->itemAt(i)->widget());
        if(target==button){
            if(event->type()==QEvent::Enter&&button->isEnabled()){
            button->setStyleSheet(data->getImages()[i+40][1]);
            return true;
            }
            else if(event->type()==QEvent::Leave&&button->isEnabled()){
            button->setStyleSheet(data->getImages()[i+40][0]);
            return false;
            }
            else if(event->type()==QEvent::Leave&&!button->isEnabled()){
            button->setStyleSheet(data->getImages()[i+40][0]);
            return false;
            }
        }
    }
    return false;
}


void MainWindow::roll()
{
    //Бросок костей, вывод информации на экран
    srand(data->getSeed());
    int roll= 2+rand()%11;
    ui->value->setText(QString::number(roll));
    ui->rollButton->setDisabled(1);
    log(data->getCurrent()->value->getName()+" выбрасывает "+ui->value->text());
    for(int i=0;i<roll;i++){
        //Перемещение фишки игрока на одну клетку по таймеру
        timer(200);
        setIcon(data->getCurrent()->value->getPos()->value->getPosX(), data->getCurrent()->value->getPos()->value->getPosY(),"border-image: url(:/images/casual.png) stretch; ", data->getCurrent()->value->getID());
        data->getCurrent()->value->setPos(data->getField().getNext(data->getCurrent()->value->getPos()));
        setIcon(data->getCurrent()->value->getPos()->value->getPosX(), data->getCurrent()->value->getPos()->value->getPosY(),data->getCurrent()->value->getIcon(), data->getCurrent()->value->getID());
        startCheck(); //Проверить, стоит ли игрок на старте
    }
    data->saveBuffer(); //Сохранить данные в буфер
    rentCheck();        //Вычислить аренду

}

void MainWindow::botCycle()
{
    //Цикл ходов для ботов
    int money;
    while(!data->getCurrent()->value->isPlayer()){
        roll(); //бросок костей
        if(data->getCurrent()->value->getMoney()<0) forfeitPressed(); //сдаться, если отрицательный баланс
        if(eventCheck()) break; //Окончить ход, если бот на событийной клетке
        money=data->getCurrent()->value->getMoney(); //вычислить баланс бота
        //Покупка собственности ботом
        if(data->getCurrent()->value->getPos()->value->isEstate()||data->getCurrent()->value->getPos()->value->isHouse()) data->getCurrent()->value->buy();
        if(money>data->getCurrent()->value->getMoney()) log(data->getCurrent()->value->getName()+" купил "+data->getCurrent()->value->getPos()->value->getName());
        if(data->getCurrent()->next->value->isPlayer()) finishPressed(); //Закончить цикл, если следующий участник реальный игрок
        else{
            //Передать ход следующему боту
            data->setSeed(QTime::currentTime().msec());
            data->setNextCurrent();
            timer(1000);
        }
    }
}

void MainWindow::log(QString info)
{
    //Вывод информации на экран, всего 3 строки для вывода
    //Неактуальная информация стирается, вместо нее более новая
    QVBoxLayout* vlayout=qobject_cast<QVBoxLayout*>(ui->logLayout->layout());
    QLabel* label;
    QLabel* prev_label;
    for(int i=2;i>0;i--){
        prev_label=qobject_cast<QLabel*>(vlayout->itemAt(i-1)->widget());
        label=qobject_cast<QLabel*>(vlayout->itemAt(i)->widget());
        label->setText(prev_label->text());
    }

    label=qobject_cast<QLabel*>(vlayout->itemAt(0)->widget());
    label->setText(info);
}


void MainWindow::updateHouseLabel(Cell *cell,int id)
{
    //Метод заполняет ячейки домами, которые уже куплены кем-то
    QString houses="";
    QAbstractButton* target;
    House*house;

    if(cell==nullptr){
        Node<Cell*>*temp=data->getField().getFirst()->next;
        for(;temp!=data->getField().getFirst();temp=temp->next){
            if(temp->value->isHouse()){
                house=dynamic_cast<House*>(temp->value);
                if(house->getOwnerID()==id){
                target=getButtonAt(house->getPosX(),house->getPosY());
                target->setText("");
                }
            }
        }
        return;
    }
    target=getButtonAt(cell->getPosX(),cell->getPosY());
    house=dynamic_cast<House*>(cell);
    if(house->getHouses()==5){
        target->setText("D");
        return;
    }
    else{
        for(int i=0;i<house->getHouses();i++) houses+="0";
    }
    target->setText(houses);
}

void MainWindow::startCheck()
{
    //Если игрок на старте, заплатить ему 200
    if(data->getCurrent()->value->getPos()->value->getPosX()==10&&data->getCurrent()->value->getPos()->value->getPosY()==10){
        log(data->getCurrent()->value->getName()+" получает 200 за пересечение старта!");
        data->getCurrent()->value->pay(-200);
        updateMoney();
    }
}

void MainWindow::prisonCheck()
{
    //Если игрок попал в тюрьму, он завершает ход и пропускает следующий
    if(data->getCurrent()->value->getPos()->value->getPosX()==0&&data->getCurrent()->value->getPos()->value->getPosY()==10){
        data->getCurrent()->value->setPos(data->getCellByPos(10,0));
        setIcon(0,10,"border-image: url(:/images/casual.png) stretch; ", data->getCurrent()->value->getID());
        setIcon(10,0,data->getCurrent()->value->getIcon(), data->getCurrent()->value->getID());
    }

    if(data->getCurrent()->value->getPos()->value->getPosX()==10&&data->getCurrent()->value->getPos()->value->getPosY()==0){
        data->getCurrent()->value->setSkip(1);
        log(data->getCurrent()->value->getName()+" попадает в тюрьму!");
        finishPressed();
    }
}

void MainWindow::rentCheck()
{
    //Вычисление аренды
    //Если не 0 - заплатить владельцу
    //Вывести об этом информацию на экран
    if(data->getActualRent()!=0){
        Estate*estate=dynamic_cast<Estate*>(data->getCurrent()->value->getPos()->value);
        Node<Entity*>*temp=data->getByID(estate->getOwnerID());
        log(data->getCurrent()->value->getName()+" платит аренду на "+data->getCurrent()->value->getPos()->value->getName()+
        " в размере "+QString::number(data->getActualRent())+'$');
        data->getCurrent()->value->pay(data->getActualRent());
        if(temp) temp->value->pay(-data->getActualRent());
        updateMoney();
    }
}

bool MainWindow::eventCheck()
{
    //Проверяет, стоит ли игрок на какой-либо событийной ячейке
    if(data->getCurrent()->value->getPos()->value->isEvent()){
        Event* event=dynamic_cast<Event*>(data->getCurrent()->value->getPos()->value);
        if(event->getChance()==1){
            callChance();
            finishPressed();
            return 1;
        }

        else if(event->getSkip()==1){
            prisonCheck();
            return 1;
        }

        else if(event->getGift()<0){
            data->getCurrent()->value->pay(-event->getGift());
            log(data->getCurrent()->value->getName()+" заплатил налог в размере "+QString::number(-event->getGift())+'$');
            finishPressed();
            return 1;

        }
    }
    return 0;
}

void MainWindow::callChance()
{
    //Вытянуть карту шанс (случайно)
    srand(data->getSeed());
    int chance=1+rand()%10;

    switch(chance){
    case 1:
        data->getCurrent()->value->pay(50);
        log(data->getCurrent()->value->getName()+" платит "+QString::number(50)+'$'+" за превышение скорости");
        break;
    case 2:
        data->getCurrent()->value->pay(25);
        log(data->getCurrent()->value->getName()+" платит "+QString::number(25)+'$'+" за посещение врача");
        break;
    case 3:
        data->getCurrent()->value->pay(100);
        log(data->getCurrent()->value->getName()+" платит "+QString::number(100)+'$'+" по ошибке");
        break;
    case 4:
        data->getCurrent()->value->pay(50);
        data->getCurrent()->next->value->pay(-50);
        log(data->getCurrent()->value->getName()+" платит "+QString::number(50)+"$ "+data->getCurrent()->next->value->getName()+" по поводу дня рождения");
        break;
    case 5:
        data->getCurrent()->value->pay(50);
        data->getCurrent()->prev->value->pay(-50);
        log(data->getCurrent()->value->getName()+" платит "+QString::number(50)+"$ "+data->getCurrent()->prev->value->getName()+" по поводу дня рождения");
        break;
    case 6:
        data->getCurrent()->value->pay(-50);
        log(data->getCurrent()->value->getName()+" находит "+QString::number(50)+'$'+" на дороге");
        break;
    case 7:
        data->getCurrent()->value->pay(-100);
        log(data->getCurrent()->value->getName()+" получает "+QString::number(100)+'$'+" по ошибке банка");
        break;
    case 8:
        data->getCurrent()->value->pay(-200);
        log(data->getCurrent()->value->getName()+" получает "+QString::number(200)+'$'+" по наследству");
        break;
    case 9:
        data->getCurrent()->value->pay(-50);
        data->getCurrent()->next->value->pay(50);
        log(data->getCurrent()->value->getName()+" получает от "+data->getCurrent()->next->value->getName()+" "+QString::number(50)+"$ "+" по поводу дня рождения");
        break;
    case 10:
        data->getCurrent()->value->pay(-50);
        data->getCurrent()->prev->value->pay(50);
        log(data->getCurrent()->value->getName()+" получает от "+data->getCurrent()->prev->value->getName()+" "+QString::number(50)+"$ "+" по поводу дня рождения");
        break;
    }
}

void MainWindow::timer(int duration)
{
    //Установить таймер (в мс)
    //Все процессы в программе прерываются
    QElapsedTimer timer;
    timer.start();
    while(true)
    {
        qApp->processEvents();
        if(timer.elapsed() > duration) break;
    }
}


QAbstractButton *MainWindow::getButtonAt(int x, int y)
{
    //Возвращает кнопку по ее позиции
    QGridLayout*grid=qobject_cast<QGridLayout*>(ui->gridLayout);
    QVBoxLayout*vlayout=qobject_cast<QVBoxLayout*>(grid->itemAtPosition(x,y)->layout());
    return qobject_cast<QAbstractButton*>(vlayout->itemAt(0)->widget());
}

bool MainWindow::endgame()
{
    //Завершение игры (если остался 1 игрок), вывод победителя
    if(data->getPlayers().getSize()==1){
        this->hide();
        winnerWindow->getWinnerLabel()->setText(data->getCurrent()->value->getName());
        winnerWindow->show();
        return 1;
    }
    return 0;
}

void MainWindow::updateMoney()
{
    //Обновить информацию о балансе участников
    QVBoxLayout*vlayout=qobject_cast<QVBoxLayout*>(ui->verticalLayout->layout());
    QLabel*label;
    Node<Entity*>*entity=data->getPlayers().getFirst();
    QString buffer;
    for(int i=0; i<data->getPlayers().getSize();i++){
        label=qobject_cast<QLabel*>(vlayout->itemAt((entity->value->getID()-1)*2+1)->widget());
        buffer=QString::number(entity->value->getMoney());
        label->setText(buffer+'$');
        entity=entity->next;
    }
}


void MainWindow::press(Node<Cell*>* cell)
{
    //Передать данные информационному окну
    emit openCellInfo(cell);
}

void MainWindow::rollPressed()
{
    //Обработать нажатие кнопки "бросить кости"
    roll();
    ui->finishButton->setDisabled(0);
    ui->rerollButton->setDisabled(0);
    eventCheck();
}

void MainWindow::rerollPressed()
{
    //Обработать нажатие клавиши "перебросить кости"
    srand(data->getSeed());
    int roll= 2+rand()%11;
    data->loadBuffer();
    updateMoney();
    updateHouseLabel();
    setIcon(data->getCurrent()->value->getPos()->value->getPosX(), data->getCurrent()->value->getPos()->value->getPosY(),"border-image: url(:/images/casual.png) stretch; ", data->getCurrent()->value->getID());
    data->getCurrent()->value->setPos(data->getField().getPrevN(data->getCurrent()->value->getPos(),roll));
    setIcon(data->getCurrent()->value->getPos()->value->getPosX(), data->getCurrent()->value->getPos()->value->getPosY(),data->getCurrent()->value->getIcon(), data->getCurrent()->value->getID());
    ui->rerollButton->setDisabled(1);
    ui->rollButton->setDisabled(0);
    ui->finishButton->setDisabled(1);
    log(data->getCurrent()->value->getName()+" решает перебросить!");
}

void MainWindow::finishPressed()
{
    //Обработать нажатие клавиши "завершить ход"
    if(data->getCurrent()->value->getMoney()<0){
        log("У Вас отрицательный баланс, заложите что-нибудь, чтобы продолжить");
        return;
    }
    data->setSeed(QTime::currentTime().msec());
    data->setNextCurrent();
    updateMoney();
    updateHouseLabel();
    ui->rerollButton->setDisabled(1);
    ui->finishButton->setDisabled(1);
    ui->forfeitButton->setDisabled(1);

    if(data->getCurrent()->value->isPlayer()){
        ui->rollButton->setDisabled(0);
        ui->forfeitButton->setDisabled(0);
    }
    else{
        //Запустить цикл ботов, если данный участник - бот
        ui->rollButton->setDisabled(1);
        botCycle();
    }

}

void MainWindow::forfeitPressed()
{
    //Обрабатывает нажатие кнопки "сдаться"
    Entity* loser=data->getCurrent()->value;
    data->setNextCurrent();
    log(loser->getName()+" сдается");
    data->updateAfterForfeit(loser->getID());
    updateHouseLabel(nullptr,loser->getID());
    setIcon(loser->getPos()->value->getPosX(), loser->getPos()->value->getPosY(),"border-image: url(:/images/casual.png) stretch; ", loser->getID());
    data->getPlayers().popValue(loser);
    data->getPlayersBuffer().popValue(loser);
    if(endgame()) return;
    data->setSeed(QTime::currentTime().msec());
    updateMoney();
    updateHouseLabel();
    ui->rerollButton->setDisabled(1);
    ui->finishButton->setDisabled(1);
    ui->forfeitButton->setDisabled(1);
    if(data->getCurrent()->value->isPlayer()){
        ui->rollButton->setDisabled(0);
        ui->forfeitButton->setDisabled(0);
    }
    else{
        ui->rollButton->setDisabled(1);
        botCycle();
    }
}


void MainWindow::startSettings()
{
    //Стартовые настройки интерфейса
    QWidget::setFixedSize(1520,1080);
    setStyleSheet("QMainWindow{border-image:url(:images/background.png); stretch}");
    ui->player1name->setStyleSheet("border-image: url(:/images/player1name.png) stretch; ");
    ui->player2name->setStyleSheet("border-image: url(:/images/player2name.png) stretch; ");
    ui->player3name->setStyleSheet("border-image: url(:/images/player3name.png) stretch; ");
    ui->player4name->setStyleSheet("border-image: url(:/images/player4name.png) stretch; ");
    ui->player1money->setStyleSheet("border-image: url(:/images/player1money.png) stretch; ");
    ui->player2money->setStyleSheet("border-image: url(:/images/player2money.png) stretch; ");
    ui->player3money->setStyleSheet("border-image: url(:/images/player3money.png) stretch; ");
    ui->player4money->setStyleSheet("border-image: url(:/images/player4money.png) stretch; ");
    ui->value->setStyleSheet("border-image: url(:/images/value.png) stretch; ");
    ui->aboutButton->setStyleSheet("border-image: url(:/images/about.png) stretch; ");
    ui->rollButton->setStyleSheet("border-image: url(:/images/roll.png) stretch; ");
    ui->forfeitButton->setStyleSheet("border-image: url(:/images/forfeit.png) stretch; ");
    ui->rerollButton->setStyleSheet("border-image: url(:/images/reroll.png) stretch; ");
    ui->finishButton->setStyleSheet("border-image: url(:/images/finish.png) stretch; ");
    ui->startButton->setStyleSheet("border-image: url(:/images/start.png) stretch; ");
    ui->brown1Button->setStyleSheet("border-image: url(:/images/brown1.png) stretch; ");
    ui->chance1Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->chance2Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->chance3Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->chance4Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->chance5Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->chance6Button->setStyleSheet("border-image: url(:/images/chance.png) stretch; ");
    ui->brown2Button->setStyleSheet("border-image: url(:/images/brown2.png) stretch; ");
    ui->tax1Button->setStyleSheet("border-image: url(:/images/tax1.png) stretch; ");
    ui->tax2Button->setStyleSheet("border-image: url(:/images/tax2.png) stretch; ");
    ui->train1Button->setStyleSheet("border-image: url(:/images/train1.png) stretch; ");
    ui->train2Button->setStyleSheet("border-image: url(:/images/train2.png) stretch; ");
    ui->train3Button->setStyleSheet("border-image: url(:/images/train3.png) stretch; ");
    ui->train4Button->setStyleSheet("border-image: url(:/images/train4.png) stretch; ");
    ui->prisonButton->setStyleSheet("border-image: url(:/images/prison.png) stretch; ");
    ui->gotoprisonButton->setStyleSheet("border-image: url(:/images/gotoprison.png) stretch; ");
    ui->parkingButton->setStyleSheet("border-image: url(:/images/parking.png) stretch; ");
    ui->blue1Button->setStyleSheet("border-image: url(:/images/blue1.png) stretch; ");
    ui->blue2Button->setStyleSheet("border-image: url(:/images/blue2.png) stretch; ");
    ui->blue3Button->setStyleSheet("border-image: url(:/images/blue3.png) stretch; ");
    ui->pink1Button->setStyleSheet("border-image: url(:/images/pink1.png) stretch; ");
    ui->pink2Button->setStyleSheet("border-image: url(:/images/pink2.png) stretch; ");
    ui->pink3Button->setStyleSheet("border-image: url(:/images/pink3.png) stretch; ");
    ui->orange1Button->setStyleSheet("border-image: url(:/images/orange1.png) stretch; ");
    ui->orange2Button->setStyleSheet("border-image: url(:/images/orange2.png) stretch; ");
    ui->orange3Button->setStyleSheet("border-image: url(:/images/orange3.png) stretch; ");
    ui->red1Button->setStyleSheet("border-image: url(:/images/red1.png) stretch; ");
    ui->red2Button->setStyleSheet("border-image: url(:/images/red2.png) stretch; ");
    ui->red3Button->setStyleSheet("border-image: url(:/images/red3.png) stretch; ");
    ui->yellow1Button->setStyleSheet("border-image: url(:/images/yellow1.png) stretch; ");
    ui->yellow2Button->setStyleSheet("border-image: url(:/images/yellow2.png) stretch; ");
    ui->yellow3Button->setStyleSheet("border-image: url(:/images/yellow3.png) stretch; ");
    ui->green1Button->setStyleSheet("border-image: url(:/images/green1.png) stretch; ");
    ui->green2Button->setStyleSheet("border-image: url(:/images/green2.png) stretch; ");
    ui->green3Button->setStyleSheet("border-image: url(:/images/green3.png) stretch; ");
    ui->darkblue1Button->setStyleSheet("border-image: url(:/images/darkblue1.png) stretch; ");
    ui->darkblue2Button->setStyleSheet("border-image: url(:/images/darkblue2.png) stretch; ");
    ui->electricityButton->setStyleSheet("border-image: url(:/images/electricity.png) stretch; ");
    ui->watersupplyButton->setStyleSheet("border-image: url(:/images/watersupply.png) stretch; ");
    ui->finishButton->setDisabled(1);
    ui->rerollButton->setDisabled(1);

    QVBoxLayout*vlayout=qobject_cast<QVBoxLayout*>(ui->verticalLayout->layout());
    QLabel*label;
    Node<Entity*>*entity=data->getPlayers().getFirst();
    QString buffer;
    for(int i=0; i<data->getPlayers().getSize();i++){
        label=qobject_cast<QLabel*>(vlayout->itemAt(i*2)->widget());
        label->setText(entity->value->getName());
        label=qobject_cast<QLabel*>(vlayout->itemAt(i*2+1)->widget());
        buffer=QString::number(entity->value->getMoney());
        label->setText(buffer+'$');
        setIcon(10,10,entity->value->getIcon(),i+1);
        entity=entity->next;
    }
    for(int i=data->getPlayers().getSize();i<4;i++){
        label=qobject_cast<QLabel*>(vlayout->itemAt(i*2)->widget());
        label->hide();
        label=qobject_cast<QLabel*>(vlayout->itemAt(i*2+1)->widget());
        label->hide();
    }
}

void MainWindow::setIcon(int cellPosX, int cellPosY, QString icon, int playerID)
{
    //Установить фишку игрока на заданную позицию
    QGridLayout*grid=qobject_cast<QGridLayout*>(ui->gridLayout);
    QVBoxLayout*vlayout=qobject_cast<QVBoxLayout*>(grid->itemAtPosition(cellPosX,cellPosY)->layout());
    QHBoxLayout*hlayout=qobject_cast<QHBoxLayout*>(vlayout->itemAt(1)->layout());
    QLabel*label=qobject_cast<QLabel*>(hlayout->itemAt(playerID-1)->widget());
    label->setStyleSheet(icon);
}




