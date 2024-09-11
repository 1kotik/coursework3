#include "house.h"


House::House(int ownerID, int cost, std::vector<int>  rent,bool mortgage, int houses, int group, QString name,int posX,int posY):Estate(ownerID,cost,rent,mortgage,0,name,posX,posY)
{
    this->houses=houses;
    this->group=group;
}

House::House(const House &house):Estate(house)
{
    this->houses=house.houses;
    this->group=house.group;
}

House &House::operator=(const House &house)
{
    House& house_=const_cast<House&>(house);
    this->setName(house_.getName());
    this->setPosX(house_.getPosX());
    this->setPosY(house_.getPosY());
    this->setOwner(house_.getOwnerID());
    this->setCost(house_.getCost());
    this->setRent(house_.getRent());
    this->setType(house_.getType());
    this->setMortgage(house_.isMortgage());
    this->houses=house.houses;
    this->group=house.group;
    return *this;
}

House::~House()
{

}

bool House::isHousesLimit()
{
    //1, если на участке стоит лимит домов
    if(houses==5) return 1;
    return 0;
}

void House::show()
{

}
void House::setHouses(int houses){
    this->houses=houses;
}
void House::setGroup(int group){
    this->group=group;
}
int& House::getHouses(){
    return houses;
}
int& House::getGroup(){
    return group;
}

int House::getHouseCost()
{
    //Возвращает цену дома
    int tempGroup=group;
    if(group%2==1) tempGroup++;
    tempGroup/=2;
    return tempGroup*50;
}

bool Cell::isHouse()
{
    //Возвращает 1, если ячейка является недвижимостью
    House*house;
    if(house=dynamic_cast<House*>(this)) return 1;
    return 0;
}

bool Cell::isEstate()
{
    //Возвращает 1, если ячейка является коммунальным предприятием
    Estate*estate;
    if(!(estate=dynamic_cast<House*>(this))&&(estate=dynamic_cast<Estate*>(this))) return 1;
    return 0;
}
