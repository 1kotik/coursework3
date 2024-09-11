#pragma once
#ifndef CELLINFO_H
#define CELLINFO_H
template<typename T> struct Node;
class Cell;
class MainWindow;
#include <QMainWindow>
namespace Ui {
class CellInfo;
}

//Описывает информационное окно

class CellInfo : public QMainWindow
{
    Q_OBJECT
private:
    MainWindow* mainWindow;
    Ui::CellInfo *ui;
    Cell* cell;
public:
    explicit CellInfo(QWidget *parent = nullptr,MainWindow* mainWindow=nullptr);
    ~CellInfo();
    void startSettings(); //Стартовые настройки
    bool eventFilter(QObject* object,QEvent*event); //обработчик вхождения курсора на кнопки
    void setButtons(); //настраивает кнопки
    void setLabels();  //настраивает текстовые метки
    void setEvent();   //настраивает текстовые метки и кнопки в соответствии с событийной ячейкой
    void setEstate();  //настраивает текстовые метки и кнопки в соответствии с ячейкой коммунального предприятия
    void setHouse();   //настраивает текстовые метки и кнопки в соответствии с ячейкой недвижимости
signals:
public slots:
    void open(Node<Cell*>*cell); //принимает сигнал

//Обработчики нажатия кнопок
private slots:
    void buyPressed();
    void housePressed();
    void mortgagePressed();
    void sellHousePressed();
    void sellPropertyPressed();
};



#endif // CELLINFO_H
