#ifndef MACIERZ
#define MACIERZ

#include <iostream>
#include <array>
#include <cmath>
#include "Wektor.hh"
#include <algorithm>

#define PI 3.14159265

/*!
*\brief Szablon macierzy rotacji 3-wymiarowej, lub macierzy 2-wymiarowej.
*/
template <int ROZMIAR>
class MacierzRot{
    std::array<wektor<ROZMIAR>, ROZMIAR> tab;
    
public:
    void transpozycja();
    /*!
    *\brief Konstruktor
    *\param kat wartosc katu obrotu (w stopniach). Domyslnie 0.
    *\param os x/y/z os obrotu. Domyslnie z.
    */
    MacierzRot(double kat=0, char os='z');

    /*!
    *\brief Iloczyn macierzy i wektora. Wynikiem jest wektor.
    *\param arg2 wektor mnozony przez macierz
    */
    wektor<ROZMIAR> operator * (const wektor<ROZMIAR> &arg2) const;

    /*!
    *\brief Iloczyn macierzy. Wynikiem jest macierz.
    *\param arg2 macierz prawej strony iloczynu
    */
    MacierzRot<ROZMIAR> operator * (const MacierzRot<ROZMIAR> &arg2) const;
    

    /*!
    *\brief Getter. Zwraca wektor o indeksie
    */
    const wektor<ROZMIAR> & operator [](int ind) const;   
};


/*************************************************************************************************/

template <int ROZMIAR>
MacierzRot<ROZMIAR>::MacierzRot(double kat, char os){
    double rad=kat*PI/180;
    switch(ROZMIAR){
        case 2: 
            tab[0][0]=cos(rad);
            tab[0][1]=-sin(rad);
            tab[1][0]=sin(rad);
            tab[1][1]=cos(rad);
            break;
        case 3:
            switch(os){
                case 'z':
                    tab[0][0]=cos(rad);
                    tab[0][1]=-sin(rad);
                    tab[0][2]=0;
                    tab[1][0]=sin(rad);
                    tab[1][1]=cos(rad);
                    tab[1][2]=0;
                    tab[2][0]=0;
                    tab[2][1]=0;
                    tab[2][2]=1;
                    break;
                case 'y':
                    tab[0][0]=cos(rad);
                    tab[0][1]=0;
                    tab[0][2]=sin(rad);
                    tab[1][0]=0;
                    tab[1][1]=1;
                    tab[1][2]=0;
                    tab[2][0]=-sin(rad);
                    tab[2][1]=0;
                    tab[2][2]=cos(rad);
                    break;
                case 'x':
                    tab[0][0]=1;
                    tab[0][1]=0;
                    tab[0][2]=0;
                    tab[1][0]=0;
                    tab[1][1]=cos(rad);
                    tab[1][2]=-sin(rad);
                    tab[2][0]=0;
                    tab[2][1]=sin(rad);
                    tab[2][2]=cos(rad);
                    break;
                default: std::cerr << "Nieprawidlowa os";
                exit(1);
                break;
            }
            break;

        default: std::cerr << "Nieprawidlowy rozmiar";
        exit(1);
        break;
    }
}

/*************************************************************************************************/

template <int ROZMIAR>
wektor<ROZMIAR> MacierzRot<ROZMIAR>::operator * (const wektor<ROZMIAR> &arg2) const{
    wektor<ROZMIAR> wynik;
    for(int i=0 ; i<ROZMIAR ; i++)
        wynik[i]=tab[i]*arg2;
   
    return wynik;
}

/*************************************************************************************************/

template <int ROZMIAR>
MacierzRot<ROZMIAR> MacierzRot<ROZMIAR>::operator * ( const MacierzRot<ROZMIAR> &arg2) const{
    MacierzRot<ROZMIAR> wynik;
    MacierzRot<ROZMIAR> tmp = arg2;


    tmp.transpozycja();
    
    for(int j=0; j<ROZMIAR ;j++)
        for(int k=0; k<ROZMIAR; k++)
            //wynik[j][k]=tab[j]*tmp[k];
                wynik.tab[j][k]=tab[j]*tmp[k];
    return wynik;
}

/*************************************************************************************************/

template <int ROZMIAR>
const wektor<ROZMIAR> & MacierzRot<ROZMIAR>::operator [](int ind) const {
    if (ind < 0 || ind >ROZMIAR-1){
        std::cerr<< "Blad indeksu wektora!";
        exit(1);
    }    
    return tab[ind];
}   

/*************************************************************************************************/


template <int ROZMIAR>
void MacierzRot<ROZMIAR>::transpozycja(){
    
    for(int i=0;i<ROZMIAR;i++)
        for(int j=i; j<ROZMIAR ; j++)
            std::swap (tab[j][i], tab[i][j]);
}

/*************************************************************************************************/

template <int ROZMIAR>
std::ostream& operator << (std::ostream &strm, const MacierzRot<ROZMIAR> &mac){  //wyswietlenie macierzy obrotu
    for(int i=0 ; i<ROZMIAR ; i++){
        strm << mac[i];
    }
    return strm;
}


#endif