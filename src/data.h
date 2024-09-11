#ifndef DATA_H
#define DATA_H
#include "event.h"
#include "house.h"
#include "bot.h"
#include "player.h"
#include "ring.h"
#include <iostream>
#include <vector>
#include <QDebug>
#include <QTime>

//Описывает интерфейс

class Data
{
private:
    Ring<Cell*> field;
    Ring<Entity*> players;
    Node<Entity*>*current;
    std::vector<std::vector<QString>> images;
    std::vector<Point> points;
    int seed;
    Ring<Cell*> field_buffer;
    Ring<Entity*> players_buffer;
public:
    Data();
    Data(int players,int bots,std::vector<QString> names);
    Data(const Data& data);
    ~Data();
    void setImages();  //для картинок
    void setSeed(int seed);
    void saveBuffer(); //сохранить данные в буфер
    void loadBuffer(); //выгрузить данные из буфера
    void copyCells(Cell* dest,Cell*source); //копировать данные одной ячейки в другую
    int& getSeed();
    std::vector<std::vector<QString>>& getImages();
    Ring<Entity*>& getPlayers();
    Ring<Entity*>& getPlayersBuffer();
    Ring<Cell*>& getField();
    void setNextCurrent(); //установить текущего игрока
    bool isGrouped(int id,Cell*cell,int actionStatus); //Проверяется полнота цветовой группы
    int getActualRent(); //вычисление аренды
    void copyField(Ring<Cell*>& destination, Ring<Cell*>& source); //копирование игрового поля
    void copyPlayers(Ring<Entity*>& destination, Ring<Entity*>& source); //копирование игроков
    bool isFree(Entity*player); //возвращает 1, если ячейка свободна для данного игрока
    void setCurrent(Node<Entity*>*current);
    Node<Entity*>* getCurrent();
    Node<Entity*>* getByID(int id);
    void updateAfterForfeit(int id); //обновить поле после поражения участника
    Node<Cell*>* getCellByPos(int posX,int posY); //вернуть ячейку по ее позиции

};

#endif // DATA_H
