#include <iostream>
#include <iomanip>
#include <fstream>
#include "Powierzchnia.hh"
#include "Plasko_Pro.hh"
#include "Interface_drona.hh"
#include "Wzgorze.hh"
#include "Scena.hh"

using namespace std;
using namespace drawNS;

Draw3DAPI * Inter_rys::rysownik = new APIGnuPlot3D(-200,200,-200,200,-150,150,0);

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

void menu();


int main(){
      Scena S;

      menu();
      int wybor;
      cout << endl << " Twoj wybor > ";
      cin >> wybor;
     
      while(wybor!=99){
       
      switch (wybor){
       case 1: 
              cout << "Wpisz wysokosc, kat obrotu i dlugosc lotu >";
              double wys, rot, odl;
              cin >> wys >> rot >> odl;
              S.animuj(wys,rot,odl);
              break;

       case 2:
              S.dodaj_przeszkode();
              break;

       case 3:
              cout << "\n\n Aktualne przeszkody: " << endl;
              S.wyswietl_przeszkody();
              cout << "\n Wpisz id elementu do usuniecia: ";
              int id_kraj;
              cin >> id_kraj;
              S.usun_przeszkode(id_kraj);
              break;

       case 4:
              S.dodaj_drona();
              break;
       
       case 5:
              cout << "\n\n Aktualne drony: " << endl;
              S.pokaz_drony();
              cout << "\n Wpisz id drona do usuniecia: ";
              int id_drona;
              cin >> id_drona;
              S.usun_drona(id_drona);
              break;

       case 6:
              cout <<"\n\n Aktualne drony: " << endl;
              S.pokaz_drony();
              cout << "\n Wybierz drona: ";
              int id_zmiana;
              cin >> id_zmiana;
              S.wybierz_drona(id_zmiana);
              break;

       case 7:
              cout << "\n\n Wspolrzedne przeszkod:  " << endl;
              S.wyswietl_przeszkody();
              cout << "\n\n Wspolrzedne dronow:  " << endl;
              S.pokaz_drony();
              break;

       default : cerr << "Brak takiej opcji!" << endl;
       }

       menu();
       cout << endl << " Twoj wybor > ";
       cin >> wybor;
       }
    

       return 0;
}



void menu(){
       cout << "   \nMenu:" << endl;
       cout << "   1 - lot drona" << endl;
       cout << "   2 - dodaj przeszkode" << endl; 
       cout << "   3 - usun przeszkode" << endl; 
       cout << "   4 - dodaj drona" << endl; 
       cout << "   5 - usun drona" << endl;
       cout << "   6 - zmien aktualnego drona" << endl;  
       cout << "   7 - wyswietl wspolrzedne" << endl; 
       cout << "  99 - zakoncz program" << endl; 

}