#ifndef DRON
#define DRON
#include <unistd.h>
#include "Graniastoslup6.hh"
#include "Interface_drona.hh"
#include "Interface_el_kraj.hh"

#define ROZMIAR_ROTOROW 7,4


/*!
* \brief Modeluje pojecie drona.
*
*   Sklada sie z korpusu i czterech wirnikow 
*/
class Dron : protected UkladW, public Inter_rys, public Inter_drona, public Inter_kraj{
    Prostopadloscian korpus;
    std::array<Graniastoslup6,4> wirniki;
    double _rozpietosc;
public:
    /*!
    *\brief Konstruktor drona
    *
    * Inicjalizuje uklad wspolrzednych, tworzy korpus i 4 wirniki.
    * Na koniec rysuje drona.
    *\param sr wektor srodka 
    *\param ori macierz orientacji drona
    */ 
    Dron(wektor<3> sr, MacierzRot<3> ori) :
    UkladW(sr, ori, nullptr), korpus(wektor<3>{0,0,0}, MacierzRot<3>(0,'z'), this, 20,20,5),
    wirniki({Graniastoslup6(wektor<3>{10,10,2.5}, MacierzRot<3>(), this, ROZMIAR_ROTOROW, "yellow"), 
    Graniastoslup6(wektor<3>{10,-10,2.5}, MacierzRot<3>(), this, ROZMIAR_ROTOROW , "black"),
    Graniastoslup6(wektor<3>{-10,10,2.5}, MacierzRot<3>(), this, ROZMIAR_ROTOROW, "yellow"), 
    Graniastoslup6(wektor<3>{-10,-10,2.5}, MacierzRot<3>(), this, ROZMIAR_ROTOROW, "black")
    }), _rozpietosc(14){rysuj();}

    /*!
    *\brief Zmazuje drona - korpus i 4 wirniki
    */
    ~Dron();

    /*!
    *\brief Obraca wirniki. Dwa w przeciwna strone
    */
    void porusz_wirniki();
    double wielkosc() override;
    void rysuj() override;
    void lec_do_przodu(double odl) override;
    void lec_do_gory(double wys) override;
    void obrot(double kat) override;
    void animacja(double wys, double kat, double odl) override;
    wektor<3> polozenie() override;
    bool czy_ladowac(Inter_drona *D) override;
    bool czy_nad(Inter_drona *D) override;
};



#endif