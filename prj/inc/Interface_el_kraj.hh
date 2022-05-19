#ifndef INTER_KRAJ
#define INTER_KRAJ

#include "Interface_drona.hh"
#include "Wektor.hh"

/*!
*\brief Interfejs elementow krajobrazu - przeszkod
*/
class Inter_kraj {
public:
    /*!
    *\brief Sprawdza czy dron znajduje sie nad przeszkoda
    *\param D - Wskaznik na interfejs drona
    */
    virtual bool czy_nad(Inter_drona * D)=0;

    /*!
    *\brief Sprawdza czy dron moze ladowac
    *\param D - Wskaznik na interfejs drona
    */
    virtual bool czy_ladowac(Inter_drona * D)=0;

    /*!
    *\brief Zwraca polozenie srodka przeszkody
    */
    virtual wektor<3> polozenie()=0;
};






#endif