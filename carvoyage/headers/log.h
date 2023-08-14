#pragma once
#include "main.h"

class logindata{
    protected:
    std::string name,password,role;
};
class save:public logindata{
    public:
    virtual void saving() = 0;
    virtual void print() = 0;
};

class log:public save{
    public:
    void login();
    void regis();
    bool validaotr();
    void saving();
    void print();
};