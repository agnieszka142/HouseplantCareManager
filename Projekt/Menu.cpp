#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Menu.h"

using namespace std;

template <class Klasa>
Klasa wprowadz_dane(Klasa nowa){
    cout << "Wprowadz informacje o roslinie\n";
    cout << "Nazwa: ";
    cin >> nowa.nazwa;
    cout << "Czestotliwosc podlewania w dniach: ";
    cin >> nowa.podl;
    int dzien,mies,rok;
    nowa.ost_podl = Data();
    while(true){
        cout << "Ostatnio podlane: (format: dd mm rrrr) ";
        cin >> dzien >> mies >> rok;
        if((mies < 13) && (mies > 0) && (dzien <= nowa.ost_podl.dlugosc[mies]) && (dzien > 0) && (rok > 0))
            break;
        cout << "Niepoprawna data!\n";
    }
    nowa.ost_podl.aktualizuj(dzien,mies,rok);
    nowa.nast_podl = nowa.ost_podl.dodaj(nowa.podl);

    return nowa;
}

template <class Klasa>
string dobra_nazwa(vector<Klasa> wektor){
    string nazwa;
    int dobra = 1;
    while(dobra){
        cout << "Podaj nazwe szukanej rosliny lub 0 aby powrocic: ";
        cin >> nazwa;
        if (nazwa == "0")
            return nazwa;

        int l = 0;
        for(auto x : wektor)
        {
            if(x.nazwa == nazwa)
                break;
            l++;
        }
        dobra = 0;
        if (l == wektor.size()){
            cout << "Nie ma rosliny o takiej nazwie!\n";
            dobra = 1;
        }
    }
    return nazwa;
}

template <class Klasa>
vector<Klasa> wczytaj_plik(string nazwa, vector<Klasa> wektor){
    ifstream in(nazwa);
    if(in.good())
    {
        while(true)
        {
            Klasa x = Klasa();
            in >> x;
            x.nast_podl = x.ost_podl.dodaj(x.podl);
            if( in.eof() ) break;
            if(find(wektor.begin(), wektor.end(), x) == wektor.end())
            {
                wektor.push_back(x);
            }
        }
    }
    in.close();
    return wektor;
}

template <class Klasa>
vector<Klasa> usun_z_wektora(string nazwa, vector<Klasa> wektor){
    for(int x = 0; x < wektor.size(); x++)
    {
        if (wektor[x].nazwa == nazwa)
        {
            wektor.erase(wektor.begin()+x);
            break;
        }
    }
    return wektor;
}

template <class Klasa>
void aktualizuj_plik(string nazwa, string nazwa_pliku, Klasa nowa){
    string tmpnazwa = nazwa_pliku + "1";
    nazwa_pliku = nazwa_pliku + ".txt";
    tmpnazwa = tmpnazwa + ".txt";

    ifstream in(nazwa_pliku);
    ofstream ou(tmpnazwa);
    string tmp;
    while (std::getline(in, tmp)){
        if (tmp.find(nazwa) == string::npos){
            ou << tmp << endl;
        }
        else
            ou << nowa;
    }
    in.close();
    ou.close();
    remove(nazwa_pliku.c_str());
    rename(tmpnazwa.c_str(), nazwa_pliku.c_str());
}

Menu::Menu(){
    dzisiaj = Data(0,0,0);
}

void Menu::wczytaj(){
    zielone = wczytaj_plik("zielone.txt", zielone);
    kwitnace = wczytaj_plik("kwitnace.txt", kwitnace);
    sukulenty = wczytaj_plik("sukulenty.txt", sukulenty);
}


