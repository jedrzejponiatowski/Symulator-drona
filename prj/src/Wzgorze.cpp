#include "Wzgorze.hh"


Wzgorze::Wzgorze(wektor<3> sr, int wys, int min, int max) :
    UkladW(sr, MacierzRot<3>(), nullptr), h(wys){
    srand(time(NULL));

    int ilosc_w = rand()%7+3 ;
    double stopnie=360.0/ilosc_w;

    for(int i =0; i<ilosc_w ; i++){
        wektor<3> tmp{double(rand()%(max-min)+min), 0, 0};
        tmp= MacierzRot<3>(i*stopnie,'z')*tmp;
        w_dolne.push_back(tmp);
    }
    rysuj();
}




void Wzgorze::rysuj(){
    UkladW globalny = uklad_w_globalnym();

    std::vector<Point3D> tmp1;
    std::vector<Point3D> tmp2;
    for (wektor<3> & x : w_dolne) {
    tmp1.push_back(konw_do_P3D(globalny.punkt_w_poprzedniku(x)));
    tmp2.push_back(konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{0,0,h})));
  } 

  std::vector<std::vector<Point3D> > tmp3;
  tmp3.push_back(tmp1);
  tmp3.push_back(tmp2);

  id=rysownik->draw_polyhedron(tmp3, "blue");
  
}



bool Wzgorze::czy_ladowac(Inter_drona *D) {
    if(this->czy_nad(D)==true){
        cout << "  Nie moze ladowac!" << endl << endl;
        return false;
    }
    else return false;
}


bool Wzgorze::czy_nad(Inter_drona *D) {

    wektor<3> pol_dron = D->polozenie();
    wektor<3> pol_przesz =polozenie();
    pol_dron[2]=0;
    pol_przesz[2]=0;

    double odl =  (pol_dron-pol_przesz).dlugosc();

    for (wektor<3> & x : w_dolne){
        if( (x.dlugosc()+D->wielkosc() ) > odl){
        cout << "\n\n\n\t\tDron nad przeszkoda.";
        return true;
        }
    }
    
    return false;

}

 wektor<3> Wzgorze::polozenie(){
     return get_srodek();
 }