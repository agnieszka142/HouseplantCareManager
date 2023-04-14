#include <iostream>
#include <fstream>
#include "Roslina.h"
#include "Menu.h"

using namespace std;

int main()
{
    cout << "Witaj!\n";
    Menu uprawa = Menu();
    int w = 1;
    while(w)
    {
        cout << "Co chcesz zrobic? (Wprowadz odpowiednia cyfre)\n"
        << "(1) Wczytaj baze\n"
        << "(2) Dodaj nowa rosline\n"
        << "(3) Wyswietl kolekcje\n"
        << "(4) Aktualizuj informacje\n"
        << "(5) Usun rosline\n"
        << "(6) Podlej rosline\n"
        << "(0) Zakoncz\n\n";
        cin >> w;
        switch(w)
        {
        case 0:
            break;
        case 1:
            uprawa.wczytaj();
            uprawa.pokaz();
            break;
        case 2:
            uprawa.dodaj();
            break;
        case 3:
            uprawa.pokaz();
            break;
        case 4:
            uprawa.aktualizuj();
            break;
        case 5:
            uprawa.usun();
            break;
        case 6:
            uprawa.podlej();
            break;
        default:
            cout << "Taka opcja nie istnieje!\n";
            break;
        }
    }
}
