#include "Scena.hh"


/********************************************************************************/
Scena::Scena(){
    elem_rys.push_back(shared_ptr<Inter_rys> (new Plaskowyz(wektor<3>{120,0,-150}, 20, 40, 60)));
    elem_kraj.push_back(dynamic_pointer_cast<Inter_kraj> (elem_rys.back() ));

    elem_rys.push_back(shared_ptr<Inter_rys>(new Plaskowyz_Pro(wektor<3>{-100,-50,-150}, MacierzRot<3>(45,'z'), 70, 50, 20)));
    elem_kraj.push_back(dynamic_pointer_cast<Inter_kraj> (elem_rys.back() ));

    elem_rys.push_back(shared_ptr<Inter_rys>(new Wzgorze(wektor<3>{-20,100,-150}, 100, 40, 80)));
    elem_kraj.push_back(dynamic_pointer_cast<Inter_kraj> (elem_rys.back() ));

    
    elem_rys.push_back(shared_ptr<Inter_rys>(new Dron(wektor<3>{0,-100,-150}, MacierzRot<3>() )));
    drony.push_back(dynamic_pointer_cast<Inter_drona> (elem_rys.back() ));
    shared_ptr<Inter_drona> & tmp= drony.back();
    this->aktualny=tmp.get();

}

/********************************************************************************/

void Scena::rysuj_wszystko() {
    for (shared_ptr<Inter_rys> & x : elem_rys){
    Inter_rys* tmp= x.get();
    tmp->rysuj();
    }
}

/********************************************************************************/

void Scena::animuj(double wys, double kat, double odl){
    if(drony.size()!=0)
        aktualny->animacja(wys, kat, odl);
    else cerr << "     \nBrak dronow!" << endl;

    sprawdz_kolizje();
}

/********************************************************************************/

void Scena::dodaj_przeszkode(){
    cout << endl << " Dodawanie przeszkody: " << endl;
    cout << " 1 - Plaskowyz " << endl
         << " 2 - Wzgorze " << endl
         << " 3 - Plaskowyz Prostopadloscienny" << endl
         << " Twoj wybor >  ";

    int wybor;
    cin >> wybor;
    switch(wybor){
        case 1: {
            cout << "Podaj wspolrzedna x,y: ";
            double x,y;
            cin >> x >> y;
            cout << "Podaj wysokosc, min i max odleglosc:  ";
            double h, min, max;
            cin >> h >> min >> max;
            while(std::cin.get() != '\n');

            if(min<max){
                elem_kraj.push_back(shared_ptr<Inter_kraj> (new Plaskowyz(wektor<3>{x,y,-150}, h, min, max)));
                elem_rys.push_back(dynamic_pointer_cast<Inter_rys> (elem_kraj.back() ));
            } else cerr<< "Blad wpisanych danych" << endl;
            break;
        }
        case 2: {
            cout << "Podaj wspolrzedna x,y: ";
            double x,y;
            cin >> x >> y;
            cout << "Podaj wysokosc, min i max odleglosc:  ";
            double h, min, max;
            cin >> h >> min >> max;
            while(std::cin.get() != '\n');

            if(min<max){
                elem_kraj.push_back(shared_ptr<Inter_kraj> (new Wzgorze(wektor<3>{x,y,-150}, h, min, max)));
                elem_rys.push_back(dynamic_pointer_cast<Inter_rys> (elem_kraj.back() ));
            } else cerr<< "Blad wpisanych danych" << endl;
            break;
        }
        case 3: {
            cout << "Podaj wspolrzedna x,y i kat obrotu:  ";
            double x,y,kat;
            cin >> x >> y >> kat;
            cout << "Podaj wysokosc(y), szerokosc(x) i glebokosc(z):  ";
            double h, min, max;
            cin >> h >> min >> max;
            while(std::cin.get() != '\n');

            elem_kraj.push_back(shared_ptr<Inter_kraj> (new Plaskowyz_Pro(wektor<3>{x,y,-150},MacierzRot<3>(kat,'z'), h, min, max)));
            elem_rys.push_back(dynamic_pointer_cast<Inter_rys> (elem_kraj.back() ));
            break;
        }
        default : cerr << "Nie ma takiej przeszkody!" << endl;
    }
    sprawdz_kolizje();
}

