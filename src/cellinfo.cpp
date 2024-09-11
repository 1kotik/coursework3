#include "mainwindow.h"
#include "cellinfo.h"
#include "ui_cellinfo.h"
CellInfo::CellInfo(QWidget *parent,MainWindow* mainWindow) :
    QMainWindow(parent),
    ui(new Ui::CellInfo)
{
    ui->setupUi(this);
    this->mainWindow=mainWindow;
    cell=nullptr;
}

CellInfo::~CellInfo()
{
    delete ui;
}

void CellInfo::startSettings()
{
    //Стартовые настройки интерфейса
    QWidget::setFixedSize(400,475);
    setStyleSheet("QMainWindow{border-image:url(:images/cellinfobackground.png); stretch}");

    ui->buyButton->setStyleSheet("border-image: url(:/images/buy.png) stretch; ");
    ui->houseButton->setStyleSheet("border-image: url(:/images/buy.png) stretch; ");
    ui->mortgageButton->setStyleSheet("border-image: url(:/images/sell.png) stretch; ");
    ui->sellButton->setStyleSheet("border-image: url(:/images/sell.png) stretch; ");
    ui->sellhouseButton->setStyleSheet("border-image: url(:/images/sell.png) stretch; ");

    ui->buyButton->setText("КУПИТЬ УЧАСТОК");
    ui->houseButton->setText("КУПИТЬ ДОМ");
    ui->mortgageButton->setText("ЗАЛОЖИТЬ");
    ui->sellButton->setText("ПРОДАТЬ УЧАСТОК");
    ui->sellhouseButton->setText("ПРОДАТЬ ДОМ");

    ui->buyButton->installEventFilter(this);
    ui->houseButton->installEventFilter(this);
    ui->mortgageButton->installEventFilter(this);
    ui->sellButton->installEventFilter(this);
    ui->sellhouseButton->installEventFilter(this);

    connect(ui->buyButton,&QAbstractButton::clicked,this,&CellInfo::buyPressed);
    connect(ui->mortgageButton,&QAbstractButton::clicked,this,&CellInfo::mortgagePressed);
    connect(ui->houseButton,&QAbstractButton::clicked,this,&CellInfo::housePressed);
    connect(ui->sellhouseButton,&QAbstractButton::clicked,this,&CellInfo::sellHousePressed);
    connect(ui->sellButton,&QAbstractButton::clicked,this,&CellInfo::sellPropertyPressed);
}

bool CellInfo::eventFilter(QObject *object, QEvent *event)
{
    //Обработчик нажатия кнопок
    QAbstractButton*button=qobject_cast<QAbstractButton*>(object);
    if((button==ui->buyButton||button==ui->houseButton)&&event->type()==QEvent::Enter&&button->isEnabled()) button->setStyleSheet("border-image: url(:/images/buyenter.png) stretch; ");
    else if((button==ui->buyButton||button==ui->houseButton)&&event->type()==QEvent::Leave&&button->isEnabled()) button->setStyleSheet("border-image: url(:/images/buy.png) stretch; ");
    else if((button==ui->mortgageButton||button==ui->sellButton||button==ui->sellhouseButton)&&event->type()==QEvent::Enter&&button->isEnabled()) button->setStyleSheet("border-image: url(:/images/sellenter.png) stretch; ");
    else if((button==ui->mortgageButton||button==ui->sellButton||button==ui->sellhouseButton)&&event->type()==QEvent::Leave&&button->isEnabled()) button->setStyleSheet("border-image: url(:/images/sell.png) stretch; ");
    return false;
}

void CellInfo::setButtons()
{
    //Установить настройки для кнопок
    ui->mortgageButton->setDisabled(1);
    ui->buyButton->setDisabled(1);
    ui->houseButton->setDisabled(1);
    ui->sellButton->setDisabled(1);
    ui->sellhouseButton->setDisabled(1);

    setEvent();
    setEstate();
    setHouse();
}

