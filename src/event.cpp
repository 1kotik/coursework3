#include "event.h"

Event::Event(int gift,int skip,int chance, QString name,int posX,int posY):Cell(name,posX,posY){
    this->gift=gift;
    this->skip=skip;
    this->chance=chance;
}
Event::Event(const Event& event):Cell(event){
    this->gift=event.gift;
    this->skip=event.skip;
    this->chance=event.chance;
}

Event &Event::operator=(const Event &event)
{
    Event& event_=const_cast<Event&>(event);
    this->setName(event_.getName());
    this->setPosX(event_.getPosX());
    this->setPosY(event_.getPosY());
    this->gift=event.gift;
    this->skip=event.skip;
    this->chance=event.chance;
    return *this;
}
void Event::setGift(int gift){
    this->gift=gift;
}
void Event::setSkip(int skip){
    this->skip=skip;
}
void Event::setChance(int chance){
    this->chance=chance;
}
int& Event::getGift(){
    return gift;
}
int& Event::getSkip(){
    return skip;
}
int& Event::getChance(){
    return chance;
}

void Event::show()
{

}

bool Cell::isEvent()
{
    //Возвращает 1, если ячейка является событийной
    Event* event;
    if(event=dynamic_cast<Event*>(this)) return 1;
    return 0;
}

Event::~Event(){

}
