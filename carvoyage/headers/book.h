#pragma once
#include "main.h"
class customer:public car{
    protected:
    std::string name,password,role;
    std::string username=name;
    public:
    void print();
    void bookcar();
    void returncar();
    void show_car();
};