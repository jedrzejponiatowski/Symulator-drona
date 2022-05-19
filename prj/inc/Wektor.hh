#ifndef WEKTOR
#define WEKTOR

#include <iostream>
#include <array>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"

/*!
*\brief Szablon wektoru n-elementowego
*/
template <int ROZMIAR>
class wektor{
    std::array<double, ROZMIAR> tab;
    inline static int _ile_jest=0;
    inline static int _ile_stworzono=0;
public:
    /*!
    *\brief Konstruktor bezparametryczny. Domysle wartosci - 0.
    */
    wektor();

    /*!
    *\brief Konstruktor. Inicjalizuje wartosci
    *\param arg lista inicjalizacyjna, jej wartosci tworza wektor
    */
    wektor(const std::initializer_list<double> &arg);

    /*!
    *\brief Konstruktor kopiujacy. 
    *\param w wektor, ktorego pola beda kopiowane
    */
    wektor(const wektor<ROZMIAR> & w);

    /*!
    *\brief Destruktor. Zmniejsza liczbe aktualnie istniejacych wektorow
    */
    ~wektor() {_ile_jest--;}

    /*!
    *\brief Dodawanie dwoch wektorow
    *\param arg2 drugi argument sumy
    */
    wektor<ROZMIAR> operator + (const wektor<ROZMIAR> & arg2) const;

    /*!
    *\brief Odejmowanie dwoch wektorow. 
    *\param arg2 drugi argument roznicy
    */
    wektor<ROZMIAR> operator - (const wektor<ROZMIAR> & arg2) const;

    /*!
    *\brief Mnozenie wektora przez skalar. Wynikiem jest wektor.
    */
    wektor<ROZMIAR> operator * (const double arg2) const;

    /*!
    *\brief Iloczyn skalarny dwoch wektorow
    */
    double operator * (const wektor<ROZMIAR> & arg2) const;

    /*!
    *\brief Porownanie dwoch wektorow
    */
    bool operator == (const wektor<ROZMIAR> & arg2) const;

    /*!
    *\brief Zwraca dlugosc wektora
    */
    double dlugosc() const;

    /*!
    *\brief Getter. Zwraca skladnik wektora o zadanym indeksie
    *\param ind indeks elementu wektora
    */
    const double & operator[](int ind) const;

    /*!
    *\brief Setter. Ustawia wartosc na danym indeksie
    *\param ind indeks elementu wektora
    */
    double & operator [](int ind);
  
    /*!
    *\brief Zwraca liczbe aktualnej liczby wektorow
    */
    static int ile_jest() {return _ile_jest;}

    /*!
    *\brief Zwraca liczbe stworzonych wektorow
    */
    static int ile_stworzono() {return _ile_stworzono;}

};



/*************************************************************************************************/

template <int ROZMIAR>
wektor<ROZMIAR>::wektor(){
    for(double &wsp_i : tab) wsp_i=0;
    _ile_jest++; _ile_stworzono++; 
}


template <int ROZMIAR>
wektor<ROZMIAR>::wektor(const std::initializer_list<double> &arg){
    int ind = -1;
    for(double wsp_i : arg) tab[++ind] = wsp_i;
    _ile_jest++; _ile_stworzono++; 
}

template <int ROZMIAR>
wektor<ROZMIAR>::wektor(const wektor<ROZMIAR> & w){
     int ind = -1;
    for(double wsp_i : w.tab) tab[++ind] = wsp_i;
    _ile_jest++; _ile_stworzono++; 
}

/*************************************************************************************************/

template <int ROZMIAR>
wektor<ROZMIAR> wektor<ROZMIAR>::operator + (const wektor<ROZMIAR> & arg2) const{
    wektor<ROZMIAR> wynik;
    for(int i=0 ; i<ROZMIAR ; i++){
        wynik[i]=tab[i]+arg2[i];
    }
    return wynik;
}

/*************************************************************************************************/

template <int ROZMIAR>
wektor<ROZMIAR> wektor<ROZMIAR>::operator - (const wektor<ROZMIAR> & arg2) const{
    wektor<ROZMIAR> wynik;
    for(int i=0 ; i<ROZMIAR ; i++){
        wynik[i]=tab[i]-arg2[i];
    }
    return wynik;
}    

/*************************************************************************************************/

template <int ROZMIAR>
wektor<ROZMIAR> wektor<ROZMIAR>::operator * (const double arg2) const{
    wektor<ROZMIAR> wynik;
    for(int i=0 ; i<ROZMIAR ; i++){
        wynik[i]=tab[i]*arg2;
    }
    return wynik;
}

/*************************************************************************************************/

template <int ROZMIAR>
double wektor<ROZMIAR>::operator * (const wektor<ROZMIAR> & arg2) const{
    double wynik=0;
    for(int i=0 ; i<ROZMIAR ; i++){
        wynik+= tab[i]*arg2[i];
    }
    return wynik;
}

/*************************************************************************************************/

template <int ROZMIAR>
const double & wektor<ROZMIAR>::operator[](int ind) const{
    if(ind<0 || ind > ROZMIAR-1){
        std::cerr << "Blad indeksu" << std::endl;
        exit(0);
    }
    return tab[ind];
}

/*************************************************************************************************/

template <int ROZMIAR>
double & wektor<ROZMIAR>::operator [](int ind){
    if(ind<0 || ind > ROZMIAR-1){
        std::cerr << "Blad indeksu" << std::endl;
        exit(0);
    }
    return tab[ind];
}

/*************************************************************************************************/

template <int ROZMIAR>
double wektor<ROZMIAR>::dlugosc() const{
    double wynik=0;
    for(int i=0 ; i<ROZMIAR ; i++){
        wynik+=pow(tab[i],2);
    }
    return sqrt(wynik);
}

/*************************************************************************************************/

template <int ROZMIAR>
std::ostream & operator << (std::ostream &strm, const wektor<ROZMIAR> &arg2) {
    strm.precision(3);
    strm << std::fixed;
    for (int i=0; i<ROZMIAR; i++){
        strm << arg2[i] << "    ";
    }
    strm << std::endl;
    return strm;
}


/*************************************************************************************************/

template <int ROZMIAR>
std::istream & operator >> (std::istream & strm, wektor<ROZMIAR> & L){
  char znak;
  double _x, _y, _z;
    strm >> znak;
    if (znak != '[' ) {
     strm.setstate(std::ios::failbit);
     return strm;
    }
    strm >> _x;
    L[0]=_x;
    strm >> znak;
    if (znak != ',' ) {
     strm.setstate(std::ios::failbit);  
     return strm;}
    strm >> _y;
    L[1]=_y;
    strm >> znak;
    if (znak != ',' ) {
     strm.setstate(std::ios::failbit);  
     return strm;}
    strm >> _z;
    L[2]=_z; 
    strm >> znak; 
    if (znak != ']' ) {
     strm.setstate(std::ios::failbit);  
     return strm;
    }
  
    return strm;
}

template <int ROZMIAR>
drawNS::Point3D konw_do_P3D(wektor<ROZMIAR> wek){
    return drawNS::Point3D(wek[0], wek[1], wek[2]);
}

template <int ROZMIAR>
bool wektor<ROZMIAR>::operator == (const wektor<ROZMIAR> & arg2) const{
    for(int i=0; i<ROZMIAR; i++){
        if(tab[i]!=arg2[i])
        return false;
    }
    return true;
}

#endif