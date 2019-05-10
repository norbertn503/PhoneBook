#include <cstring>
#include "String.h"

String::String():Len(0){
    Str = new char[1];
    Str[0] = '\0';
}

String::String(char c):Len(1){
    Str = new char[Len +1];
    Str[0] = c;
    Str[1] = '\0';
}

String::String(const char* c){
    Len = strlen(c);
    Str = new char[Len + 1];
    strcpy(Str, c);
}

String::String(const String& s){
    Len = s.Len;
    Str = new char[Len + 1];
    strcpy(Str,s.Str);
}

String::~String(){delete[] Str;}

String String::operator+(const String& s)const {
    String uj;
    uj.Len = Len + s.Len;
    delete []uj.Str;
    uj.Str = new char[uj.Len + 1];
    strcpy(uj.Str, Str);
    strcat(uj.Str, s.Str);
    return uj;
}

//String String::operator+(char ch){

//}
