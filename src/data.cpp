#include "data.h"


Data::Data(int players,int bots,std::vector<QString> names)
{
    seed=QTime::currentTime().msec();
    setImages();

    std::vector<QString> icons={"border-image: url(:/images/player1icon.png) stretch; ","border-image: url(:/images/player2icon.png) stretch; ",
                                "border-image: url(:/images/player3icon.png) stretch; ","border-image: url(:/images/player4icon.png) stretch; "
    };

    int id = 1;
    Player player;
    Bot bot;
    Estate estate;
    Event event;
    House house;
    QString botname="БОТ";

    event={200,0,0,"",10,10};          //start
    field.push(new Event (event));
    field_buffer.push(new Event(event));


    Node<Cell*>* first=field.getFirst();

    for(int i=0;i<players;i++){
        player={id,1000,first,0,icons[i],names[i]};
        this->players.push(new Player (player));
        players_buffer.push(new Player(player));
        id++;
    }

    for (int i = 0; i <bots; i++) {
        bot = {id,1000,first,0,icons[players+i],botname+QString::number(i+1) };
        this->players.push(new Bot (bot));
        players_buffer.push(new Bot(bot));
        id++;
    }

    current=this->players.getFirst();

    house={0,60,{2,10,30,90,160,250},0,0,1,"ЖИТНАЯ УЛ.",10,9};      //житная
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,1,"ШАНС",10,8};                   //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,60,{4,20,60,180,320,450},0,0,1,"НАГАТИНСКАЯ УЛ.",10,7};      //нагатинская
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={-200,0,0,"ПОДОХОДНЫЙ НАЛОГ",10,6};         //подоходный налог
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    estate={0,200,{25,50,100,200},0,1,"РИЖСКАЯ Ж/Д",10,5};      //жд1
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    house={0,100,{6,30,90,270,400,550},0,0,2,"ВАРШАВСКОЕ ШОССЕ",10,4};     //варшавское шоссе
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,1,"ШАНС",10,3};            //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,100,{6,30,90,270,400,550},0,0,2,"УЛ. ОГАРЕВА",10,2};     //огарева
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,120,{8,40,100,300,450,600},0,0,2,"ПЕРВАЯ ПАРКОВАЯ УЛ.",10,1};     //первая парковая
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,1,0,"ТЮРЬМА",10,0};            //тюрьма
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,140,{10,50,150,450,625,750},0,0,3,"УЛ. ПОЛЯНКА",9,0};     //полянка
    field.push(new House (house));
    field_buffer.push(new House(house));
    estate={0,150,{4,10},0,2,"ЭЛЕКТРОСТАНЦИЯ",8,0};      //электроэнергия
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    house={0,140,{10,50,150,450,625,750},0,0,3,"УЛ. СРЕТЕНКА",7,0};     //сретенка
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,160,{12,60,180,500,700,900},0,0,3,"РОСТОВСКАЯ НАБЕРЕЖНАЯ",6,0};     //ростовкая набережная
    field.push(new House (house));
    field_buffer.push(new House(house));
    estate={0,200,{25,50,100,200},0,1,"КУРСКАЯ Ж/Д",5,0};      //жд2
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    house={0,180,{14,70,200,550,750,950},0,0,4,"РЯЗАНСКИЙ ПРОСПЕКТ",4,0};     //рязанский проспект
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,1,"ШАНС",3,0};            //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,180,{14,70,200,550,750,950},0,0,4,"УЛ. ВАВИЛОВА",2,0};     //вавилова
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,200,{16,80,220,600,800,1000},0,0,4,"РУБЛЕВСКОЕ ШОССЕ",1,0};     //рублевское шоссе
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,0,"ОТДЫХ",0,0};            //бесплатная парковка
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,220,{18,90,250,700,875,1050},0,0,5,"УЛ. ТВЕРСКАЯ",0,1};     //тверская
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,1,"ШАНС",0,2};            //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,220,{18,90,250,700,875,1050},0,0,5,"ПУШКИНСКАЯ УЛ.",0,3};     //пушкинская
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,240,{20,100,300,750,925,1100},0,0,5,"ПЛОЩАДЬ МАЯКОВСКОГО",0,4};     //площадь маяковского
    field.push(new House (house));
    field_buffer.push(new House(house));
    estate={0,200,{25,50,100,200},0,1,"КАЗАНСКАЯ Ж/Д",0,5};      //жд3
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    house={0,260,{22,110,330,800,975,1150},0,0,6,"УЛ. ГРУЗИНСКИЙ ВАЛ",0,6};     //грузинский вал
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,260,{22,110,330,800,975,1150},0,0,6,"УЛ. ЧАЙКОВСКОГО",0,7};     //чайковского
    field.push(new House (house));
    field_buffer.push(new House(house));
    estate={0,150,{4,10},0,2,"ВОДОПРОВОД",0,8};      //водопровод
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    house={0,280,{24,120,360,850,1025,1200},0,0,6,"СМОЛЕНСКАЯ ПЛОЩАДЬ",0,9};     //смоленская площадь
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,1,0,"ТЮРЬМА",0,10};            //тюрьма
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,300,{26,130,390,900,1100,1275},0,0,7,"УЛ. ЩУСЕВА",1,10};     //щусева
    field.push(new House (house));
    field_buffer.push(new House(house));
    house={0,300,{26,130,390,900,1100,1275},0,0,7,"ГОГОЛЕВСКИЙ БУЛЬВАР",2,10};     //гоголевский бульвар
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={0,0,1,"ШАНС",3,10};            //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,320,{28,150,450,1000,1200,1400},0,0,7,"КУТУЗОВСКИЙ ПРОСПЕКТ",4,10};     //кутузовский проспект
    field.push(new House (house));
    field_buffer.push(new House(house));
    estate={0,200,{25,50,100,200},0,1,"ЛЕНИНГРАДСКАЯ Ж/Д",5,10};      //жд4
    field.push(new Estate (estate));
    field_buffer.push(new Estate (estate));
    event={0,0,1,"ШАНС",6,10};            //шанс
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,350,{35,175,500,1100,1300,1500},0,0,8,"УЛ. МАЛАЯ БРОННАЯ",7,10};     //малая бронная
    field.push(new House (house));
    field_buffer.push(new House(house));
    event={-100,0,0,"СВЕРХНАЛОГ",8,10};         //сверхналог
    field.push(new Event (event));
    field_buffer.push(new Event(event));
    house={0,400,{50,200,600,1400,1700,2000},0,0,8,"УЛ. АРБАТ",9,10};     //арбат
    field.push(new House (house));
    field_buffer.push(new House(house));


}

