#include <iostream>
#include "Zielona.h"
#include <windows.h>

Zielona::Zielona(){}

void Zielona::pokaz(){
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10 );
    cout << "\n******************" << endl << nazwa << endl << "******************" << endl;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7 );cout << "Ostatnio podlano: ";
    ost_podl.pokaz();
    cout << "Nastepne podlewanie: ";
    nast_podl.pokaz();
    cout << endl;
}
