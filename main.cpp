/*
 * Grupo: Oscar Vargas - Juan Diego Collazos
 * Fecha: 5/08/2023
 * main test
 */
#include <iostream>
#include "hotel.h"
#include "guest.h"
#include "room.h"
#include <string>

void test1();
void test2();
void showCommands();

int main(){
    int a;
    std::cout << "type '1' for test 1 and '2' for test 2" << std::endl << "> ";
    std::cin >> a;
    if ( a == 1 ){
        test1();
    } else if ( a == 2 ){
        test2();
    } else {
        std::cout << "?" << std::endl;
    }
}

void test1() {
    Hotel houston("Houston", "Cr 10 N 11-202", "456-123-741");
    Guest jorge("Jorge", "312-741-8523");
    Guest luis("Luis", "312-526-8523");
    Guest maria("Maria", "312-526-1234");
    Guest juan("Juan", "312-741-9856");
    Guest oscar("oscar", "325-895-412");

    houston.reserveRoom(1, jorge);
    houston.reserveRoom(4, maria);
    houston.reserveRoom(7, luis);
    houston.reserveAnyRoom(juan);
    houston.info();
    houston.freeRoom(1);
    houston.freeRoom(4);
    houston.info();
    houston.reserveRoom(1, oscar);
    houston.info();
}

void test2(){
    showCommands();
    int id;
    Guest myGuest;
    Hotel hotel( "Houston", "Near the park", "154616546516" );
    std::string name, phoneNumber, comand;
    std::cin >> comand;
    while ( comand != "exit" ){
        if ( comand == "reserveRoom" ){
            std::cin >> id >> name >> phoneNumber;
            myGuest = Guest( name, phoneNumber );
            hotel.reserveRoom( id, myGuest );
        } else if ( comand == "reserveAnyRoom" ){
            std::cin >> name >> phoneNumber;
            myGuest = Guest( name, phoneNumber );
            hotel.reserveAnyRoom( myGuest );
        } else if ( comand == "freeRoom" ){
            std::cin >> id;
            hotel.freeRoom( id );
        } else if ( comand == "info" ){
            hotel.info();
        } else if ( comand == "help" ){
            showCommands();
        } else {
            std::cout << "The command wasn't understood" << std::endl ;
        }
        std::cin >> comand;
    }
}

void showCommands(){
    std::cout << "Good day\n->_<-\nThe available commands are:\n'exit' | to exit\n";
    std::cout << "'reserveRoom' + roomId + clientName + clientPhone | to reserve a particular room\n";
    std::cout << "'reserveAnyRoom' + clientName + clientPhone | to reserve any room in the hotel\n";
    std::cout << "'info' | to get all the information related to the Hotel\n";
    std::cout << "'help' | to show this again\n";

}