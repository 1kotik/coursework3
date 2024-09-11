#include "player.h"


Player::Player(int id,int money,Node<Cell*>*pos,int skip, QString icon,QString name):Entity(id,money,pos,skip,icon,name)
{

}

Player::Player(const Player &player):Entity(player)
{

}

Player::~Player()
{

}

void Player::buy()
{
    //Купить собственность
    Estate* estate=dynamic_cast<Estate*>(getPos()->value);
    estate->setOwner(id);
    money-=estate->getCost();
}

bool Entity::isPlayer()
{
    //Возвращает 1, если данный участник - реальный игрок
    Player* player;
    if(player=dynamic_cast<Player*>(this)) return 1;
    return 0;
}
