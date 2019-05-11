#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class myString{
    char *Str;
    size_t Len;
public:
    myString();
    myString(char);
    myString(const char*);
    myString(const myString&);
    ~myString();

    size_t getLen()const {return Len;}
    const char* getStr()const {return Str;}

    myString& operator=(const myString&);
    myString operator+(const myString& s)const;
    myString operator+(char ch)const;
    bool operator==(const myString&) const;
    bool operator!=(const myString&) const;
};

std::ostream& operator<<(std::ostream& os, const myString& s);
std::istream& operator>>(std::istream& is, myString& s);

#endif // MYSTRING_H
