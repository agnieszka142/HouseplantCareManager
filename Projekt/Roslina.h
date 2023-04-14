#include <iostream>
#include "Data.h"

using namespace std;

#ifndef ROSLINA_H
#define ROSLINA_H

class Roslina{
public:
    string nazwa;
    int podl;
    Data ost_podl;
    Data nast_podl;

    Roslina();
    void podlej(int,int,int);
    virtual void pokaz();
    bool operator==(Roslina);
    friend istream& operator>>(istream& is, Roslina& r);
    friend ostream& operator<<(ostream& os, const Roslina& r);
};

#endif

