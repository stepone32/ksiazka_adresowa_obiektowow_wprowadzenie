#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;
    string nazwaTymczasowegoPlikuZAdresatami;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string nowaNazwa, string staraNazwa);

public:
    PlikZAdresatami(string nazwaPliku):PlikTekstowy(nazwaPliku)
    {
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
        idOstatniegoAdresata = 0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresataZPliku();

    bool dopiszAdresataDoPliku(Adresat adresat);
    void edytujWybranegoAdresataWPliku(Adresat edytowanyAdresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);

};

#endif // PLIKZADRESATAMI_H
