#include "Graniastoslup6.hh"



void Graniastoslup6::rysuj() {
    UkladW globalny = uklad_w_globalnym();

    int tmp=rysownik->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {{

    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r,0 ,0})),    
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r/2,-0.866*r ,0})) , 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r/2,-0.866*r ,0})),  
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r,0 ,0})),
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r/2,0.866*r ,0})),  
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r/2,0.866*r,0}))
      },{
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r,0 ,h})),    
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r/2,-0.866*r ,h})) , 
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r/2,-0.866*r ,h})),  
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r,0 ,h})),
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{-r/2,0.866*r ,h})),  
    konw_do_P3D(globalny.punkt_w_poprzedniku(wektor<3>{r/2,0.866*r,h}))
      }}, kolor);

    if(id!=-1)
        rysownik->erase_shape(id);
    id=tmp;

}
