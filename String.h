#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include "memtrace.h"

class String{
    char* str;
    size_t len;
public:
    String():str(NULL),len(0){}
    String(const char);
    String(const char*);
    String(const String&);
    String(const char* from, const char* to);

    String& operator=(const String&);

    bool operator==(const String&);
	bool operator>(const String&);
	bool operator<(const String& s){ return !(*this == s || *this>s); }

    void operator+=(const String&);
    void operator+=(const char);
    char& operator[](unsigned int);
	unsigned int where(const char); // karakter elso elofordulasat keresi
	unsigned int where(const char, int); // karakter n. elofordulasat keresi
	bool find(const char*); //talal-e egyezest benne

    bool empty(){return len==0;}
    void erase();

    char* c_str(){return str;}
	double str_to_double(){return atof(str);}

    size_t length(){return len;}
    friend std::ostream& operator<<(std::ostream& os, String& s){
		os<<s.c_str();
		return os;
	}
    ~String();

};


#endif // STRING_H_INCLUDED
