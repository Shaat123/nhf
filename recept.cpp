#include "recept.h"
#include "memtrace.h"


/* egy recept kinézete:
Ez a recept cime
<cim end>
Ezek
A
Hozzavalok
<hv end>
Ez a recept szovege
<szoveg end>
*/
void Recept::add_hv(String& s){
    if(hozzavalok==NULL)
        hozzavalok=new Hozzavalo[maxhozzavalok];
    int firstspace=s.where(' ');
	String first(s.c_str(),s.c_str() + firstspace);
	int secondspace = s.where(' ', 2);
	double amount = first.str_to_double();

	String unit(s.c_str() + firstspace, s.c_str() + secondspace);
	String mat(s.c_str() + secondspace);
    hvszam++;
    Hozzavalo temp(hvszam, amount, unit, mat);
    hozzavalok[hvszam-1]=temp;
}

void Recept::kiir(){
	std::cout << cim << std::endl;
    for(int i=0; i<hvszam; ++i){
        hozzavalok[i].kiir(std::cout);
    }
	std::cout << std::endl << receptszoveg << std::endl;
}

void Recept::ment(std::ostream& OS){
    OS<<cim<<std::endl<<"<cim end>"<<std::endl;
    for(int i=0; i<hvszam; ++i){
        hozzavalok[i].kiir(OS);
        OS<<std::endl;
    }
    OS<<"<hv end>";
    OS<<std::endl<<receptszoveg<<"<szoveg end>";
}


int Recept::maxhozzavalok=100;
void Recept::maxhv_change(int i){
    maxhozzavalok=i;
}
void Recept::operator=(Recept& r){
	cim = r.cim;
	receptszoveg = r.receptszoveg;

	if (hozzavalok != NULL)
		delete[] hozzavalok;
    hvszam=r.hvszam;
    hozzavalok=new Hozzavalo[r.hvszam];
    for(int i=0; i<hvszam; ++i){
        hozzavalok[i]=r.hozzavalok[i];
    }
    maxhozzavalok=r.maxhozzavalok;
}

Recept::~Recept(){
    if(hozzavalok!=NULL)
        delete[] hozzavalok;
}

