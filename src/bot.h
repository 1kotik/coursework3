#ifndef BOT_H
#define BOT_H
#include "entity.h"

//Описывает бота (нереального игрока)
class Data;
class Bot:public Entity
{
public:
    Bot(int id=0,int money=0,Node<Cell*>*pos=nullptr,int skip=0, QString icon="",QString name="");
    Bot(const Bot&bot);
    ~Bot();
    void buy() override; //купить собственность с определенным шансом
};

#endif // BOT_H
