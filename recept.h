#ifndef RECEPT_H_INCLUDED
#define RECEPT_H_INCLUDED
#include "hozzavalo.h"
#include <iostream>
#include "String.h"
#include "memtrace.h"

class Recept{
    int hvszam;
    Hozzavalo* hozzavalok;
    String cim;
    String receptszoveg;
    static int maxhozzavalok;
public:
    Recept():hvszam(0),hozzavalok(NULL),cim(), receptszoveg(){}    // hozzavalok, receptszoveg, hvszam=0
    void operator=(Recept& r); //egy masik recept objektum feltoltese ennek az adataival
    void add_hv(String&); //dinamikusan foglal
    void remove_hv(unsigned int n);
	void add_cim(String& s){ cim = s; };
	void add_szoveg(String& s){ receptszoveg += s; }
	void remove_szoveg(){ receptszoveg.erase(); }
    void maxhv_change(int);
    String getcim(){return cim;}
    void kiir();
    void ment(std::ostream& OS);

    ~Recept();
};

#endif // RECEPT_H_INCLUDED
