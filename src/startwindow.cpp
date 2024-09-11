#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    players=1;
    bots=0;
    mainWindow=new MainWindow();
    startSettings();
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::startSettings()
{
    //Начальные настройки стартового окна
    ui->start->installEventFilter(this);
    QWidget::setFixedSize(800,600);
    setStyleSheet("QMainWindow{border-image:url(:images/startwindowbackground.png); stretch}");
    ui->start->setStyleSheet("border-image: url(:/images/continue.png) stretch; ");
    ui->playercount->setStyleSheet("border-image: url(:/images/spinbox.png) stretch; ");
    ui->botcount->setStyleSheet("border-image: url(:/images/spinbox.png) stretch; ");
    ui->name1edit->setStyleSheet("border-image: url(:/images/lineedit.png) stretch; ");
    ui->name2edit->setStyleSheet("border-image: url(:/images/lineedit.png) stretch; ");
    ui->name3edit->setStyleSheet("border-image: url(:/images/lineedit.png) stretch; ");
    ui->name4edit->setStyleSheet("border-image: url(:/images/lineedit.png) stretch; ");
    ui->name2->hide();
    ui->name3->hide();
    ui->name4->hide();
    ui->name2edit->hide();
    ui->name3edit->hide();
    ui->name4edit->hide();
    connect(ui->playercount,&QSpinBox::valueChanged,this,&StartWindow::showLineEdit);
    connect(ui->botcount,&QSpinBox::valueChanged,this,&StartWindow::botSpinBox);
    ui->start->installEventFilter(this);
    ui->start->setDisabled(1);
    connect(this,&StartWindow::sendData,mainWindow,&MainWindow::receiveData);
    connect(ui->start,&QAbstractButton::clicked,this, &StartWindow::emitData);
    connect(ui->start,&QAbstractButton::clicked,this,&QWidget::hide);
    connect(ui->start,&QAbstractButton::clicked,mainWindow,&QWidget::show);
}

bool StartWindow::eventFilter(QObject *object, QEvent *event)
{
    //Обрабатывает вхождение курсора на кнопки
    if(object==ui->start&&event->type()==QEvent::Enter&&ui->start->isEnabled()) ui->start->setStyleSheet("border-image: url(:/images/continueenter.png) stretch; ");
    else if(object==ui->start&&event->type()==QEvent::Leave&&ui->start->isEnabled()) ui->start->setStyleSheet("border-image: url(:/images/continue.png) stretch; ");
    return false;
}

int &StartWindow::getPlayers()
{
    return players;
}

int &StartWindow::getBots()
{
    return bots;
}

QFormLayout *StartWindow::getFormLayout()
{
    return ui->formLayout;
}

void StartWindow::showLineEdit()
{
    //Для интерфейса
    QFormLayout* flayout=qobject_cast<QFormLayout*>(ui->formLayout->layout());
    QLineEdit* lineedit;
    QLabel* label;

    if(bots+ui->playercount->value()>4){
        ui->playercount->setValue(ui->playercount->value()-1);
        return;
    }

    if(players<ui->playercount->value()){
        lineedit=qobject_cast<QLineEdit*>(flayout->itemAt(ui->playercount->value()-1,QFormLayout::FieldRole)->widget());
        label=qobject_cast<QLabel*>(flayout->itemAt(ui->playercount->value()-1,QFormLayout::LabelRole)->widget());
        players++;
        lineedit->show();
        label->show();
    }
    else if(players>ui->playercount->value()){
        players--;
        lineedit=qobject_cast<QLineEdit*>(flayout->itemAt(ui->playercount->value(),QFormLayout::FieldRole)->widget());
        label=qobject_cast<QLabel*>(flayout->itemAt(ui->playercount->value(),QFormLayout::LabelRole)->widget());
        lineedit->hide();
        label->hide();
    }

    if(players+bots<2&&ui->start->isEnabled()) ui->start->setDisabled(1);
    else if(players+bots>=2&&!ui->start->isEnabled()) ui->start->setDisabled(0);
}

void StartWindow::botSpinBox()
{
    //Для интерфейса
    if(players+ui->botcount->value()>4){
        ui->botcount->setValue(ui->botcount->value()-1);
    }
    else if(bots>ui->botcount->value()) bots--;
    else if(bots<ui->botcount->value()) bots++;

    if(players+bots<2&&ui->start->isEnabled()) ui->start->setDisabled(1);
    else if(players+bots>=2&&!ui->start->isEnabled()) ui->start->setDisabled(0);

}

void StartWindow::emitData()
{
    //Передать данные главному окну
    std::vector<QString> names;
    QFormLayout* flayout=getFormLayout();
    QLineEdit* lineedit;

    for(int i=0;i<players;i++){
        lineedit=qobject_cast<QLineEdit*>(flayout->itemAt(i,QFormLayout::FieldRole)->widget());
        names.push_back(lineedit->text());
    }

    emit sendData(players,bots,names);
}
