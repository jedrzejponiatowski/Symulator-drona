#ifndef INTER_RYS
#define INTER_RYS
#include "Dr3D_gnuplot_api.hh"
using namespace drawNS;


/*!
*\brief Interfejs rysowania.
*
*   Laczy z Draw3DAPI i rysuje w gnuplocie.
*/
class Inter_rys{
protected: 
    /*!
    *\brief Pole statyczne, wspolny wskaznik do rysowania
    */
    static Draw3DAPI *rysownik;
public:
    /*!
    *\brief Funkcja do rysowania w gnuplocie
    */
    virtual void rysuj() = 0;
};






#endif