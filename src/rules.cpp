#include "rules.h"
#include "ui_rules.h"
Rules::Rules(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Rules)
{
    ui->setupUi(this);
    setStyleSheet("QMainWindow{border-image:url(:images/rulesbackground.png); stretch}");
    QWidget::setFixedSize(600,350);
}

Rules::~Rules()
{
    delete ui;
}
