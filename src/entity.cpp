#include "entity.h"
#include "player.h"
#include "bot.h"
Entity::Entity(int id,int money,Node<Cell*>*pos,int skip, QString icon,QString name)
{
    this->id=id;
    this->money=money;
    this->pos=pos;
    this->skip=skip;
    this->icon=icon;
    this->name=name;
}

Entity::Entity(const Entity &entity)
{
    this->id=entity.id;
    this->money=entity.money;
    this->pos=entity.pos;
    this->skip=entity.skip;
    this->icon=entity.icon;
    this->name=entity.name;
}

Entity::~Entity()
{

}


void Entity::setID(int id)
{
    this->id=id;
}

void Entity::setMoney(int money)
{
    this->money=money;
}

void Entity::setPos(Node<Cell*>*pos)
{
    this->pos=pos;
}

void Entity::setSkip(int skip)
{
    this->skip=skip;
}

void Entity::setIcon(QString icon)
{
    this->icon=icon;
}

void Entity::setName(QString name)
{
    this->name=name;
}

QString&Entity::getIcon()
{
    return icon;
}

QString &Entity::getName()
{
    return name;
}

int &Entity::getSkip()
{
    return skip;
}

int& Entity::getID()
{
    return id;
}

int& Entity::getMoney()
{
    return money;
}

Node<Cell*>* Entity::getPos()
{
    return pos;
}

Entity& Entity::operator=(const Entity& source)
{
    this->id=source.id;
    this->money=source.money;
    this->pos=source.pos;
    this->skip=source.skip;
    this->icon=source.icon;
    this->name=source.name;
    return *this;
}

bool Entity::isEnough(int cost)
{
    //Возвращает 1, если игрок может заплатить указанную цену
    if(money<cost) return 0;
    return 1;
}

bool Entity::mortgage(Cell*cell)
{
    //Залог собственности игроком
    Estate* estate=dynamic_cast<Estate*>(cell);

    if(estate->isMortgage()){
        estate->setMortgage(0);
        this->money-=estate->getCost()*0.55;
        return 0;
    }
    else{
        estate->setMortgage(1);
        this->money+=estate->getCost()/2;
        return 1;
    }
}

bool Entity::buyHouse(Cell *cell)
{
    //Покупка дома игроком
    House*house=dynamic_cast<House*>(cell);

    house->setHouses(house->getHouses()+1);
    this->money-=house->getHouseCost();
    if(house->getHouses()==5) return 1;
    else return 0;
}

bool Entity::sellHouse(Cell *cell)
{
    //Продажа дома игроком
    House*house=dynamic_cast<House*>(cell);

    house->setHouses(house->getHouses()-1);
    this->money+=house->getHouseCost()/2;
    if(house->getHouses()+1==5) return 1;
    else return 0;
}

void Entity::sell(Cell *cell)
{
    //Продажа собственности игроком
    Estate* estate=dynamic_cast<Estate*>(cell);
    estate->setOwner(0);
    money+=estate->getCost()*0.75;
}

void Entity::pay(int rent){
    //Уплатить указанную цену
    money-=rent;
}


