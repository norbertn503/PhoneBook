#include "Institution.h"

bool Institution::operator==(const Institution& i){
    return PhoneBookRecord::operator==(i) && HelpDeskNumber == i.HelpDeskNumber;
}

void Institution::write(std::ostream& os){
    PhoneBookRecord::write(os);
    os << HelpDeskNumber << std::endl;
}
