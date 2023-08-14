/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 3/08/2023
 * hotel.cpp
 */

#include "hotel.h"

Hotel::Hotel(const string &name, const string &address, const string &telephoneNumber ){
    this->name = name;
    this->address = address;
    this->telephoneNumber = telephoneNumber;
    this->availableRooms = NRooms;
    this->reserves = {};
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(100, 500);
    for ( int index = 0 ; index < NRooms ; ++index  ){
        (this->rooms).push_back(Room(index,dist(mt)));
    }
}

string Hotel::getName(){
    return this->name;
}
string Hotel::getAddress(){
    return this->address;
}
string Hotel::getTelephoneNumber(){
    return this->telephoneNumber;
}
int Hotel::getAvailableRooms(){
    return this->availableRooms;
}

bool Hotel::reserveRoom(int roomId, Guest &client, int nNights){
    bool ans = false;
    if(rooms[roomId].reserve(client, nNights)){
        reserves.push_back(Reserve( reserves.size() + 1, client, rooms[roomId]));
        Payment payment(reserves[reserves.size() - 1], rooms[roomId].getCost(), nNights);
        client.pay(rooms[roomId].getCost());
        --availableRooms;
    }else
        cout << "It is NOT possible to reserve the room" << endl;
    return ans;
}

bool Hotel::reserveAnyRoom(Guest& client, int nNights ){
    int index = 0;
    bool reserved = false;
    if(this->getAvailableRooms() != 0){
        while (!reserved && index < (this->rooms).size() ) {
            if(rooms[index].reserve(client, nNights)){
                reserves.push_back(Reserve( reserves.size() + 1, client, rooms[index]));
                Payment payment(reserves[reserves.size() - 1], rooms[index].getCost(), nNights);
                client.pay(rooms[index].getCost());
                --availableRooms;
                reserved = true;
            }
            ++index;
        }
    }else
        cout << "It is NOT possible to reserve any room" << endl;
    return reserved;
}

bool Hotel::freeRoom(int roomId ){
    return (this->rooms)[roomId].freeRoom();
}

void Hotel::info(){
    cout << "Hotel information" << endl;
    cout << "-----------------------------------"<< endl;
    cout << "Name: " << this->getName() << endl;
    cout << "Address: " << this->getAddress() << endl;
    cout << "Telephone number: " << this->getTelephoneNumber() << endl;
    cout << "(Rooms available: " << this->getAvailableRooms() << " ) " << endl;
    cout << "************************************"<< endl;
    cout << "Available Rooms :"<< endl;
    for(int index = 0; index < this->rooms.size(); ++index){
        if((this->rooms)[index].isAvailable())
            (this->rooms)[index].info();
    }
    cout << "************************************"<< endl;
    cout << "Occupied Rooms :"<< endl;
    for(int index = 0; index < this->rooms.size(); ++index){
        if(!(this->rooms)[index].isAvailable())
            (this->rooms)[index].info();
    }
}

