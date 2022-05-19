#ifndef PLASKO
#define PLASKO

#include "Dron.hh"
#include <random>
#include <stdlib.h>
#include <time.h>
#include "Interface_el_kraj.hh"
#include "Interface_rysowania.hh"
#include <cmath>

/*!
*\brief Klasa przeszkody - plaskowyzu randomizowanego.
*/
class Plaskowyz: public UkladW, public Inter_rys, public Inter_kraj {
private:
    double h;
    std::vector< wektor<3> > w_dolne;
    int id;
  
public:
    /*!
    *\brief Konstruktor. Rysuje przeszkode w gnuplocie.
    *
    * Dlugosc odcinkow srodek-wierzcholek jest losowana z przedzialu min-max.
    * Ilosc bokow jest losowana z przedzialu 3-9.
    * \param sr wektor srodka przeszkody
    * \param wys wysokosc przeszkody w OZ
    * \param min minimalna odleglosc srodek-wierzcholek
    * \param max maksymalna odleglosc srodek-wierzcholek
    */
    Plaskowyz(wektor<3> sr, int wys, int min, int max);

    /*!
    *\brief Destruktor. Zmazuje przeszkode w gnuplocie
    */
    ~Plaskowyz() {rysownik->erase_shape(id);}
  
    
    void rysuj() override;
    
    virtual bool czy_ladowac(Inter_drona * D) override;
    virtual bool czy_nad(Inter_drona * D) override;
    virtual wektor<3> polozenie() override;

};




#endif