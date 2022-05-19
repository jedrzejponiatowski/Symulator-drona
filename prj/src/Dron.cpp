#include "Dron.hh"



Dron::~Dron(){
  korpus.zmaz();
  for(int i=0; i<4; i++)
    wirniki[i].zmaz();
}


void Dron::rysuj(){
  korpus.rysuj();
  for(int i=0; i<4; i++){
    wirniki[i].rysuj();}
}



void Dron::lec_do_przodu(double odl){
  translacja(wektor<3>{0,odl,0});
}

void Dron::lec_do_gory(double wys){
  translacja(wektor<3>{0,0,wys});
}


void Dron::obrot(double kat){
  rotacja(MacierzRot<3>(kat,'z'));
}


void Dron::animacja(double wys, double kat, double odl){

  if(wys>=0){
    for(double i=0; i <wys;i+=4){
      lec_do_gory(4);
      porusz_wirniki();
      rysuj();
      std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
  } else {
    
    for(double i=0; i >wys;i-=4){
       lec_do_gory(-4);
       porusz_wirniki();
       rysuj();
       std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
  } 



  if(kat>0){
    for(double j=0; j<kat;j+=4){
      obrot(4);
      porusz_wirniki();
      rysuj();
      std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
  } else {
    for(double j=0; j>kat;j-=4){
      obrot(-4);
      porusz_wirniki();
      rysuj();
      std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
  }



  if(odl>0){
    for(double k=0; k<odl;k+=4){
      lec_do_przodu(4);
      porusz_wirniki();
      rysuj();
      std::this_thread::sleep_for (std::chrono::milliseconds(100));
    }
  } else {
    if(odl!=0) std::cerr<< "Lot mozliwy tylko do przodu";
  }



  

}

void Dron::porusz_wirniki(){
    wirniki[0].rotacja(MacierzRot<3>(20,'z'));
    wirniki[1].rotacja(MacierzRot<3>(-20,'z'));
    wirniki[2].rotacja(MacierzRot<3>(-20,'z'));
    wirniki[3].rotacja(MacierzRot<3>(20,'z'));

}

  wektor<3> Dron::polozenie(){
    UkladW globalny = uklad_w_globalnym();
    wektor<3> wynik = globalny.punkt_w_poprzedniku(wektor<3>{0,0,0});
    

  return wynik;
  }


bool Dron::czy_ladowac(Inter_drona *D){
  if(czy_nad(D)==true){
    wektor<3> pol_argument = D->polozenie();
    wektor<3> pol_aktualny =polozenie();
    double wys = pol_argument[2] - pol_aktualny[2];
    cout << "  Wysokosc:  " << wys << endl << endl;
    return true;
  }
  else return false;
}


bool Dron::czy_nad(Inter_drona *D){

    wektor<3> pol_argument = D->polozenie();
    wektor<3> pol_aktualny =polozenie();
    pol_argument[2]=0;
    pol_aktualny[2]=0;

    double odl =  (pol_argument-pol_aktualny).dlugosc();

    if( 2*D->wielkosc() > odl){
      cout << "\n\n\n\t\tDron nad/pod innym dronem.";
      return true;
    } else return false;

}





double Dron::wielkosc(){
  return _rozpietosc;
}


