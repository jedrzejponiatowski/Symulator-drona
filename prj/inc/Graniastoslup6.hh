#ifndef ROTORY
#define ROTORY

#include "Prostopadloscian.hh"
#include <iostream>
#include <vector>


/*!
*\brief Graniastoslup 6-katny foremny. Imitacja wirnika.
*/
class Graniastoslup6: public UkladW, public Inter_rys{
    double r;
    double h;
    int id;
    std::string kolor;
public:
    /*!
    *\brief Konstruktor. Tworzy uklad graniastoslup z wlasnym ukladem wspolrzednych
    *\param sr wektor srodka
    *\param ori macierz orientacji ukladu wsp
    *\param poprz wskaznik na poprzedni uklad
    *\param pro promien figury (do wierzcholka)
    *\param wys wysokosc figury
    *\param _kolor kolor figury
    */
    Graniastoslup6(wektor<3> sr, MacierzRot<3> ori, UkladW *poprz, double pro, double wys, std::string _kolor) :
    UkladW(sr,ori,poprz), r(pro), h(wys), id(-1), kolor(_kolor) {}
    
    /*!
    *\brief Usuwa figure w gnuplocie
    */
    void zmaz() {rysownik->erase_shape(id);}
    void rysuj() override;
};















#endif