void Menu::dodaj(){
    cout << "\nWybierz kategorie\n"
    << "(1) Roslina zielona\n"
    << "(2) Roslina kwitnaca\n"
    << "(3) Sukulent\n"
    << "(0) Wroc\n";
    int w;
    cin >> w;
    switch(w)
    {
    case 0:
        return;
    case 1:
    {
        Zielona nowa = Zielona();
        nowa = wprowadz_dane(nowa);

        if(find(zielone.begin(), zielone.end(), nowa) == zielone.end())
        {
            zielone.push_back(nowa);
            ofstream ou;
            ou.open("zielone.txt", ios_base::app);
            ou << nowa;
            ou.close();
        }
        break;
    }
    case 2:
    {
        Kwitnaca nowa = Kwitnaca();
        nowa = wprowadz_dane(nowa);

        if(find(kwitnace.begin(), kwitnace.end(), nowa) == kwitnace.end())
        {
            kwitnace.push_back(nowa);
            ofstream ou("kwitnace.txt");
            ou << nowa;
            ou.close();
        }
        break;
    }
    case 3:
    {
        Sukulent nowa = Sukulent();
        nowa = wprowadz_dane(nowa);

        if(find(sukulenty.begin(), sukulenty.end(), nowa) == sukulenty.end())
        {
            sukulenty.push_back(nowa);
            ofstream ou("sukulenty.txt");
            ou << nowa;
            ou.close();
        }
        break;
    }
    default:
        cout << "Nie ma takiej kategorii!\n";
        return;
    }
}

void Menu::aktualizuj(){
    cout << "\nWybierz kategorie\n"
    << "(1) Roslina zielona\n"
    << "(2) Roslina kwitnaca\n"
    << "(3) Sukulent\n"
    << "(0) Wroc\n";
    int w;
    cin >> w;
    switch(w)
    {
    case 0:
        return;
    case 1:
    {
        string nazwa;
        nazwa = dobra_nazwa(zielone);
        if (nazwa == "0")
            break;

        Zielona nowa = Zielona();
        nowa = wprowadz_dane(nowa);

        aktualizuj_plik(nazwa, "zielone", nowa);

        zielone = usun_z_wektora(nazwa, zielone);
        zielone.push_back(nowa);

        break;
    }
    case 2:
    {
        string nazwa;
        nazwa = dobra_nazwa(kwitnace);
        if (nazwa == "0")
            break;

        Kwitnaca nowa = Kwitnaca();
        nowa = wprowadz_dane(nowa);

        aktualizuj_plik(nazwa, "kwitnace", nowa);

        kwitnace = usun_z_wektora(nazwa, kwitnace);
        kwitnace.push_back(nowa);

        break;
    }
    case 3:
    {
        string nazwa;
        nazwa = dobra_nazwa(sukulenty);
        if (nazwa == "0")
            break;

        Sukulent nowa = Sukulent();
        nowa = wprowadz_dane(nowa);

        aktualizuj_plik(nazwa, "sukulenty", nowa);

        sukulenty = usun_z_wektora(nazwa, sukulenty);
        sukulenty.push_back(nowa);

        break;
    }
    default:
        cout << "Nie ma takiej kategorii!\n";
        return;
    }
}

