#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QTabBar>
#include "data.h"
#include "cellinfo.h"
#include <QLineEdit>
#include <QDateTime>
#include <QtGlobal>
#include <QRandomGenerator>
#include <QTimer>
#include <windows.h>
#include <QThread>
#include <QAbstractButton>
#include "rules.h"
#include "winnerwindow.h"

//Описывает главное окно

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class CellInfo;
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    CellInfo* cellInfo;
    Rules* rules;
    WinnerWindow* winnerWindow;
    Data* data;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Data* getData();
    void connections();  //соединяет сигналы, кнопки, слоты
    void startSettings(); //стартовые настройки окна
    void setIcon(int cellPosX,int cellPosY,QString icon,int playerID); //установить модель игрока на заданную ячейку
    bool eventFilter(QObject* object,QEvent*event); //обработчик вхождения курсора на кнопки
    void roll(); //бросок костей
    void botCycle(); //цикл игры ботов
    void log(QString info); //вывести информацию на экран
    void updateMoney(); //обновить информаию о капитале
    void updateHouseLabel(Cell*cell=nullptr,int id=0); //обновить информацию о домах, построенных на игровом поле
    void startCheck();  //обработчик вхождения игрока на поле Старт
    void prisonCheck(); //обработчик вхождения игрока на поле Тюрьма
    void rentCheck();   //вычисление аренды
    bool eventCheck();  //обработчик вхождения игрока на событийную ячейку
    void callChance();  //обработчик вхождения игрока на поле Шанс
    void timer(int duration); //установить таймер
    QAbstractButton* getButtonAt(int x,int y); //возвращает кнопку по заданной позиции
    bool endgame(); //завершить игру, если остался 1 игрок

signals:
    void openCellInfo(Node<Cell*>*cell);

public slots:
    void receiveData(int players,int bots,std::vector<QString> names); //принять данные

//Обработчик нажатия кнопок
private slots:
    void press(Node<Cell*>*cell);
    void rollPressed();
    void rerollPressed();
    void finishPressed();
    void forfeitPressed();

};

#endif // MAINWINDOW_H
