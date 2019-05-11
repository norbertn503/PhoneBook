#ifndef PHONEBOOKRECORD_H
#define PHONEBOOKRECORD_H

#include "myString.h"
#include "PhoneBookRecord.h"

class PhoneBookRecord{
    myString Name;
    myString Address;
    myString Number;

public:
    PhoneBookRecord(myString Na ,myString Ad ,myString Nu):Name(Na), Address(Ad), Number(Nu){}
    virtual ~PhoneBookRecord(){}

    myString getName()const {return Name;}
    myString getNumber()const {return Number;}
    void setNumber(myString s){Number = s;}
    myString getAddress()const {return Address;}
    void setAddress(myString s){Address = s;}

    virtual void setHDN(myString){};
    virtual void setPnumber(myString){};
    virtual void setNickname(myString){};

    virtual void write(std::ostream&);

    bool operator==(const PhoneBookRecord&);

 //   virtual PhoneBookRecord* clone() = 0;

};

#endif // PHONEBOOKRECORD_H