void Menu::usun(){
    cout << "\nWybierz kategorie\n"
    << "(1) Roslina zielona\n"
    << "(2) Roslina kwitnaca\n"
    << "(3) Sukulent\n"
    << "(0) Wroc\n";
    int w;
    cin >> w;
    switch(w)
    {
    case 0:
        return;
    case 1:
    {
        string nazwa;
        nazwa = dobra_nazwa(zielone);
        if (nazwa == "0")
            break;

        ifstream in("zielone.txt");
        ofstream ou("zielone1.txt");
        string tmp;
        while (std::getline(in, tmp)){
            if (tmp.find(nazwa) == string::npos){
                ou << tmp << endl;
            }
        }
        in.close();
        ou.close();
        remove("zielone.txt");
        rename("zielone1.txt","zielone.txt");
        zielone = usun_z_wektora(nazwa, zielone);

        break;
    }
    case 2:
    {
        string nazwa;
        nazwa = dobra_nazwa(kwitnace);
        if (nazwa == "0")
            break;

        ifstream in("kwitnace.txt");
        ofstream ou("kwitnace1.txt");
        string tmp;
        while (std::getline(in, tmp)){
            if (tmp.find(nazwa) == string::npos){
                ou << tmp << endl;
            }
        }
        in.close();
        ou.close();
        remove("kwitnace.txt");
        rename("kwitnace1.txt","kwitnace.txt");
        kwitnace = usun_z_wektora(nazwa, kwitnace);

        break;
    }
    case 3:
    {
        string nazwa;
        nazwa = dobra_nazwa(sukulenty);
        if (nazwa == "0")
            break;

        ifstream in("sukulenty.txt");
        ofstream ou("sukulenty1.txt");
        string tmp;
        while (std::getline(in, tmp)){
            if (tmp.find(nazwa) == string::npos){
                ou << tmp << endl;
            }
        }
        in.close();
        ou.close();
        remove("sukulenty.txt");
        rename("sukulenty1.txt","sukulenty.txt");
        sukulenty = usun_z_wektora(nazwa, sukulenty);

        break;
    }
    default:
        cout << "Nie ma takiej kategorii!\n";
        return;
    }
}

void Menu::pokaz(){
    for(auto z : zielone)
        z.pokaz();
    for(auto k : kwitnace)
        k.pokaz();
    for(auto s : sukulenty)
        s.pokaz();
}

void Menu::podlej(){
    if(dzisiaj == Data(0,0,0))
    {
        int dzien,mies,rok;
        while(true){
            cout << "Wprowadz dzisiejsza date: (format: dd mm rrrr) ";
            cin >> dzien >> mies >> rok;
            if((mies < 13) && (mies > 0) && (dzien <= dzisiaj.dlugosc[mies]) && (dzien > 0) && (rok > 0))
                break;
            cout << "Niepoprawna data!\n";
        }
        dzisiaj.aktualizuj(dzien,mies,rok);
    }
    cout << "\nWybierz kategorie\n"
    << "(1) Roslina zielona\n"
    << "(2) Roslina kwitnaca\n"
    << "(3) Sukulent\n"
    << "(0) Wroc\n";
    int w;
    cin >> w;
    switch(w)
    {
    case 0:
        return;
    case 1:
    {
        string nazwa;
        nazwa = dobra_nazwa(zielone);
        if (nazwa == "0")
            break;

        Zielona nowa = Zielona();
        for(Zielona& z : zielone){
            if(z.nazwa == nazwa){
                z.ost_podl = dzisiaj;
                z.nast_podl = z.ost_podl.dodaj(z.podl);
                nowa = z;
                break;
            }
        }

        aktualizuj_plik(nazwa, "zielone", nowa);

        break;
    }
    case 2:
    {
        string nazwa;
        nazwa = dobra_nazwa(kwitnace);
        if (nazwa == "0")
            break;

        Kwitnaca nowa = Kwitnaca();
        for(Kwitnaca& k : kwitnace){
            if(k.nazwa == nazwa){
                k.ost_podl = dzisiaj;
                k.nast_podl = k.ost_podl.dodaj(k.podl);
                nowa = k;
                break;
            }
        }

        aktualizuj_plik(nazwa, "kwitnace", nowa);

        break;
    }
    case 3:
    {
        string nazwa;
        nazwa = dobra_nazwa(sukulenty);
        if (nazwa == "0")
            break;

        Sukulent nowa = Sukulent();
        for(Sukulent& s : sukulenty){
            if(s.nazwa == nazwa){
                s.ost_podl = dzisiaj;
                s.nast_podl = s.ost_podl.dodaj(s.podl);
                nowa = s;
                break;
            }
        }

        aktualizuj_plik(nazwa, "sukulenty", nowa);

        break;
    }
    default:
        cout << "Nie ma takiej kategorii!\n";
        return;
    }

}
