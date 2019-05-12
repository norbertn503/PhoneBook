#include "Person.h"

bool Person::operator==(const Person& p){
    return PhoneBookRecord::operator==(p) && Nickname == p.Nickname && Pnumber == p.Pnumber;
}


void Person::write(std::ostream& os){
    PhoneBookRecord::write(os);
    os << Pnumber << ", " << Nickname << std::endl;
}
