#ifndef UKLAD_WSP
#define UKLAD_WSP

#include <iostream>
#include "Macierz.hh"
#include <vector>
#include "Dr3D_gnuplot_api.hh"


/*!
*\brief Modeluje uklad wspolrzednych.
*
*   Przyjmuje wektor srodka, macierz rotacji i wskaznik na poprzedni uklad.
*/
class UkladW{
    UkladW * poprzednik;
    wektor<3> srodek;
    MacierzRot<3> orientacja;
public:
    /*!
    *\brief Konstruktor bezparametryczny
    */
    UkladW () : poprzednik(nullptr), srodek(wektor<3>()), orientacja(MacierzRot<3>()) {};

    /*!
    *\brief Konstruktor
    *\param sr wektor srodka ukladu
    *\param ori macierz orientacji ukladu
    *\param poprz wskaznik na poprzedni uklad
    */
    UkladW( wektor<3> sr, MacierzRot<3> ori, UkladW * poprz) : 
    poprzednik(poprz), srodek(sr), orientacja(ori) {}

    /*!
    *\brief Translacja srodka o zadany wektor
    *\param W wektor przesuniecia
    */
    void translacja(const wektor<3> &W) {srodek=srodek+orientacja*W;}

    /*!
    *\brief Obrot orientacji uklady o zadana macierz rotacji
    *\param M macierz rotacji
    */
    void rotacja(const MacierzRot<3> &M) {orientacja=orientacja*M;}

    /*!
    *\brief zwraca wektor punktu w ukladzie poprzednika
    *\param punkt wektor punktu w przestrzeni
    */
    wektor<3> punkt_w_poprzedniku(wektor<3> punkt);

    /*!
    *\brief zwraca uklad lokalny w ukladzie globalnym
    */
    UkladW uklad_w_globalnym();

    /*!
    *\brief getter. Zwraca srodek ukladu lokalnego
    */
    wektor<3> get_srodek() const {return srodek;}

    /*!
    *\brief wyswietla wektor srodka i macierz orientacji ukladu
    */
    void wyswietl();
};








#endif