#ifndef WZGORZE
#define WZGORZE

#include "Plaskowyz.hh"
#include <cmath>


/*!
*\brief Modeluje przeszkode - wzgorze randomizowane.
*/
class Wzgorze: public UkladW, public Inter_rys, public Inter_kraj{
private:
    double h;
    std::vector< wektor<3> > w_dolne;
    int id;
public:
    /*!
    *\brief Konstruktor.
    *
    * Tworzy i rysuje wzgorze randomizowane. Odleglosc srodek-wierzcholek losowana z przedzialu min-max.
    * Ilosc wierzcholkow losowana z przedzialu 3-9.
    *\param sr wektor srodka przeszkody
    *\param wys wartosc wysokosci przeszkody
    *\param min minimalna odleglosc srodek-wierzcholek
    *\param max maksymalna odleglosc srodek-wierzcholek
    */
    Wzgorze(wektor<3> sr, int wys, int min, int max);

    /*!
    *\brief Destruktor. Zmazuje przeszkode w gnuplocie
    */
    ~Wzgorze() {rysownik->erase_shape(id);}

    void rysuj() override;
    bool czy_ladowac(Inter_drona *D) override;
    bool czy_nad(Inter_drona *D) override;
    virtual wektor<3> polozenie() override;
};




#endif