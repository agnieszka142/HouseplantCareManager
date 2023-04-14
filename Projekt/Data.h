#include <iostream>

using namespace std;

#ifndef DATA_H
#define DATA_H

class Data{
public:
    int dzien, mies, rok;
    int dlugosc[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    Data();
    Data(int,int,int);
    void aktualizuj(int,int,int);
    void pokaz();
    Data dodaj(int);
    bool operator==(Data);
};

#endif
