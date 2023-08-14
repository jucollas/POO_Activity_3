/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 5/08/2023
 * Clase Guest
 */

#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
#include <random>
#include "reserve.h"

using namespace std;

class Payment{
private:
    int amount;
    int nNight; 
    const Reserve& reserve;
public:
    Payment(const Reserve& reserve, int costNight, int nNight);
    int getAmount();
    int getNNight();
    Reserve getReserve();
};

#endif
