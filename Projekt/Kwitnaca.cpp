#include <iostream>
#include "Kwitnaca.h"
#include <windows.h>

Kwitnaca::Kwitnaca(){}

void Kwitnaca::pokaz(){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13 );
    cout << "\n******************" << endl << nazwa << endl << "******************" << endl;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );cout << "Ostatnio podlano: ";
    ost_podl.pokaz();
    cout << "Nastepne podlewanie: ";
    nast_podl.pokaz();
    cout << endl;
}