Data::Data(const Data &data)
{
    this->players=data.players;
    this->field=data.field;
    this->current=data.current;
}

Data::~Data()
{

}
void Data::setNextCurrent()
{
    //Определение следующего игрока, пропуск хода, если игрок в тюрьме
    current=current->next;
    for(;current->value->getSkip()==1;current=current->next){
        if(current->value->getSkip()==1) current->value->setSkip(0);
    }
}
void Data::setImages()
{
    //Картинки
    images={
        {"border-image: url(:/images/start.png) stretch; ","border-image: url(:/images/startenter.png) stretch; "},
        {"border-image: url(:/images/brown1.png) stretch; ","border-image: url(:/images/brown1enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/brown2.png) stretch; ","border-image: url(:/images/brown2enter.png) stretch; "},
        {"border-image: url(:/images/tax1.png) stretch; ","border-image: url(:/images/tax1enter.png) stretch; "},
        {"border-image: url(:/images/train1.png) stretch; ","border-image: url(:/images/train1enter.png) stretch; "},
        {"border-image: url(:/images/blue1.png) stretch; ","border-image: url(:/images/blue1enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/blue2.png) stretch; ","border-image: url(:/images/blue2enter.png) stretch; "},
        {"border-image: url(:/images/blue3.png) stretch; ","border-image: url(:/images/blue3enter.png) stretch; "},
        {"border-image: url(:/images/prison.png) stretch; ","border-image: url(:/images/prisonenter.png) stretch; "},
        {"border-image: url(:/images/pink1.png) stretch; ","border-image: url(:/images/pink1enter.png) stretch; "},
        {"border-image: url(:/images/electricity.png) stretch; ","border-image: url(:/images/electricityenter.png) stretch; "},
        {"border-image: url(:/images/pink2.png) stretch; ","border-image: url(:/images/pink2enter.png) stretch; "},
        {"border-image: url(:/images/pink3.png) stretch; ","border-image: url(:/images/pink3enter.png) stretch; "},
        {"border-image: url(:/images/train2.png) stretch; ","border-image: url(:/images/train2enter.png) stretch; "},
        {"border-image: url(:/images/orange1.png) stretch; ","border-image: url(:/images/orange1enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/orange2.png) stretch; ","border-image: url(:/images/orange2enter.png) stretch; "},
        {"border-image: url(:/images/orange3.png) stretch; ","border-image: url(:/images/orange3enter.png) stretch; "},
        {"border-image: url(:/images/parking.png) stretch; ","border-image: url(:/images/parkingenter.png) stretch; "},
        {"border-image: url(:/images/red1.png) stretch; ","border-image: url(:/images/red1enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/red2.png) stretch; ","border-image: url(:/images/red2enter.png) stretch; "},
        {"border-image: url(:/images/red3.png) stretch; ","border-image: url(:/images/red3enter.png) stretch; "},
        {"border-image: url(:/images/train3.png) stretch; ","border-image: url(:/images/train3enter.png) stretch; "},
        {"border-image: url(:/images/yellow1.png) stretch; ","border-image: url(:/images/yellow1enter.png) stretch; "},
        {"border-image: url(:/images/yellow2.png) stretch; ","border-image: url(:/images/yellow2enter.png) stretch; "},
        {"border-image: url(:/images/watersupply.png) stretch; ","border-image: url(:/images/watersupplyenter.png) stretch; "},
        {"border-image: url(:/images/yellow3.png) stretch; ","border-image: url(:/images/yellow3enter.png) stretch; "},
        {"border-image: url(:/images/gotoprison.png) stretch; ","border-image: url(:/images/gotoprisonenter.png) stretch; "},
        {"border-image: url(:/images/green1.png) stretch; ","border-image: url(:/images/green1enter.png) stretch; "},
        {"border-image: url(:/images/green2.png) stretch; ","border-image: url(:/images/green2enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/green3.png) stretch; ","border-image: url(:/images/green3enter.png) stretch; "},
        {"border-image: url(:/images/train4.png) stretch; ","border-image: url(:/images/train4enter.png) stretch; "},
        {"border-image: url(:/images/chance.png) stretch; ","border-image: url(:/images/chanceenter.png) stretch; "},
        {"border-image: url(:/images/darkblue1.png) stretch; ","border-image: url(:/images/darkblue1enter.png) stretch; "},
        {"border-image: url(:/images/tax2.png) stretch; ","border-image: url(:/images/tax2enter.png) stretch; "},
        {"border-image: url(:/images/darkblue2.png) stretch; ","border-image: url(:/images/darkblue2enter.png) stretch; "},
        {"border-image: url(:/images/roll.png) stretch; ","border-image: url(:/images/rollenter.png) stretch; "},
        {"border-image: url(:/images/finish.png) stretch; ","border-image: url(:/images/finishenter.png) stretch; "},
        {"border-image: url(:/images/reroll.png) stretch; ","border-image: url(:/images/rerollenter.png) stretch; "},
        {"border-image: url(:/images/about.png) stretch; ","border-image: url(:/images/aboutenter.png) stretch; "},
        {"border-image: url(:/images/forfeit.png) stretch; ","border-image: url(:/images/forfeitenter.png) stretch; "}
    };
}


