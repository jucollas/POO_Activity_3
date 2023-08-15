#include <iostream>
#include <string>
#include "guest.h"
#include "room.h"
#include "payment.h"

#ifndef RESERVE_H
#define RESERVE_H

using namespace std;

class Reserve {
private:
    int id;
    Guest* guestRef;
    Room* roomRef;
    string status;
    Payment* paymentRef;

public:
    Reserve(int id, Guest& guest, Room& room, Payment& payment);
    int getId();
    Guest* getGuest();
    Room* getRoom();
    Payment* getPayment();
    string getStatus();
    /*
     * metodos
     */
    void finish();
    void infoSimple();
    void infoComplete();
};

#endif
