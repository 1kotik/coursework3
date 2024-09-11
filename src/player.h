#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"

//Описывает реального игрока
class Player:public Entity
{
public:
    Player(int id=0,int money=0,Node<Cell*>*pos=nullptr,int skip=0,QString icon="",QString name="");
    Player(const Player& player);
    ~Player();
    void buy() override; //купить собственность
};

#endif // PLAYER_H
