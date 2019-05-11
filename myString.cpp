#include <cstring>
#include "myString.h"

myString::myString():Len(0){
    Str = new char[1];
    Str[0] = '\0';
}

myString::myString(char c):Len(1){
    Str = new char[Len +1];
    Str[0] = c;
    Str[1] = '\0';
}

myString::myString(const char* c){
    Len = strlen(c);
    Str = new char[Len + 1];
    strcpy(Str, c);
}

myString::myString(const myString& s){
    Len = s.Len;
    Str = new char[Len + 1];
    strcpy(Str,s.Str);
}

myString::~myString(){
    delete[] Str;
}

myString& myString::operator=(const myString& s){
    if(this != &s){
        delete []Str;
        Len = s.getLen();
        Str = new char[Len + 1];
        strcpy(Str, s.Str);
    }
    return *this;
}

myString myString::operator+(const myString& s)const {
    myString uj;
    uj.Len = Len + s.Len;
    delete[] uj.Str;
    uj.Str = new char[uj.Len + 1];
    strcpy(uj.Str, Str);
    strcat(uj.Str, s.Str);
    return uj;
}

myString myString::operator+(char ch)const{
    return *this + myString(ch);
}

bool myString::operator==(const myString& s)const {
    if(Len !=s.Len) return false;
    for(size_t i =0; i<Len; i++){
        if(Str[i]!=s.Str[i]) return false;
    }
    return true;
}

bool myString::operator!=(const myString& s)const{
    return !(*this == s);
}

std::ostream& operator<<(std::ostream& os, const myString& s){
     os << s.getStr();
     return os;
}

std::istream& operator>>(std::istream& is, myString& s){
    unsigned char ch;
    s = myString("");
   is >> std::noskipws;
   while(is >> ch){
    if(ch == '\n') break;
    s = s + ch;
   }
    return is;
}
