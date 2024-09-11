#ifndef TRAINSTATION_H
#define TRAINSTATION_H
#include "estate.h"

class TrainStation:public Estate
{
public:
    TrainStation(std::string name,int ownerID,int cost,int rent);
    TrainStation(const TrainStation& trainSt);
    int getActualRent() override;
    ~TrainStation();
};

#endif // TRAINSTATION_H
