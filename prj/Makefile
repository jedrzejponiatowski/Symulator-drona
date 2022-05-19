#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: Dron
	./Dron

Dron: obj obj/main.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o obj/Uklad_Wspolrzednych.o obj/Graniastoslup6.o obj/Dron.o obj/Powierzchnia.o  obj/Plaskowyz.o obj/Wzgorze.o obj/Plasko_Pro.o obj/Scena.o 
	g++ -Wall -pedantic -std=c++0x -o Dron obj/main.o obj/Prostopadloscian.o obj/Powierzchnia.o \
	obj/Uklad_Wspolrzednych.o obj/Graniastoslup6.o obj/Dron.o  obj/Dr3D_gnuplot_api.o obj/Plaskowyz.o obj/Wzgorze.o obj/Plasko_Pro.o obj/Scena.o -lpthread

obj:
	mkdir obj


obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Wektor.hh inc/Macierz.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ -c ${CXXFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Uklad_Wspolrzednych.o: src/Uklad_Wspolrzednych.cpp inc/Uklad_Wspolrzednych.hh
	g++ -c ${CXXFLAGS} -o obj/Uklad_Wspolrzednych.o src/Uklad_Wspolrzednych.cpp

obj/Graniastoslup6.o: src/Graniastoslup6.cpp inc/Graniastoslup6.hh
	g++ -c ${CXXFLAGS} -o obj/Graniastoslup6.o src/Graniastoslup6.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Powierzchnia.o: src/Powierzchnia.cpp inc/Powierzchnia.hh
	g++ -c ${CXXFLAGS} -o obj/Powierzchnia.o src/Powierzchnia.cpp



obj/Plaskowyz.o: src/Plaskowyz.cpp inc/Plaskowyz.hh
	g++ -c ${CXXFLAGS} -o obj/Plaskowyz.o src/Plaskowyz.cpp

obj/Wzgorze.o: src/Wzgorze.cpp inc/Wzgorze.hh
	g++ -c ${CXXFLAGS} -o obj/Wzgorze.o src/Wzgorze.cpp

obj/Plasko_Pro.o: src/Plasko_Pro.cpp inc/Plasko_Pro.hh
	g++ -c ${CXXFLAGS} -o obj/Plasko_Pro.o src/Plasko_Pro.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp




clean:
	rm -f obj/*.o Dron