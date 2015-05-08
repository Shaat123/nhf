#include <iostream>
#include "hozzavalo.h"
#include "recept.h"
#include "recepttar.h"
#include "String.h"
#include "memtrace.h"



void teszt1(){
    //default recepttar betoltese es kiirasa
    ReceptTar TAR;
    TAR.kiir();
}
void teszt2(){
    //default recepttar betoltese es kiirasa,
    //aztan csereje egy masikra es ellenorzes hogy tenyleg cserelodott
    ReceptTar TAR;
    TAR.kiir();
    TAR.DB_csere("dat.dat");
    std::cout<<"---------------------------------------------------------"<<std::endl;
    TAR.DB_replace();
    TAR.kiir();
}
void teszt3(){
    //default mentese egy uj fajlba, masik recepttar felepitese es kiirasa onnan
    ReceptTar TAR;
    TAR.kiir();
    TAR.DB_csere("uj.dat"); //nem letezo fajl
    TAR.ment();
    ReceptTar TAR2;
    TAR2.DB_csere("uj.dat");
    TAR2.DB_replace();
    TAR2.kiir();
}

int main()
{
	//_StartMemoryCheck();
	//char* a = "Aladar";
	//String line(a);
	//std::cout << line;
	int i;
    std::cin>>i;
    switch (i){
        case 1:
            teszt1();
            break;
        case 2:
            teszt2();
            break;
        case 3:
            teszt3();
            break;
        default:
            break;
    }
	char c;
	while (std::cin >> c);
    return 0;
	//_CrtDumpMemoryLeaks();
}
