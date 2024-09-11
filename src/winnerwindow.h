#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class WinnerWindow;
}

class WinnerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WinnerWindow(QWidget *parent = nullptr);
    ~WinnerWindow();
    bool eventFilter(QObject* object,QEvent*event);
    void endProgram();
    QLabel* getWinnerLabel();


private:
    Ui::WinnerWindow *ui;
};

#endif // WINNERWINDOW_H
