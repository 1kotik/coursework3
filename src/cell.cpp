#include "cell.h"
#include "house.h"
#include "event.h"
#include <iostream>
Cell::Cell(QString name,int posX,int posY)
{
    this->name=name;
    this->posX=posX;
    this->posY=posY;
}

Cell::Cell(const Cell &cell)
{
    this->name=cell.name;
    this->posX=cell.posX;
    this->posY=cell.posY;
}

Cell::~Cell()
{

}

void Cell::setPosX(int posX)
{
    this->posX=posX;
}

void Cell::setPosY(int posY)
{
    this->posY=posY;
}

void Cell::setName(QString name){
    this->name=name;
}



int& Cell::getPosX()
{
    return posX;
}

int& Cell::getPosY()
{
    return posY;
}

QString& Cell::getName(){
    return name;
}



