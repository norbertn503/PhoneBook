#ifndef STRING_H
#define STRING_H

#include <iostream>

class String{
    char *Str;
    size_t Len;
public:
    String();
    String(char);
    String(const char*);
    String(const String&);
    ~String();

    size_t getLen()const {return Len;}
    const char* getStr()const {return Str;}

    String operator+(const String& s)const;
    String operator+(char ch)const;
    bool operator==(const String&) const;
    bool operator!=(const String&) const;
};


#endif // STRING_H
