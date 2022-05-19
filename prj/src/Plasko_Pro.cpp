#include "Plasko_Pro.hh"
#include <cmath>


bool Plaskowyz_Pro::czy_ladowac(Inter_drona *D) {
   if(this->czy_nad(D)==true){
      wektor<3> pol_drona = D->polozenie();
      pol_drona[2]=0;
      wektor<3> pol_przeszkody=this->polozenie();
      pol_przeszkody[2]=0;
   
   double roznica = (pol_drona - pol_przeszkody).dlugosc();
   
   if( (abs(roznica) < _rozpietosc[0]) || (abs(roznica) < _rozpietosc[1])){

      wektor<3> tmp1=D->polozenie();
      wektor<3> tmp2=this->polozenie();
      double wysokosc =  (tmp1[2]-tmp2[2]-2*_rozpietosc[2]);
      cout << " Moze wyladowac. \n\t\tWysokosc do przeszkody:  " << wysokosc << endl << endl;
      return true;
      } else {
      cout << "  Nie moze ladowac!" << endl << endl;
      return false;
      }
   }   
   else return false;
   
}


bool Plaskowyz_Pro::czy_nad(Inter_drona *D){
   
   wektor<3> pol_drona=D->polozenie();
   pol_drona[2]=0;
   wektor<3> pol_przeszkody=polozenie();
   pol_przeszkody[2]=0;
  
   double roznica = (pol_drona - pol_przeszkody).dlugosc();

   if( abs(roznica) < _rozpietosc[0]+D->wielkosc() || abs(roznica) < _rozpietosc[1]+D->wielkosc()){
     cout << "\n\n\n\t\tDron nad przeszkoda.";
     return true;
   }
   else return false;
}

wektor<3> Plaskowyz_Pro::polozenie(){
   return get_srodek();
}