#include "bot.h"


Bot::Bot(int id,int money,Node<Cell*>*pos,int skip, QString icon,QString name):Entity(id,money,pos,skip,icon,name)
{

}

Bot::Bot(const Bot &bot):Entity(bot)
{

}

Bot::~Bot()
{

}


void Bot::buy(){
    //Покупка собственности с шансом 50%
    int chance=rand()%2;
    if(chance==1){
        Estate* estate=dynamic_cast<Estate*>(getPos()->value);
        if(isEnough(estate->getCost())&&estate->getOwnerID()==0){
        estate->setOwner(id);
        money-=estate->getCost();
        }
    }
}

