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
    const Guest& guestRef;
    const Room& roomRef;
    string status;

public:
    Reserve(int id, const Guest& guest, const Room& room);
    int getId();
    Guest getGuest();
    Room getRoom();
    string getStatus();
    /*
     * metodos
     */
    void finish();
    void info();
};

#endif
