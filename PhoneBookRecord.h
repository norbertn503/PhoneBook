#ifndef PHONEBOOKRECORD_H
#define PHONEBOOKRECORD_H

#include "myString.h"
#include "PhoneBookRecord.h"

class PhoneBookRecord{
    myString Name;
    myString Address;
    myString Number;

public:
    ///Konstruktor
    PhoneBookRecord(myString Na ,myString Ad ,myString Nu):Name(Na), Address(Ad), Number(Nu){}

   ///Destruktor
    virtual ~PhoneBookRecord(){}

    myString getName()const {return Name;}
    myString getNumber()const {return Number;}
    void setNumber(myString s){Number = s;}
    myString getAddress()const {return Address;}
    void setAddress(myString s){Address = s;}

    virtual void setHDN(myString){};
    virtual void setPnumber(myString){};
    virtual void setNickname(myString){};

    ///Objektum kiírása
    ///param - output stream ahova a kiírás történni fog
    virtual void write(std::ostream&);

    ///Egyenlőség operator
    ///param - a művelet másik operandusa
    ///return - művelet eredménye
    bool operator==(const PhoneBookRecord&);

 //   virtual PhoneBookRecord* clone() = 0;

};

#endif // PHONEBOOKRECORD_H
