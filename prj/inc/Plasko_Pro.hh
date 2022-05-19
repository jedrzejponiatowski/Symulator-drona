#ifndef PLASKO_PRO
#define PLASKO_PRO

#include "Interface_el_kraj.hh"
#include "Prostopadloscian.hh"
#include <cmath>

/*!
*\brief Klasa przeszkody, plaskowyzu prostopadlosciennego (prostopadloscian)
*/
class Plaskowyz_Pro: public Prostopadloscian ,  public Inter_kraj {
    wektor<3> _rozpietosc;
    int idp;
public:
    /*!
    *\brief Konstruktor. Tworzy prostopadloscian w ukladzie wspolrzednych
    *\param sr wektor srodka przeszkody
    *\param rot macierz orientacji przeszkody
    *\param wys rozmiar w OY
    *\param szer rozmiar w OX
    *\param gleb rozmiar w OZ
    */
    Plaskowyz_Pro (wektor<3> sr, MacierzRot<3> rot, double wys, double szer, double gleb) :
    Prostopadloscian(sr, rot, nullptr, wys, szer, gleb), 
    _rozpietosc(wektor<3>{wys/2,szer/2,gleb/2}) {}

    /*!
    *\brief Destruktor. Zmazuje przeszkode w gnuplocie.
    */
    ~Plaskowyz_Pro () {zmaz();}

    /*!
    *\brief Getter. Zwraca polezenie srodka przeszkody. Potrzebne do sprawdzenia kolizji.
    */
    virtual wektor<3> polozenie() override; 
    virtual bool czy_ladowac(Inter_drona *D) override;
    virtual bool czy_nad(Inter_drona *D) override;
    

};





#endif