void Data::setSeed(int seed)
{
    this->seed=seed;
}

void Data::saveBuffer()
{
    //Сохранить данные о поле и игроках в буфер
    copyField(field_buffer,field);
    copyPlayers(players_buffer,players);
}

void Data::loadBuffer()
{
    //Выгрузить данные о поле и игроках из буфера
    copyField(field,field_buffer);
    copyPlayers(players,players_buffer);
}

void Data::copyCells(Cell *dest, Cell *source)
{
    //Копирование данных из одной ячейки в другую
    if(dest->isEstate()){
        Estate& dest_={*dynamic_cast<Estate*>(dest)};
        const Estate& source_={*dynamic_cast<Estate*>(source)};
        dest_=source_;
    }
    if(dest->isHouse()){
        House& dest_={*dynamic_cast<House*>(dest)};
        const House& source_={*dynamic_cast<House*>(source)};
        dest_=source_;
    }
    if(dest->isEvent()){
        Event& dest_={*dynamic_cast<Event*>(dest)};
        const Event& source_={*dynamic_cast<Event*>(source)};
        dest_=source_;
    }
}

void Data::copyField(Ring<Cell *>& destination, Ring<Cell*>& source)
{
    //Копирование игрового поля
    Node<Cell*>*source_cell=source.getFirst();
    Node<Cell*>*dest_cell=destination.getFirst();
    for(int i=0;i<source.getSize();i++,source_cell=source_cell->next,dest_cell=dest_cell->next){
        copyCells(dest_cell->value,source_cell->value);
    }
}

void Data::copyPlayers(Ring<Entity *>& destination, Ring<Entity *>& source)
{
    //Копирование игроков
    Node<Entity*>* source_player=source.getFirst();
    Node<Entity*>* dest_player=destination.getFirst();
    for(int i=0;i<source.getSize();i++,source_player=source_player->next,dest_player=dest_player->next){
        *dest_player->value=*source_player->value;
        copyCells(dest_player->value->getPos()->value,source_player->value->getPos()->value);
    }
}

int &Data::getSeed()
{
    return seed;
}

std::vector<std::vector<QString> > &Data::getImages()
{
    return images;
}

void Data::setCurrent(Node<Entity *> *current)
{
    this->current=current;
}


Node<Entity *> *Data::getCurrent()
{
    return current;
}

Node<Entity *>* Data::getByID(int id)
{
    //Возвращает участника по заданному ID
    Node<Entity*>* temp=players.getFirst();

    do{
        if(temp->value->getID()==id) return temp;
        temp=temp->next;
    }while(temp!=players.getFirst());

    return nullptr;
}

