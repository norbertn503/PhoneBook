#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class myString{
    char *Str;
    size_t Len;
public:
    ///Üres myString létrehozása
    myString();

    ///myString létrehozása karakterből
    ///param - karakter amiből myString lesz
    myString(char);

    ///myString létrehozása const char* ból
    ///param - const char* amiből myString lesz
    myString(const char*);

    ///myString másoló construktora
    ///param - egy mások myString objektum
    myString(const myString&);

    ///myString destruktor
    ~myString();

    size_t getLen()const {return Len;}
    const char* getStr()const {return Str;}

    ///értékadó operator
    ///param - művelet másik operandusa
    ///return myString referencia hogy működjön a többszörös értkadás
    myString& operator=(const myString&);

    ///myStringhez myStringet fűz
    ///param - a myStrnghez fűzendő myString
    ///return az eredmény myString
    myString operator+(const myString& s)const;

    ///myStringhez karaktert fűz
    ///param - a myStrnghez fűzendő karakter
    ///return az eredmény myString
    myString operator+(char ch)const;

    ///egyenlőség operator
    ///param - a művelet másik operandusa
    ///return művelet eredménye
    bool operator==(const myString&) const;

    ///egyenlőtlenség operator
    ///param - a művelet másik operandusa
    ///return művelet eredménye
    bool operator!=(const myString&) const;
};

///Kiíró operátor
///param - output stream amire kiír
///param - myString amit kiírunk
///return - output stream referencia
std::ostream& operator<<(std::ostream& os, const myString& s);

///beolvasó operator
///param - inputstream amiről beolvasunk
///param - myString amibe beolvasunk
///return - input stream referencia
std::istream& operator>>(std::istream& is, myString& s);

#endif // MYSTRING_H
