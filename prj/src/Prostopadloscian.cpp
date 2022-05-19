#include "Prostopadloscian.hh"
#define EPSILON 0.000000000000003

void Prostopadloscian::rysuj(){
    UkladW globalny = uklad_w_globalnym();
    
    int tmp=rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > { { 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/2,szer/2,0})),    
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/-2,szer/2,0})) , 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/-2,szer/-2,0})),  
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/2,szer/-2,0}))
      },{
	konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/2,szer/2,gleb})),   
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/-2,szer/2,gleb})) , 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/-2,szer/-2,gleb})), 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{wys/2,szer/-2,gleb}))      
	}},"black");


    if(id!=-1)
        rysownik->erase_shape(id);
    id=tmp;
    

}
















#define test2
#ifndef test2
Prostopadloscian::Prostopadloscian(const std::array<wektor<3> ,8 > &arg){
    for(int i=0; i<8 ; i++){
    wierzcholki[i]=arg[i];
    }

    for(int i=1;i<4;i++){
        if(wymiary_check(i)==false){
            switch(i){
                case 1: std::cerr<< "Krotsze boki nie sa rowne\n"; break;
                case 2: std::cerr<< "Dluzsze boki nie sa rowne\n"; break;
                case 3: std::cerr<< "Poprzeczne boki nie sa rowne\n"; break;
            }
        }
    }

    id=-1;
}

/*************************************************************************************************/
void Prostopadloscian::rotacja(const MacierzRot<3> &M){
    for(int i=0 ; i<8 ; i++){
        wierzcholki[i]=M*wierzcholki[i];
    }
}

/*************************************************************************************************/

void Prostopadloscian::translacja(const wektor<3> &W){
    for(int i=0 ; i<8 ; i++){
        wierzcholki[i]=wierzcholki[i]+W;
    }
}

/*************************************************************************************************/

drawNS::Point3D Prostopadloscian::konwertuj(const wektor<3> &wek){
    drawNS::Point3D wynik(wek[0], wek[1], wek[2]);
    return wynik;
}

/*************************************************************************************************/

void Prostopadloscian::rysuj(drawNS::Draw3DAPI * rysownik){

    int tmp=rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{
	konwertuj(wierzcholki[0]), konwertuj(wierzcholki[1]), 
    konwertuj(wierzcholki[2]), konwertuj(wierzcholki[3])
      },{
	konwertuj(wierzcholki[4]), konwertuj(wierzcholki[5]), 
    konwertuj(wierzcholki[6]), konwertuj(wierzcholki[7])       
	}},"black");

    if(id!=-1)
        rysownik->erase_shape(id);
    id=tmp;
}

/*************************************************************************************************/

bool Prostopadloscian::wymiary_check(int konfig){
    switch(konfig){
        case 1: //krotsze
            if( sqrt(pow((wierzcholki[3] - wierzcholki[0]).dlugosc()-(wierzcholki[2] - wierzcholki[1]).dlugosc(),2)) > EPSILON 
             || sqrt(pow((wierzcholki[7] - wierzcholki[4]).dlugosc()-(wierzcholki[6] - wierzcholki[5]).dlugosc(),2)) > EPSILON
            ) return false;
            break;
        case 2: //dluzsze
            if( sqrt(pow((wierzcholki[2] - wierzcholki[3]).dlugosc()-(wierzcholki[1] - wierzcholki[0]).dlugosc(),2)) > EPSILON 
            ||  sqrt(pow((wierzcholki[6] - wierzcholki[7]).dlugosc()-(wierzcholki[5] - wierzcholki[4]).dlugosc(),2)) > EPSILON
            ) return false;
            break;
        case 3: //poprzeczne
            if( sqrt(pow((wierzcholki[4] - wierzcholki[0]).dlugosc()-(wierzcholki[7] - wierzcholki[3]).dlugosc(),2)) > EPSILON 
            ||  sqrt(pow((wierzcholki[5] - wierzcholki[1]).dlugosc()-(wierzcholki[6] - wierzcholki[2]).dlugosc(),2)) > EPSILON
            ) return false;
            break;
    }
    return true;
}   

/*************************************************************************************************/

void Prostopadloscian::wyswietl_boki(){
              cout.precision(15);
              cout << std::fixed;
              cout << "Krotsze boki:" << endl;
              cout << "Bok pierwszy:  " <<  (wierzcholki[3] - wierzcholki[0]).dlugosc() << endl;
              cout << "Bok drugi:  " << (wierzcholki[2] - wierzcholki[1]).dlugosc() << endl;
              cout << "Bok trzeci:  " << (wierzcholki[6] - wierzcholki[5]).dlugosc() << endl;
              cout << "Bok czwarty:  " << (wierzcholki[7] - wierzcholki[4]).dlugosc() << endl;
              cout << endl << "Dluzsze boki:" << endl;
              cout << "Bok pierwszy:  " << (wierzcholki[2] - wierzcholki[3]).dlugosc() << endl;
              cout << "Bok drugi:  " << (wierzcholki[1] - wierzcholki[0]).dlugosc() << endl;
              cout << "Bok trzeci:  " << (wierzcholki[6] - wierzcholki[7]).dlugosc() << endl;
              cout << "Bok czwarty:  " << (wierzcholki[5] - wierzcholki[4]).dlugosc() << endl;
              cout << endl << "Poprzeczne boki:" << endl;
              cout << "Bok pierwszy:  " << (wierzcholki[4] - wierzcholki[0]).dlugosc() << endl;
              cout << "Bok drugi:  " << (wierzcholki[7] - wierzcholki[3]).dlugosc() << endl;
              cout << "Bok trzeci:  " << (wierzcholki[5] - wierzcholki[1]).dlugosc() << endl;
              cout << "Bok czwarty:  " << (wierzcholki[6] - wierzcholki[2]).dlugosc() << endl;
              
}

/*************************************************************************************************/


const wektor<3> & Prostopadloscian::operator [](int ind) const{
    if(ind>7 || ind<0)
        std::cerr<<"Indeks poza zakresem!";   
    return wierzcholki[ind];
}

/*************************************************************************************************/

std::ostream& operator << ( std::ostream &strm, const Prostopadloscian &pr){
    for(int i=0; i<8 ; i++)
    strm<< pr[i] << std::endl;
    return strm;
}
#endif