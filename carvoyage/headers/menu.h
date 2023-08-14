#pragma once
#include "main.h"

class menuLogics{
    protected:
        int choice;
        std::string arr[3] = { " Login", " Register", " Exit" };
        std::string renter[5]={" Add Car"," Remove Car", " Edit CarInfo"," Go Back"," Exit"};
        std::string booker[5]= {" Book Car"," Print Receipt"," Return Car"," Go Back"," Exit"};
    public:
    void pauser();
    menuLogics();
    void menu(std::string arr[],int n);
    void choice1();
    void choice2();
    void choice3();
    ~menuLogics();
};