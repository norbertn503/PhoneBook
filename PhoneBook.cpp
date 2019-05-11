#include "PhoneBook.h"
#include "myString.h"
#include "Person.h"
#include "Institution.h"

PhoneBook::PhoneBook(std::istream& is){
    Size = 0;
    PhoneBookRecord** tmp;
    List = new PhoneBookRecord*[1];
    myString s0,s1,s2,s3,s4,s5;

    for(; is >> s0; Size++){
        if(Size != 0){
            tmp = new PhoneBookRecord*[Size+1];

            for(size_t i = 0; i < Size; i++){
                tmp[i]=List[i];
            }
            delete[] List;
            List = tmp;
        }//if

        if(s0 == "p"){
            is >> s1 >> s2 >> s3 >> s4 >>s5;
            Person* newdata = new Person(s1,s2,s3,s4,s5);
            List[Size] = newdata;
        }

        else if(s0 == "i"){
            is >> s1 >> s2 >> s3 >> s4;
            Institution* newdata =  new Institution(s1,s2,s3,s4);
            List[Size] = newdata;
        }
    }//while
}

void PhoneBook::add(PhoneBookRecord* p){

    for(size_t i = 0; i < Size; i++){
        if(List[i]->getNumber() == p->getNumber()) throw "Már létezik ilyen adat";
    }

    PhoneBookRecord** tmp = new PhoneBookRecord*[Size+1];

    for(size_t i = 0; i < Size; i++){
        tmp[i] = List[i];
    }

    delete[] List;
    List = tmp;

    Size++;

    List[Size-1] = p;
}

void PhoneBook::eraseRecord(myString s){
    if(Size == 0)throw "A telefonkönyv üres";

    bool nincs = true;

    for(size_t i = 0; i < Size; i++){
        if(List[i]->getNumber() == s){
            nincs = false;
        }

    }
    if(nincs) throw "Nincs ilyen elem";

    PhoneBookRecord** tmp = new PhoneBookRecord*[Size];
    size_t j = 0;
    for(size_t i = 0; i < Size;i++){

        if(List[i]->getNumber() != s){
                tmp[j] = List[i];
                j+=1;
        }else{
            delete List[i];
        }
    }//for

    delete[] List;

    Size--;

    List = new PhoneBookRecord*[Size];
    for(size_t i = 0; i < Size ; i++){
        List[i] = tmp[i];
    }

    delete[] tmp;
}

void PhoneBook::change(myString s0, myString s1, myString s2){
    for(size_t i = 0; i < Size; i++){

        if(List[i]->getNumber() == s0){
            if(s1 == "Number"){

                for(size_t j = 0; j < Size; j++){
                    if(List[i]->getNumber() == s2)  throw "Ilyen szám már létezik";
                    }

                 List[i]->setNumber(s2);

            }else if(s1 =="Address") List[i]->setAddress(s2);

            else if(s1 == "Pnumber") List[i]->setNumber(s2);

            else if(s1 == "Nickname") List[i]->setNickname(s2);

            else if( s1 =="HelpDeskNumber") List[i]->setHDN(s2);

            else throw("Érvénytelen adat mező");
        }
    }

}

void PhoneBook::write(std::ostream& os){
    for(size_t i = 0; i < Size; i++){
        List[i]->write(os);
    }
}

PhoneBook::~PhoneBook(){
    for(size_t i = 0; i < Size; i++){
        delete List[i];
    }
    delete[] List;
}
