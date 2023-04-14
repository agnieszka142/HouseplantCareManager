#include <iostream>
#include <vector>
#include "Zielona.h"
#include "Kwitnaca.h"
#include "Sukulent.h"

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu{
public:
    Data dzisiaj;
    vector <Zielona> zielone;
    vector <Kwitnaca> kwitnace;
    vector <Sukulent> sukulenty;
    Menu();
    void wczytaj();
    void dodaj();
    void aktualizuj();
    void usun();
    void pokaz();
    void podlej();
};

#endif