//Следующие 4 метода настраивают интерфейс в соответствии с типом ячейки
void CellInfo::setLabels()
{
    QString buffer=QString::number(123);
    ui->name->setText(cell->getName());
    Node<Entity*>*temp;
    if(cell->isHouse()){
        ui->rentlabel->show();
        ui->rent->show();
        ui->costlabel->show();
        ui->cost->show();
        ui->name->show();
        ui->house1label->show();
        ui->house2label->show();
        ui->house3label->show();
        ui->house4label->show();
        ui->hotellabel->show();
        ui->house1->show();
        ui->house2->show();
        ui->house3->show();
        ui->house4->show();
        ui->hotel->show();
        ui->housecostlabel->show();
        ui->housecost->show();
        ui->mortgage->show();
        ui->mortgagelabel->show();
        ui->buyButton->show();
        ui->houseButton->show();
        ui->mortgageButton->show();
        ui->ownerlabel->show();
        ui->owner->show();
        House*house=dynamic_cast<House*>(cell);
        buffer=QString::number(house->getCost());
        ui->cost->setText(buffer+'$');
        buffer=QString::number(house->getCost()/2);
        ui->mortgage->setText(buffer+'$');
        buffer=QString::number(house->getHouseCost());
        ui->housecost->setText(buffer+'$');
        ui->rentlabel->setText("АРЕНДА");
        ui->house1label->setText("С ОДНИМ ДОМОМ");
        ui->house2label->setText("С ДВУМЯ ДОМАМИ");
        ui->house3label->setText("С ТРЕМЯ ДОМАМИ");
        ui->house4label->setText("С ЧЕТЫРЬМЯ ДОМАМИ");
        ui->hotellabel->setText("С ОДНИМ ОТЕЛЕМ");
        setStyleSheet("QMainWindow{border-image:url(:images/cellinfobackground.png); stretch}");

        buffer=QString::number(house->getRent()[0]);
        ui->rent->setText(buffer+'$');
        buffer=QString::number(house->getRent()[1]);
        ui->house1->setText(buffer+'$');
        buffer=QString::number(house->getRent()[2]);
        ui->house2->setText(buffer+'$');
        buffer=QString::number(house->getRent()[3]);
        ui->house3->setText(buffer+'$');
        buffer=QString::number(house->getRent()[4]);
        ui->house4->setText(buffer+'$');
        buffer=QString::number(house->getRent()[5]);
        ui->hotel->setText(buffer+'$');
        temp=mainWindow->getData()->getByID(house->getOwnerID());
        if(temp&&house->isMortgage()){
            ui->mortgageButton->setText("ВЫКУПИТЬ");
            ui->owner->setText(temp->value->getName()+" (УЧАСТОК ЗАЛОЖЕН)");
        }
        else if(temp){
            ui->mortgageButton->setText("ЗАЛОЖИТЬ");
            ui->owner->setText(temp->value->getName());
        }
        else ui->owner->setText("-");

    }

    else{
        ui->rentlabel->hide();
        ui->rent->hide();
        ui->house1label->hide();
        ui->house2label->hide();
        ui->house3label->hide();
        ui->house4label->hide();
        ui->hotellabel->hide();
        ui->house1->hide();
        ui->house2->hide();
        ui->house3->hide();
        ui->house4->hide();
        ui->hotel->hide();
        ui->housecostlabel->hide();
        ui->housecost->hide();

        if(cell->isEstate()){
            Estate*estate=dynamic_cast<Estate*>(cell);
            buffer=QString::number(estate->getCost());
            ui->mortgage->show();
            ui->mortgagelabel->show();
            ui->costlabel->show();
            ui->cost->show();
            ui->name->show();
            ui->owner->show();
            ui->ownerlabel->show();
            ui->cost->setText(buffer+'$');
            buffer=QString::number(estate->getCost()/2);
            ui->mortgage->setText(buffer+'$');
            temp=mainWindow->getData()->getByID(estate->getOwnerID());

            if(temp&&estate->isMortgage()){
                ui->mortgageButton->setText("ВЫКУПИТЬ");
                ui->owner->setText(temp->value->getName()+" (УЧАСТОК ЗАЛОЖЕН)");
            }
            else if(temp){
                ui->mortgageButton->setText("ЗАЛОЖИТЬ");
                ui->owner->setText(temp->value->getName());
            }
            else ui->owner->setText("-");

            if(estate->getType()==1){
                setStyleSheet("QMainWindow{border-image:url(:images/trainbackground.png); stretch}");
            }

            else{
                setStyleSheet("QMainWindow{border-image:url(:images/supplybackground.png); stretch}");
            }
        }

        else{
            Event*event=dynamic_cast<Event*>(cell);
            ui->mortgage->hide();
            ui->mortgagelabel->hide();
            ui->costlabel->hide();
            ui->cost->hide();
            ui->name->hide();
            ui->owner->hide();
            ui->ownerlabel->hide();
            if(event->getSkip()==1) setStyleSheet("QMainWindow{border-image:url(:images/prisonbackground.png); stretch}");
            else if(event->getChance()==1) setStyleSheet("QMainWindow{border-image:url(:images/chancebackground.png); stretch}");
            else if(event->getGift()>0) setStyleSheet("QMainWindow{border-image:url(:images/startbackground.png); stretch}");
            else if(event->getGift()<0) setStyleSheet("QMainWindow{border-image:url(:images/taxbackground.png); stretch}");
            else setStyleSheet("QMainWindow{border-image:url(:images/relaxbackground.png); stretch}");
        }
    }
}

void CellInfo::setEvent()
{
    if(cell->isEvent()){
        ui->mortgageButton->hide();
        ui->buyButton->hide();
        ui->houseButton->hide();
        ui->sellButton->hide();
        ui->sellhouseButton->hide();
    }
}

