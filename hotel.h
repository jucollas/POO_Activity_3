/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 3/08/2023
 * Clase Hotel
 */


#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include "room.h"
#include "guest.h"
#include "reserve.h"
//#include "test.cpp"

#define NRooms 10

using namespace std;

class Hotel{
private:
    string name;
    string address;
    string telephoneNumber;
    int availableRooms;
    vector<Room> rooms;
    vector<Reserve> reserves;
public:
    Hotel( const string &name, const string &address, const string &telephoneNumber );

    /*
     * setters y getters
     */
    string getName();
    string getAddress();
    string getTelephoneNumber();
    int getAvailableRooms();

    /*
     * metodos
     */
    bool reserveRoom( int roomId, Guest &client );
    bool reserveAnyRoom( Guest &client );
    bool freeRoom( int roomId );
    void viewAllReserve();
    void info();

};

#endif