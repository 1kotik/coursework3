#ifndef EVENT_H
#define EVENT_H
#include "cell.h"

//Описывает событийную ячейку

class Event:public Cell
{
protected:
    int gift;
    int skip;
    int chance;
public:
    Event(int gift=0,int skip=0,int chance=0, QString name="",int posX=0,int posY=0);
    Event(const Event& event);
    Event& operator=(const Event&event);
    void setGift(int gift);
    void setSkip(int skip);
    void setChance(int chance);
    int& getGift();
    int& getSkip();
    int& getChance();
    virtual void show() override;
    ~Event();
};

#endif // EVENT_H
