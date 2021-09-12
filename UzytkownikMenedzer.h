#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"


using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;


public:
    UzytkownikMenedzer(string nazwaPlikuZuzytkownikami): plikZUzytkownikami(nazwaPlikuZuzytkownikami)
    {
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika=0;
    };


    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku();
    void wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif // UZYTKOWNIKMENEDZER_H
