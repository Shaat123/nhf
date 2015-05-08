#include "hozzavalo.h"
#include "memtrace.h"

void Hozzavalo::operator=(Hozzavalo& h){
    sorszam=h.sorszam;
    mennyiseg=h.mennyiseg;
	mertekegyseg = h.mertekegyseg;
	anyag = h.anyag;
}


void Hozzavalo::kiir(std::ostream& OS){
    OS<<mennyiseg<<' '<<mertekegyseg<<' '<<anyag;
}
