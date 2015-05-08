#include "String.h"
#include "memtrace.h"


String::String(const char c){
    len=1;
    str=new char[len + 1];
    str[0] = c;
	str[1] = 0;

}

String::String(const char* s){
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}
String::String(const String& s){
    len=s.len;
    str=new char[len+1];
    strcpy(str, s.str);
}
String::String(const char* from, const char* to){
	len = to - from;
	str = new char[len + 1];
	strncpy(str, from, len + 1 );
	str[len] = 0;
}

String& String::operator=(const String& s){
    if(str!=NULL)
        delete[] str;
    len=s.len;
    str=new char[len+1];
    strcpy(str, s.str);
    return *this;
}

bool String::operator==(const String& s){
    if(len!=s.len)
        return false;
    if(strcmp(str, s.str))
        return false;
    return true;
}

bool String::operator>(const String& s){
	return (strcmp(str, s.str) > 0);
}

void String::operator+=(const char c){
    if(str!=NULL){
		char* temp = new char[len + 1];
        strcpy(temp, str);
        delete[] str;
        len++;
		str = new char[len + 1];
		strcpy(str, temp);
    }
    else {
        len++;
		str = new char[len + 1];
    }
	str[len - 1] = c;
	str[len] = 0;
}
void String::operator+=(const String& s){
    if(str!=NULL){
        char* temp=new char[len+1];
        strcpy(temp, str);
        delete[] str;
        len=len+s.len;
        str=new char[len+1];
        strcpy(str, temp);
        strcat(str, s.str);
    }
    else{
        len=s.len;
        str=new char[len+1];
        strcpy(str, s.str);
    }
}
char& String::operator[](unsigned int i){
    if(i>=0 && i<len)
        return str[i];
    else throw std::out_of_range("Hibas string indexeles");
}
unsigned int String::where(const char c){
	return (strchr(str, c)-str+1);
}
unsigned int String::where(const char c, int n){
	char* temp=str;
	for (int i = 0; i < n; ++i) {
		temp = strchr(temp, c)+1;
	}
	int dir = temp - str;
	return (dir);
}
bool String::find(const char* s){
	return !(strcmp(str, s));
}

void String::erase(){
    if(str!=NULL)
        delete[] str;
    str=NULL;
    len=0;
}

String::~String(){
   if(str!=NULL)
        delete[] str;
}

