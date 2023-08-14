#include <iostream>
#include <string>
#include "guest.h"
#include "room.h"

#ifndef RESERVE_H
#define RESERVE_H

using namespace std;

class Reserve {
private:
    int id;
    Guest* guestRef;
    Room* roomRef;
    string status;

public:
    Reserve(int id, Guest& guest, Room& room);
    int getId();
    Guest* getGuest();
    Room* getRoom();
    string getStatus();
    /*
     * metodos
     */
    void finish();
    void info();
};

#endif
