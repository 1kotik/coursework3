#ifndef ENTITY_H
#define ENTITY_H


#include <iostream>
#include "ring.h"
#include <QString>
#include "house.h"
#include "event.h"

//Описывает участника игры

class Entity
{
protected:
    int id;
    int money;        //current money
    Node<Cell*>* pos; //position on the map
    int skip;
    QString icon;
    QString name;
public:
    Entity(int id,int money,Node<Cell*>* pos,int skip, QString icon,QString name);
    Entity(const Entity&entity);
    Entity& operator=(const Entity&source);
    ~Entity();
    void setID(int id);
    void setMoney(int money);
    void setPos(Node<Cell*>*pos);
    void setSkip(int skip);
    void setIcon(QString icon);
    void setName(QString name);
    QString& getIcon();
    QString& getName();
    int& getSkip();
    int& getID();
    int& getMoney();
    Node<Cell*>* getPos();
    bool isEnough(int cost);  //возращает 1, если игрок может заплатить указанную цену
    bool mortgage(Cell*cell); //заложить участок
    bool buyHouse(Cell*cell); //купить дом
    bool sellHouse(Cell*cell); //продать дом
    void sell(Cell*cell);      //продать участок
    virtual void buy()=0;      //купить участок
    void pay(int rent);        //заплатить указанную цену
    bool isPlayer();           //возвращает 1, если участник является реальным игроком
};

#endif // ENTITY_H
