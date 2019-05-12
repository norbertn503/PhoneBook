#include "PhoneBookRecord.h"

bool PhoneBookRecord::operator==(const PhoneBookRecord& p){
     return Name == p.Name && Address == p.Address && Number == p.Number ;
}

void PhoneBookRecord::write(std::ostream& os){
    os << Name << ", " << Address << ", " << Number << ", ";
}
