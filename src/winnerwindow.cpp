#include "winnerwindow.h"
#include "ui_winnerwindow.h"

WinnerWindow::WinnerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WinnerWindow)
{
    ui->setupUi(this);
    QWidget::setFixedSize(400,300);
    setStyleSheet("QMainWindow{border-image:url(:images/winnerbackground.png); stretch}");
    ui->endButton->setStyleSheet("border-image: url(:/images/end.png) stretch; ");
    ui->endButton->installEventFilter(this);
    connect(ui->endButton, &QAbstractButton::clicked,this,&WinnerWindow::endProgram);
}

WinnerWindow::~WinnerWindow()
{
    delete ui;
}

bool WinnerWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object==ui->endButton&&event->type()==QEvent::Enter) ui->endButton->setStyleSheet("border-image: url(:/images/endenter.png) stretch; ");
    else if(object==ui->endButton&&event->type()==QEvent::Leave) ui->endButton->setStyleSheet("border-image: url(:/images/end.png) stretch; ");
    return false;
}

void WinnerWindow::endProgram()
{
    qApp->exit();
}

QLabel* WinnerWindow::getWinnerLabel()
{
    return ui->winnername;
}


