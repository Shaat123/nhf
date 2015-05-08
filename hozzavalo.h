#ifndef HOZZAVALO_H_INCLUDED
#define HOZZAVALO_H_INCLUDED
#include <iostream>
#include "String.h"
#include "memtrace.h"

class Hozzavalo{
    int sorszam;
    double mennyiseg;
    String mertekegyseg;
    String anyag;
public:
    Hozzavalo():sorszam(0), mennyiseg(0), mertekegyseg(), anyag(){}
	Hozzavalo(int s, double am, String& unit, String& mat) :sorszam(s), mennyiseg(am), mertekegyseg(unit), anyag(mat){}
    void operator=(Hozzavalo& h);
    void kiir(std::ostream&);
};


#endif // HOZZAVALO_H_INCLUDED
