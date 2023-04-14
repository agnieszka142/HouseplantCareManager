#include <iostream>
#include "Roslina.h"

using namespace std;

Roslina::Roslina(){}

void Roslina::pokaz(){
    cout << "\n******************" << endl << nazwa << endl << "******************" << endl;
    cout << "Ostatnio podlano: ";
    ost_podl.pokaz();
    cout << "Nastepne podlewanie: ";
    nast_podl.pokaz();
    cout << endl;
}

void Roslina::podlej(int dzien, int mies, int rok){
    ost_podl = Data(dzien, mies, rok);
    nast_podl = ost_podl.dodaj(podl);
}

bool Roslina::operator==(Roslina r){
    if((this->nazwa == r.nazwa) && (this->podl == r.podl))
       return true;
    return false;
}

istream& operator>>(istream& is, Roslina& r)
{
    is >> r.nazwa;
    is >> r.podl;
    is >> r.ost_podl.dzien >> r.ost_podl.mies >> r.ost_podl.rok;

    return is;
}

ostream& operator<<(ostream& os, const Roslina& r)
{
    os << r.nazwa << " ";
    os << r.podl << " ";
    os << r.ost_podl.dzien << " " << r.ost_podl.mies << " " << r.ost_podl.rok << "\n";

    return os;
}


