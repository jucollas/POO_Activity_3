/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 5/08/2023
 * Clase Guest
 */
#include <string>
#include <iostream>
#include <random>

#ifndef PAYMENT_H
#define PAYMENT_H

using namespace std;

class Payment{
private:
    int amount;
    int nNight;
public:
    Payment(int costNight, int nNight);
    int getAmount();
    int getNNight();
};

#endif
