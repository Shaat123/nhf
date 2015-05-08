#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "recept.h"
#include "String.h"
#include "memtrace.h"

class ReceptTar{
    Recept *receptek;
    int n;
    std::fstream FILE;
    static const char* FILENAME;
    static int MAXRECEPT;
public:
    /* fajl megnyitasa olvasasra, sorok megszamolasa,
    ekkora meretu dinamikus Recept tomb foglalasa, sorok atadasa a Recept osztaly ertekado operatoranak hogy feltoltse a tombot
    */
    ReceptTar();
    void ment(); /* fajl megnyitasa irasra,  truncate opcioval, majd a Recept tomb elemeinek atadasa a Recept osztaly file output fuggvenyenek */

    void kiir(); /*receptek rendezese, majd sorszamozva soronkent kiiras*/

    void rendez(); /* receptek beturendbe rendezese */

    void kiir(const char* hozzavalo); /* receptek rendezese, majd azon receptek kiirasa, amelyekben megtalalhato az adott hozzavalo */
    void kiir(unsigned int receptszam, bool szoveg_is);  // kiirja az adott sorszamu recept hozavaloit, a hozzavalokat sorszamozva, szoveg_is==1 hatasara a recept szoveget is

    void add(); //letrehoz egy uj, ures receptet, es a lista vegere rakja

    void szerkeszt(unsigned int receptszam,unsigned int hozzavaloszam, const char* hozzavalo_szoveg); /* a hozzavalok listajabol valasztott sorszam alapjan (ha a letezo sorszamoknal nagyobb sorszamot kap, akkor uj, egyel nagyobb sorszamu hozzavalot hoz letre */
    void szerkeszt(unsigned int receptszam, const char* recept_szoveg); // a recept szovegenek szerkesztese

    void torol(unsigned int receptszam);//torli az adott szamu receptet, az esetleg utana allokat elorebb csusztatja egyel

    void urit(); // osszes recept torlese
    void DB_replace();
    void DB_csere(const char* filepath); // recepttar csereje  // egyfajta ertekado operatorkent mukodik, es egybol felul is irja az elozot
    void set_maxrecept(int i);
    ~ReceptTar();
};

















#endif // HEADER_H_INCLUDED
