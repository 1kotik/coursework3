#ifndef ESTATE_H
#define ESTATE_H
#include "cell.h"
#include <iostream>

//Описывает ячейку коммунального предприятия

class Estate:public Cell
{
protected:
    int ownerID;
    int cost;
    std::vector<int> rent;
    bool mortgage;
    int type;
public:
    Estate(int ownerID=0,int cost=0,std::vector<int> rent={},bool mortgage=0,int type=0, QString name="",int posX=0,int posY=0);
    Estate(const Estate& estate);
    Estate& operator=(const Estate&estate);
    ~Estate();
    void setOwner(int ownerID);
    void setCost(int cost);
    void setRent(std::vector<int>  rent);
    void setType(int type);
    void setMortgage(bool value);
    bool isMortgage(); //1, если участок заложен
    int& getType();
    int& getOwnerID();
    int& getCost();
    std::vector<int>& getRent();
    virtual void show() override;
};

#endif // ESTATE_H
