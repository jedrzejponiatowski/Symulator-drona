#include "Powierzchnia.hh"

using drawNS::Point3D;

void Powierzchnia::rysuj(){

std::vector<std::vector<Point3D> > tmp2;
for(int i=-200; i<=200 ; i+=25){
    std::vector<Point3D> tmp1;
    for(int j=-200; j<=200 ; j+=100)
        tmp1.push_back( Point3D(i,j,h) );
    tmp2.push_back(tmp1);
}

rysownik->draw_surface(tmp2 , "grey");
}
