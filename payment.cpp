#include "payment.h"

Payment::Payment(const Reserve& reserve, int costNight, int nNight): reserve(reserve),nNight(nNight), amount(nNight * costNight){

};

int Payment::getAmount(){
    return amount;
}

int Payment::getNNight(){
    return nNight;
}

Reserve Payment::getReserve(){
    return reserve;
}