#ifndef HOUSE_H
#define HOUSE_H
#include "estate.h"

//Описывает ячейку недвижимости

class House:public Estate
{
private:
    int houses;
    int group;
public:
    House(int ownerID=0,int cost=0,std::vector<int> rent={},bool mortgage=0,int houses=0,int group=0, QString name="",int posX=0,int posY=0);
    House(const House& house);
    House& operator=(const House&house);
    void setHouses(int houses);
    void setGroup(int group);
    int& getHouses();
    int& getGroup();
    int getHouseCost();
    ~House();
    bool isHousesLimit(); //1, если на участке построено максимальное количество домов
    virtual void show() override;
};

#endif // HOUSE_H
