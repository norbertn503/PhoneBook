#include "PhoneBook.h"
#include "myString.h"
#include "Person.h"
#include "Institution.h"

PhoneBook::PhoneBook(std::istream& is){
    Size = 0;
    PhoneBookRecord** tmp;
    List = new PhoneBookRecord*[1];
    myString s0,s1,s2,s3,s4,s5;

    while(!is.eof()){
        if(Size != 0){
            tmp = new PhoneBookRecord*[Size+1];

            for(size_t i = 0; i < Size; i++){
                tmp[i]=List[i];
            }
            delete[] List;
            List = tmp;
        }//if

        is >> s0;

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

       Size++;
    }//while

    Size--;
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