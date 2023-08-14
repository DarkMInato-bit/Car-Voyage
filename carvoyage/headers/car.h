#pragma once
#include "main.h"

class car:public logindata{

    protected:
    std::string name,password,role;
    int carrent;
    std::string car_brand,car_model,car_numberp;
    int car_rent;
    std::ifstream read;
    std::ofstream write;
    public:
    void save();
    void show_car();
    void show();
};

class car_manage:public car{
    public:
    void add();
    void removee();
    void edit();
};