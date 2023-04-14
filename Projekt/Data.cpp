#include <iostream>
#include "Data.h"

using namespace std;

int przestepny(int rok){
    if ((((rok%4) == 0) && ((rok%100) != 0)) || ((rok%400) == 0))
        return 1;
    return 0;
}

int minelo(Data d){
    int dni = 0;
    if (przestepny(d.rok))
        d.dlugosc[2] = 29;
    int m = 1;
    while (m < d.mies){
        dni += d.dlugosc[m];
        m += 1;
    }
    dni += d.dzien;
    return dni;
}

Data::Data(){
}

Data::Data(int dzien, int mies, int rok){
    this->dzien = dzien;
    this->mies = mies;
    this->rok = rok;
}

bool Data::operator==(Data d){
    if ((this->dzien == d.dzien) && (this->mies == d.mies) && (this->rok == d.rok))
        return true;
    return false;
}

void Data::aktualizuj(int dzien, int mies, int rok){
    this->dzien = dzien;
    this->mies = mies;
    this->rok = rok;
}

void Data::pokaz(){
    cout << dzien << "/" << mies << "/" << rok << endl;
}

Data Data::dodaj(int x){
    Data nowa = Data(0,0,rok);
    x += minelo(Data(dzien,mies,rok));

    int limit;
    if(przestepny(nowa.rok))
        limit = 366;
    else
        limit = 365;
    while((minelo(nowa) + x) > limit){
        x -= (limit - minelo(nowa));
        nowa.rok += 1;
        if(przestepny(nowa.rok + 1))
            limit = 366;
        else
            limit = 365;
    }

    while((nowa.dzien + x) > dlugosc[nowa.mies]){
        x -= dlugosc[nowa.mies];
        if((nowa.mies == 2) && przestepny(nowa.rok))
            x -= 1;
        nowa.mies++;
        if(nowa.mies == 13)
            nowa.mies = 1;
    }
    nowa.dzien += x;

    return nowa;
}
