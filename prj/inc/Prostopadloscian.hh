#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>
#include "Dr3D_gnuplot_api.hh"
#include "Uklad_Wspolrzednych.hh"
#include "Interface_rysowania.hh"
using std::cout;
using std::endl;
using std::setprecision;
using namespace drawNS; 


/*!
*\brief Modeluje prostopadloscian - korpus drona.
*/
class Prostopadloscian : public UkladW, public Inter_rys{
  double wys;
  double szer;
  double gleb;
  int id;
public:
  /*!
  *\brief Konstruktor. Rysuje w gnuplocie prostopadloscian
  *\param sr wektor srodka bryly
  *\param ori macierz orientacji bryly
  *\param poprz wskaznik na uklad, w ktorym bryla jest zdefiniowana
  *\param w dlugosc w OY
  *\param s dlugosc w OX
  *\param g dlugosc w OZ
  */
  Prostopadloscian(wektor<3> sr, MacierzRot<3> ori, UkladW *poprz, double w, double s, double g) :
  UkladW(sr,ori,poprz), wys(s), szer(w), gleb(g), id(-1) { rysuj(); }

  /*!
  *\brief Zmazuje prostopadloscian w gnuplocie
  */
  void zmaz() {rysownik->erase_shape(id);}
  void rysuj() override;
  
  
};

#endif