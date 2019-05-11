#ifndef INSTITUTION_H
#define INSTITUTION_H

#include "PhoneBookRecord.h"
#include "myString.h"

class Institution : public PhoneBookRecord{
    myString HelpDeskNumber;

public:
    Institution(myString Na, myString Ad, myString Nu, myString He):
                PhoneBookRecord(Na,Ad,Nu), HelpDeskNumber(He){}

    myString getHDN()const {return HelpDeskNumber;}
    void setHDN(myString s){HelpDeskNumber = s;}

    bool operator==(const Institution&);

    void write(std::ostream&);

   // PhoneBookRecord* clone();
};

#endif // INSTITUTION_H
