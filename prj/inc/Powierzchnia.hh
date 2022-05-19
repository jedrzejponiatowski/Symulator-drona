#ifndef POWIERZCHNIA
#define POWIERZCHNIA
#include "Dron.hh"


/*!
*\brief Tworzy siatke - imitacja powierzchni.
*/
class Powierzchnia: public Inter_rys{
    double h;
public:
    /*!
    *\brief Konstruktor. 
    *\param wys polozenie w OZ, na ktorym znajdzie sie siatka
    */
    Powierzchnia(double wys) : h(wys) {}
    
    void rysuj() override;
};







#endif