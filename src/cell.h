#ifndef CELL_H
#define CELL_H
#include <QString>

//Описывает ячейку игрового поля

class Estate;
class House;
class Event;
class Cell
{
protected:
    QString name;
    int posX;
    int posY;
public:
    Cell(QString name="",int posX=0,int posY=0);
    Cell(const Cell& cell);
    ~Cell();
    void setPosX(int posX);
    void setPosY(int posY);
    void setName(QString name);
    bool isEstate(); //возвращает 1, если является общественным предприятием
    bool isHouse();  //возвращает 1, если является событийной ячейкой
    bool isEvent();  //возвращает 1, если является недвижимостью
    int&getPosX();
    int&getPosY();
    QString&getName();
    virtual void show()=0;
};

#endif // CELL_H
