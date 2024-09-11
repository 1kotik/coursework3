#include "trainstation.h"

TrainStation::TrainStation(std::string name,int ownerID,int cost,int rent):Estate(name,ownerID,cost,rent){

}

TrainStation::TrainStation(const TrainStation& trainSt):Estate(trainSt){

}
int TrainStation::getActualRent(){
    return 1;////////////////////
}
TrainStation::~TrainStation(){

}
