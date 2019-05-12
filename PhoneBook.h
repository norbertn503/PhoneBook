#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "PhoneBookRecord.h"
#include "myString.h"
#include <fstream>

class PhoneBook{
    PhoneBookRecord** List;
    size_t Size;

public:
    ///Konstruktor
    ///param - input fájl stream ahonnan beolvassa a telefonkönyvet
    PhoneBook(std::ifstream&);
  //  PhoneBook(const PhoneBook&);

    ///Destruktor
    ~PhoneBook();

    size_t getSize()const {return Size;}
    void setSize(size_t l){Size = l;}

    ///Elem hozzáadása
    ///param - alaposztály típusú pointer
    void add(PhoneBookRecord*);

    ///Elem törlése
    ///param - myString ami a törlendő elem telefonszáma
    void eraseRecord(myString);

    ///Elem adatainak megváltozatása
    ///param - myString ami a változtatandó elem telefonszáma
    ///param - myString ami az elem változtatandó típusát adja meg
    ///param - myString az új adat
    void change(myString,myString,myString);

    ///Telefonkönyv kiírása
    ///param - output stream ahova a kiírás történni fog
    void write(std::ostream&);
};

#endif // PHONEBOOK_H
