#include "reserve.h"

Reserve::Reserve(int id, const Guest& guest, const Room& room)
        : id(id), guestRef(guest), roomRef(room), status("Enabled") {
        // ...
    }

int Reserve::getId(){
    return this->id;
};

Guest Reserve::getGuest(){
    return guestRef;
}

Room Reserve::getRoom(){
    return roomRef;
}
string Reserve::getStatus(){
    return this->status;
}

void Reserve::finish(){
    this->status = "Disabled";
}
void info();