/********************************************************************************/

void Scena::dodaj_drona(){
    cout << "Podaj wspolrzedna x,y drona:  ";
    double x,y;
    cin >> x >> y;
    while(std::cin.get() != '\n');

    elem_rys.push_back(shared_ptr<Inter_rys>(new Dron(wektor<3>{x,y,-150}, MacierzRot<3>() )));
    drony.push_back(dynamic_pointer_cast<Inter_drona> (elem_rys.back() ));
    sprawdz_kolizje();
}

/********************************************************************************/

void Scena::usun_przeszkode(uint id){

    if(id>=0 && id-1 < elem_kraj.size() ){
        shared_ptr<Inter_kraj> tmp = elem_kraj[id-1];
        shared_ptr<Inter_rys> tmp1 = dynamic_pointer_cast<Inter_rys>(tmp);
    
        elem_rys.erase(remove(elem_rys.begin(), elem_rys.end(), tmp1 ), elem_rys.end());
        elem_kraj.erase(remove(elem_kraj.begin(), elem_kraj.end(), tmp ), elem_kraj.end() );
} else {
    cerr << "Taki element nie istnieje!" << endl;
}
}

/********************************************************************************/

void Scena::usun_drona(uint id){

if(id>=0 && id-1 < drony.size() ){
    shared_ptr<Inter_drona> tmp = drony[id-1];
    shared_ptr<Inter_rys> tmp1 = dynamic_pointer_cast<Inter_rys>(tmp);
    
    if(tmp->polozenie() == aktualny->polozenie()){
        aktualny=nullptr;
    }

    elem_rys.erase(remove(elem_rys.begin(), elem_rys.end(), tmp1 ), elem_rys.end());
    drony.erase(remove(drony.begin(), drony.end(), tmp ), drony.end() );
} else {
    cerr << "Taki dron nie istnieje!" << endl;
}
}

/********************************************************************************/

void Scena::pokaz_drony(){
    int i =1;
    if(drony.size()!=0){
        cout << "id dronow:         wspolrzedne:" << endl;
        for (shared_ptr<Inter_drona> & x : drony){
            Inter_drona* tmp= x.get();
            cout <<  i << "              " << tmp->polozenie() << endl;
            i++;
        }
        cout << "\n\n Aktualny dron:  " << aktualny->polozenie() << endl;
     
    } else cerr << "    Brak dronow!" << endl;
}

/********************************************************************************/

void Scena::wyswietl_przeszkody(){
    int i =1;
    cout << "id:         wspolrzedne:" << endl;
    for (shared_ptr<Inter_kraj> & x : elem_kraj){
    Inter_kraj* tmp= x.get();
    cout <<  i << "    " << tmp->polozenie() << endl;
    i++;
    }



}

/********************************************************************************/

void Scena::wybierz_drona(uint id){

    if(id>=0 && id-1 < drony.size() ){
        shared_ptr<Inter_drona> & tmp= drony[id-1];
        this->aktualny=tmp.get();
    } else cerr << "    \n Taki dron nie istnieje!" << endl;
    sprawdz_kolizje();
}

void Scena::sprawdz_kolizje(){
    for (shared_ptr<Inter_kraj> &x : elem_kraj){
        Inter_kraj* tmp= x.get();
        tmp->czy_ladowac(aktualny);
    }


    std::vector<shared_ptr<Inter_kraj> > tmp_kolekcja;

    for(shared_ptr<Inter_drona> &x :drony){
        tmp_kolekcja.push_back(dynamic_pointer_cast<Inter_kraj> (x));
    }

    for (shared_ptr<Inter_kraj> &x : tmp_kolekcja){
        Inter_kraj* tmp= x.get();
            if(tmp->polozenie() == aktualny->polozenie()) ;
            else tmp->czy_ladowac(aktualny);
        
    }
}