void CellInfo::setEstate()
{
    if(!cell->isEstate()) return;

    ui->mortgageButton->show();
    ui->buyButton->show();
    ui->sellButton->show();
    ui->houseButton->hide();
    ui->sellhouseButton->hide();
    Estate* estate=dynamic_cast<Estate*>(cell);

    if(mainWindow->getData()->getCurrent()->value->isPlayer()){

        if(estate->getOwnerID()==0&&mainWindow->getData()->getCurrent()->value->getPos()->value==cell
        &&mainWindow->getData()->getCurrent()->value->isEnough(estate->getCost())) ui->buyButton->setDisabled(0);

        if(estate->getOwnerID()==mainWindow->getData()->getCurrent()->value->getID()){
            if((!estate->isMortgage())
                ||(estate->isMortgage()&&mainWindow->getData()->getCurrent()->value->isEnough(estate->getCost()*0.55))) ui->mortgageButton->setDisabled(0);
            if(!estate->isMortgage()) ui->sellButton->setDisabled(0);
        }
    }
}

void CellInfo::setHouse()
{
    if(!cell->isHouse()) return;

    ui->mortgageButton->show();
    ui->buyButton->show();
    ui->houseButton->show();
    ui->sellButton->show();
    ui->sellhouseButton->show();
    House* house=dynamic_cast<House*>(cell);


    if(mainWindow->getData()->getCurrent()->value->isPlayer()){

        if(house->getOwnerID()==0&&mainWindow->getData()->getCurrent()->value->getPos()->value==cell
            &&mainWindow->getData()->getCurrent()->value->isEnough(house->getCost())) ui->buyButton->setDisabled(0);

        if(house->getOwnerID()==mainWindow->getData()->getCurrent()->value->getID()){
            if((!house->isMortgage())
                ||(house->isMortgage()&&mainWindow->getData()->getCurrent()->value->isEnough(house->getCost()*0.55))) ui->mortgageButton->setDisabled(0);

            if(mainWindow->getData()->isGrouped(mainWindow->getData()->getCurrent()->value->getID(),cell,1)&&!house->isHousesLimit()
                &&mainWindow->getData()->getCurrent()->value->isEnough(house->getHouseCost())) ui->houseButton->setDisabled(0);

            if(mainWindow->getData()->isGrouped(mainWindow->getData()->getCurrent()->value->getID(),cell,0)){
                if(!house->isMortgage()){
                    if(house->getHouses()!=0){
                    ui->sellButton->setDisabled(1);
                    ui->sellhouseButton->setDisabled(0);
                    }
                    else{
                    ui->sellButton->setDisabled(0);
                    ui->sellhouseButton->setDisabled(1);
                    }
                }
            }

        }

    }



}

void CellInfo::open(Node<Cell *> *cell)
{
    //Получение и обработка данных ячейки
    this->cell=cell->value;
    setButtons();
    setLabels();
}

void CellInfo::buyPressed()
{
    //Покупка собственности, обработка покупки, вывод информации на экран
    hide();
    mainWindow->getData()->getCurrent()->value->buy();
    mainWindow->log(mainWindow->getData()->getCurrent()->value->getName()+" купил "+mainWindow->getData()->getCurrent()->value->getPos()->value->getName());
    mainWindow->updateMoney();
}

void CellInfo::housePressed()
{
    //Покупка дома, обработка покупки, вывод информации на экран
    QString status=" купил дом на ";
    hide();
    if(mainWindow->getData()->getCurrent()->value->buyHouse(cell)) status=" купил отель на ";
    mainWindow->log(mainWindow->getData()->getCurrent()->value->getName()+status+mainWindow->getData()->getCurrent()->value->getPos()->value->getName());
    mainWindow->updateMoney();
    mainWindow->updateHouseLabel(cell,0);

}

void CellInfo::mortgagePressed()
{
    //Залог собственности, обработка залога, вывод информации на экран
    QString status=" выкупил ";
    hide();
    if(mainWindow->getData()->getCurrent()->value->mortgage(cell)) status=" заложил ";
    mainWindow->log(mainWindow->getData()->getCurrent()->value->getName()+status+mainWindow->getData()->getCurrent()->value->getPos()->value->getName());
    mainWindow->updateMoney();
}

void CellInfo::sellHousePressed()
{
    //Продажа дома, обработка продажи, вывод информации на экран
    QString status=" продал дом на ";
    hide();
    if(mainWindow->getData()->getCurrent()->value->sellHouse(cell)) status=" продал отель на ";
    mainWindow->log(mainWindow->getData()->getCurrent()->value->getName()+status+mainWindow->getData()->getCurrent()->value->getPos()->value->getName());
    mainWindow->updateMoney();
    mainWindow->updateHouseLabel(cell,0);
}

void CellInfo::sellPropertyPressed()
{
    //Продажа собственности, обработка продажи, вывод информации на экран
    hide();
    mainWindow->getData()->getCurrent()->value->sell(cell);
    mainWindow->log(mainWindow->getData()->getCurrent()->value->getName()+" продал "+mainWindow->getData()->getCurrent()->value->getPos()->value->getName());
    mainWindow->updateMoney();
}
