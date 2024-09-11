#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include "mainwindow.h"
namespace Ui {
class StartWindow;
}
//Описывает стартовое окно
class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();
    void startSettings(); //Начальные настройки интерфейса
    bool eventFilter(QObject* object,QEvent*event); //Обработчик вхождение курсора на кнопки
    int& getPlayers();
    int& getBots();
    QFormLayout* getFormLayout();
private:
    Ui::StartWindow *ui;
    MainWindow* mainWindow;
    int players;
    int bots;
private slots:
    void showLineEdit(); //для корректной работы
    void botSpinBox();   //для корректной работы
    void emitData();     //передает данные главному окну
signals:
    void sendData(int players,int bots,std::vector<QString> names); //передает данные главному окну
};

#endif // STARTWINDOW_H
