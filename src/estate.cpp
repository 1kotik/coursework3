#include "estate.h"



Estate::Estate(int ownerID, int cost, std::vector<int> rent,bool mortgage,int type, QString name,int posX,int posY):Cell(name,posX,posY)
{
    this->ownerID=ownerID;
    this->cost=cost;
    this->rent=rent;
    this->type=type;
    this->mortgage=mortgage;
}

Estate::Estate(const Estate &estate):Cell(estate)
{
    this->ownerID=estate.ownerID;
    this->cost=estate.cost;
    this->rent=estate.rent;
    this->type=estate.type;
    this->mortgage=estate.mortgage;
}

Estate& Estate::operator=(const Estate& estate)
{
    Estate& estate_=const_cast<Estate&>(estate);
    this->setName(estate_.getName());
    this->setPosX(estate_.getPosX());
    this->setPosY(estate_.getPosY());
    this->ownerID=estate.ownerID;
    this->cost=estate.cost;
    this->rent=estate.rent;
    this->type=estate.type;
    this->mortgage=estate.mortgage;
    return *this;
}

void Estate::setOwner(int ownerID){
    this->ownerID=ownerID;
}
void Estate::setCost(int cost){
    this->cost=cost;
}
void Estate::setRent(std::vector<int> rent){
    this->rent=rent;
}

int& Estate::getOwnerID(){
    return ownerID;
}
int& Estate::getCost(){
    return cost;
}
std::vector<int> & Estate::getRent(){
    return rent;
}
void Estate::setType(int type){
    this->type=type;
}

void Estate::setMortgage(bool value)
{
    mortgage=value;
}

bool Estate::isMortgage()
{
    return mortgage;
}
int&Estate::getType(){
    return type;
}



void Estate::show()
{

}

Estate::~Estate()
{

}

