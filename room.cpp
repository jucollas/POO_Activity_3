/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 5/08/2023
 * room.cpp
 */

#include "room.h"

Room::Room(const int& id, const int& cost){
    this->id = id;
    this->available = true;
    this->cost = cost;
    //this->guest = Guest();
}


bool Room::reserve( Guest &guest){
    bool ans = false;
    if (guest.getCash() >= this->getCost() && this->isAvailable()){
        ans = true;
        this->available = false;
    }
    return ans;
}

int Room::getCost(){
    return this->cost;
}

int Room::getId(){
    return this->id;
}

bool Room::isAvailable(){
    return this->available;
}

bool Room::freeRoom(){
    this->available = true;
    //this->guest = Guest();
    return available;
}

void Room::info(){
    cout << "==================================="<< endl;
    cout << "==================================="<< endl;
    cout << "- Room: 00" << this->getId() << endl;
    cout << "Cost: " << this->getCost() << endl;
    cout << "State: ";
    if(this->isAvailable())
        cout << "Available" << endl;
    else
        cout << "Occupied" << endl;
    //this->guest.info();
}
