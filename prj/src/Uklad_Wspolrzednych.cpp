#include "Uklad_Wspolrzednych.hh"


void UkladW::wyswietl(){
    std::cout << srodek << std::endl;
    std::cout << orientacja << std::endl;

}

wektor<3> UkladW::punkt_w_poprzedniku(wektor<3> punkt){
    wektor<3> wynik;
    wynik= srodek + (orientacja*punkt);
    return wynik;
}


UkladW UkladW::uklad_w_globalnym(){

    UkladW * tmp = poprzednik;
    UkladW * globalny = tmp;
    std::vector<MacierzRot<3> >kolejka;
    int licznik=1;
    wektor<3> wynik=srodek;
    kolejka.push_back(orientacja);

    while(tmp!=nullptr){
        wynik=tmp->punkt_w_poprzedniku(wynik);
        kolejka.push_back(tmp->orientacja);
        licznik++;
        globalny=tmp;
        tmp=tmp->poprzednik;
        
    }
    
    MacierzRot<3> r;
    for (int i=licznik; i>0 ; i--) {
                     r=r*kolejka.back();
                     kolejka.pop_back();
              }

    return UkladW(wynik, r, globalny);
}
