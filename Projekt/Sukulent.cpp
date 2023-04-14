#include <iostream>
#include "Sukulent.h"
#include <windows.h>

Sukulent::Sukulent(){}

void Sukulent::pokaz(){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14 );
    cout << "\n******************" << endl << nazwa << endl << "******************" << endl;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );cout << "Ostatnio podlano: ";
    ost_podl.pokaz();
    cout << "Nastepne podlewanie: ";
    nast_podl.pokaz();
    cout << endl;
}