void Data::updateAfterForfeit(int id)
{
    //Обновить данные после того, как участник сдался
    //Т.е. продать всю его собственность
    Node<Cell*>*temp=field.getFirst()->next;
    Estate* estate;
    House* house;
    for(;temp!=field.getFirst();temp=temp->next){
        if(temp->value->isEstate()||temp->value->isHouse()){
            estate=dynamic_cast<Estate*>(temp->value);
            if(estate->getOwnerID()==id){
                estate->setOwner(0);
                estate->setMortgage(0);
            }
        }
        if(temp->value->isHouse()){
            house=dynamic_cast<House*>(temp->value);
            if(house->getOwnerID()==id){
                house->setHouses(0);
            }
        }
    }
}

Ring<Entity *> &Data::getPlayers()
{
    return players;
}

Ring<Entity *> &Data::getPlayersBuffer()
{
    return players_buffer;
}

Ring<Cell *> &Data::getField()
{
    return field;
}

bool Data::isGrouped(int id,Cell*cell,int actionStatus)
{
    //Возвращает 1, если вся заданная группа принадлежит заданному игроку
    //Статус 0: Игрок хочет продать дом на участке
    //Статус 1: Игрок хочет купить дом на участке
    //Статус 2: Другой игрок платит аренду
    House*house=dynamic_cast<House*>(cell);
    Node<Cell*>*temp=field.getFirst()->next;
    int counter=0;
    int group=house->getGroup();
    int houseQuantity=house->getHouses();
    int ownerID=house->getOwnerID();
    for(;temp!=field.getFirst();temp=temp->next){
        if(temp->value->isHouse()){
            house=dynamic_cast<House*>(temp->value);
            if(house->getGroup()!=group) continue;
            else{
                if(actionStatus==1&&house->getOwnerID()==id&&houseQuantity<=house->getHouses()) counter++; //игрок покупает дом на данном участке
                else if(actionStatus==0&&houseQuantity>=house->getHouses()) counter++; //игрок хочет продает дом на данном участке
                else if(actionStatus==2&&ownerID!=0&&ownerID!=id&&ownerID==house->getOwnerID()) counter++; //2- игрок платит аренду
            }
        }
    }

    if((group==1||group==8)&&counter==2) return 1;
    if(counter==3) return 1;
    return 0;
}

int Data::getActualRent()
{
    //Вычисление аренды на участке по правилам монополии
    srand(seed);
    int roll=2+rand()%11;
    int counter=0;
    Node<Cell*>* temp=field.getFirst()->next;
    int ownerID=0;
    if(current->value->getPos()->value->isEstate()){
        Estate*estate=dynamic_cast<Estate*>(current->value->getPos()->value);
        ownerID=estate->getOwnerID();
        if(estate->getOwnerID()==0||estate->getOwnerID()==current->value->getID()) return 0;
        if(estate->getType()==1){ //trainSt
            for(;temp!=field.getFirst();temp=temp->next){
                if(temp->value->isEstate()){
                    estate=dynamic_cast<Estate*>(temp->value);
                    if((estate->getOwnerID()==ownerID)&&(estate->getType()==1)) counter++;
                }
            }
            if(counter==3) return 100;
            if(counter==4) return 200;
            else return counter*25;
        }

        else{ //service
            for(;temp!=field.getFirst();temp=temp->next){
                if(temp->value->isEstate()){
                    estate=dynamic_cast<Estate*>(temp->value);
                    if((estate->getOwnerID()==ownerID)&&(estate->getType()==2)) counter++;
                }
            }
            if(counter==1) return roll*4;
            else if(counter==2) return roll*10;
            else return 0;
        }
    }

    else if(current->value->getPos()->value->isHouse()){
        House* house=dynamic_cast<House*>(current->value->getPos()->value);
        if(isGrouped(current->value->getID(),current->value->getPos()->value,2)){
            if(house->getHouses()==0) return house->getRent()[0]*2;
            else return house->getRent()[house->getHouses()];
        }
        else{
            if(house->getOwnerID()!=0&&house->getOwnerID()!=current->value->getID()) return house->getRent()[0];
            else return 0;
        }
    }
    return 0;
}



bool Data::isFree(Entity *player)
{
    //Возвращает 1, если участок свободен или принадлежит игроку
    Estate*estate=dynamic_cast<Estate*>(player->getPos()->value);
    if(estate->getOwnerID()!=player->getID()&&estate->getOwnerID()!=0) return 0;
    return 1;
}


Node<Cell *>* Data::getCellByPos(int posX, int posY)
{
    //Возвращает ячейку по ее позиции
    Node<Cell*>*temp=field.getFirst();

    for(;;temp=temp->next){
        if(temp->value->getPosX()==posX&&temp->value->getPosY()==posY) return temp;
    }
}



