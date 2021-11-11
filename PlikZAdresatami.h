#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZAdresatami
{
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami):NAZWA_PLIKU_Z_ADRESATAMI (nazwaPlikuZAdresatami)
    {
        nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
        idOstatniegoAdresata = 0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresataZPliku();

    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string nowaNazwa, string staraNazwa);
    bool dopiszAdresataDoPliku(Adresat adresat);
    void edytujWybranegoAdresataWPliku(Adresat edytowanyAdresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);
};

#endif // PLIKZADRESATAMI_H
