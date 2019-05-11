#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "PhoneBookRecord.h"
#include "myString.h"

class PhoneBook{
    PhoneBookRecord** List;
    size_t Size;

public:
    PhoneBook(std::istream&);
  //  PhoneBook(const PhoneBook&);
    ~PhoneBook();

    size_t getSize()const {return Size;}
    void setSize(size_t l){Size = l;}

    void add(PhoneBookRecord*);
    void eraseRecord(myString);
    void change(myString,myString,myString);

    void write(std::ostream&);
};

#endif // PHONEBOOK_H
