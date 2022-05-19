#ifndef SCENA
#define SCENA

#include "Dron.hh"
#include "Plaskowyz.hh"
#include "Plasko_Pro.hh"
#include "Wzgorze.hh"
#include "Interface_rysowania.hh"
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;

/*!
*\brief Modeluje pojecie sceny. Zarzadzanie dronami i przeszkodami.
*
*   Umozliwia animacje drona, dodawanie i usuwanie przeszkod i dronow. Zmiana aktualnego drona. 
*   Wyswietlenie wspolrzednych.
*/
class Scena{
private:
    vector<shared_ptr<Inter_drona> > drony;
    vector<shared_ptr<Inter_kraj> > elem_kraj;
    vector<shared_ptr<Inter_rys> > elem_rys;
    Inter_drona * aktualny;
public:
    /*!
    *\brief Konstruktor. Tworzy i rysuje drona i trzy przeszkody.
    */
    Scena();
    
    /*!
    *\brief Animacja lotu drona.
    *\param wys wartosc/dlugosc lotu pionowego drona 
    *\param kat kat obrotu w stopniach. >0 obrot w lewo, <0 obrot w prawo
    *\param odl wartosc/dlugosc lotu poziomego drona
    */
    void animuj(double wys, double kat, double odl);

    /*!
    *\brief Rysuje wszystkie przeszkody z kolekcji. 
    *
    * Wczesniej ich nie zmazuje -> nadrysowuje juz istniejace.
    */
    void rysuj_wszystko();

    /*!
    *\brief Dodaje i rysuje nowe przeszkody - wzgorze, plaskowyz, plaskowyz prostopadloscienny
    */
    void dodaj_przeszkode();

    /*!
    *\brief Dodaje do kolekcji i rysuje nowego drona
    */
    void dodaj_drona();

    /*!
    *\brief Usuwa przeszkode z kolekcji. Zmazuje ja.
    *\param id numer przeszkody w kolekcji
    */
    void usun_przeszkode(uint id);

    /*!
    *\brief Wyswietla wspolrzedne srodkow przeszkod
    */
    void wyswietl_przeszkody();

    /*!
    *\brief Wyswietla wspolrzedne srodkow dronow
    */
    void pokaz_drony();

    /*!
    *\brief Usuwa z kolekcji i zmazuje istniejacego drona
    *\param id numer drona w kolekcji
    */
    void usun_drona(uint id);

    /*!
    *\brief Umozliwia wybor aktualnego drona
    *\param id numer drona w kolekcji, ktory ma stac sie aktualnym
    */
    void wybierz_drona(uint id);
    
    void sprawdz_kolizje();
};















#endif