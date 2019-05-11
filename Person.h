#ifndef PERSON_H
#define PERSON_H

#include "PhoneBookRecord.h"
#include "myString.h"

class Person: public PhoneBookRecord{
    myString Pnumber;
    myString Nickname;

public:
    Person(myString Na, myString Ad, myString Nu, myString Pn, myString Ni):
                PhoneBookRecord(Na,Ad,Nu),Pnumber(Pn) ,Nickname(Ni){}

    myString getNickname()const {return Nickname;}
    void setNickname(myString s){ Nickname = s;}
    myString getPnumber()const {return Pnumber;}
    void setPnumber(myString s){Pnumber = s;}

    bool operator==(const Person&);

    void write(std::ostream&);

//    PhoneBookRecord* clone();

};

#endif // PERSON_H
