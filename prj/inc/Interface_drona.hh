#ifndef INTER_DRONA
#define INTER_DRONA

#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
using namespace drawNS; 


/*!
*\brief Interfejs drona.
*
*   Modeluje interfejs do lotu, obrotu i animacji drona
*/
class Inter_drona{
public:
    /*!
    *\brief Powoduje lot drona do przodu
    *\param odl - Wartosc dlugosci lotu
    */
    virtual void lec_do_przodu(double odl) = 0;

    /*!
    *\brief Podowuje lot drona do gory
    *\param wys - Wysokosc lotu
    */
    virtual void lec_do_gory(double wys) = 0;

    /*!
    *\brief Powoduje obrot drona. 
    *\param kat - Kat obrotu w stopniach. >0 obrot w lewo, <0 obrot w prawo
    */
    virtual void obrot(double kat) =0;

    /*!
    *\brief Animacja lotu - lot pionowy, obrot, lot poziomy
    *\param wys - wysokosc lotu
    *\param kat - kat obrotu w stopniach
    *\param odl - dlugosc lotu
    */
    virtual void animacja(double wys, double kat, double odl)=0;

    /*!
    *\brief Zwraca wektor polozenia srodka drona
    */
    virtual wektor<3> polozenie()=0;

    /*!
    *\brief Zwraca promien drona
    */
    virtual double wielkosc()=0;

   


};




#endif