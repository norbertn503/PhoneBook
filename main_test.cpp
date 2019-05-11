#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

#include "myString.h"
#include "PhoneBookRecord.h"
#include "Person.h"
#include "Institution.h"
#include "PhoneBook.h"

void Test_1(){
    std::cout << "myString osztály tesztje:" << std::endl;

    std::cout << "\t paraméter nélküli ctor: " << std::endl;
        myString ures;

        if(ures.getLen() == 0){
            std::cout << "Jó a hossz" << std::endl;
        } else std::cout << "Rossz a hossza" << std::endl;

    std::cout << "\t char paraméteres ctor:" << std::endl;
        char ch1 = 's';
        myString s1(ch1);
        if(s1.getLen() == 1){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;

        if(s1 == "s"){
        //valamiért mindig rossz de ha kíírom azt kapom amit kell és memória hiba sincs
            std::cout << "Jó a karakter" << std::endl;
        }else std::cout << "Rossz a karakter" << std::endl;

    std::cout << "\t const char* paraméteres ctor:" << std::endl;
        const char* teszt = "Hello string";
        myString s2(teszt);

        if(s2.getLen() == (size_t)strlen(teszt)){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;

        if(s2.getStr() == s2.getStr()){
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;

    std::cout << "\t copy ctor:" << std::endl;
        myString s3 = s2;

        if(s2.getLen() == s3.getLen()){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;

        if(s3 == "Hello string"){
        //valamiért mindig hamis lesz de ha kíírom azt kapom amit kell és memória hiba sincs
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;

    std::cout << "\toperator=(const myString&):" << std::endl;

    std::cout << "\toperator+(const myString&):" << std::endl;
        myString s4("Teszt");
        myString s5("elek");
        myString s6;

        s6 = s4 + s5;

        if(s6 == "Tesztelek"){
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;

    std::cout << "\toperator+(char):" << std::endl;
        myString s7("alm");
        char ch2 = 'a';
        myString s8;
        s8 = s7 + ch2;
        if(s8 == "alma"){
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;

    std::cout << "\toperator==(const myString&):" << std::endl;
        myString s9("alma");
        if(s8 == s9){
            std::cout << "Sikeres összehasonlítás" << std::endl;
        }else std::cout << "Sikertelen összehasonlítás" << std::endl;

    std::cout << "\toperator!=(const myString):" << std::endl;
         if(s3 != s9){
            std::cout << "Sikeres összehasonlítás" << std::endl;
        }else std::cout << "Sikertelen összehasonlítás" << std::endl;

    std::cout << "\toperator<< és operator>>:" << std::endl;
        std::stringstream ss;
        myString s10;
        myString s11("Ez egy nagyon hosszú szöveg, meg számok 23424234235");

        std::cout << s11 << std::endl;
        std::cout << "Kiírjuk sstreamre" << std::endl;
        ss << s11;

        std::cout << "Visszaolvassuk és újra kíírjuk" << std::endl;
        ss >> s10;
        std::cout << s10 << std::endl;
}

void Test_2(){
std::cout << "Person osztály tesztje:" << std::endl;

    std::cout << "\tPerson ctor:" << std::endl;
        Person p1("Kis Bela", "Budapest Janos utca 43", "0670 337 28 34", "0670 342 33 53", "bubus");

        if(p1.getName() == "Kis Bela"){
            std::cout << "Helyes név" << std::endl;
        }else std::cout << "Helytelen név" << std::endl;

        if(p1.getAddress() == "Budapest Janos utca 43"){
            std::cout << "Helyes cím" << std::endl;
        }else std::cout << "Helytelen cím" << std::endl;

        if(p1.getNumber() == "0670 337 28 34"){
            std::cout << "Helyes telefonszám" << std::endl;
        }else std::cout << "Helytelen telefonszám" << std::endl;

        if(p1.getPnumber() == "0670 342 33 53"){
            std::cout << "Helyes privátszám" << std::endl;
        }else std::cout << "Helytelen privátszám" << std::endl;

        if(p1.getNickname() == "bubus"){
            std::cout << "Helyes becenév" << std::endl;
        }else std::cout << "Helytelen becenév" << std::endl;

    std::cout << "\toperator==:" << std::endl;
       Person p2("","","","","");
       p2 = p1;

        if(p1 == p2){
            std::cout << "Sikeres összehasonlítás" << std::endl;
        }else std::cout << "Sikertelen összehasonlítás" << std::endl;

     std::cout << "\twrite  metódus:" << std::endl;

        std::cout << "Kiiírjuk a teszt embert" << std::endl;
        p2.write(std::cout);

std::cout << "Institution osztály tesztje: " << std::endl;

    std::cout << "\tInstitution ctor:" << std::endl;
        Institution i1("Snack Fun", "Szekszárd Mag utca 43", "0620 876 12 43", "1234-4567");

        if(i1.getName() == "Snack Fun"){
            std::cout << "Helyes név" << std::endl;
        }else std::cout << "Helytelen név" << std::endl;

        if(i1.getAddress() == "Szekszárd Mag utca 43"){
            std::cout << "Helyes cím" << std::endl;
        }else std::cout << "Helytelen cím" << std::endl;

        if(i1.getNumber() == "0620 876 12 43"){
            std::cout << "Helyes telefonszám" << std::endl;
        }else std::cout << "Helytelen telefonszám" << std::endl;

        if(i1.getHDN() == "1234-4567"){
            std::cout << "Helyes help desk szám" << std::endl;
        }else std::cout << "Helytelen help desk szám" << std::endl;

    std::cout << "\toperator==:" << std::endl;
       Institution i2("","","","");
       i2 = i1;

        if(i1 == i2){
            std::cout << "Sikeres összehasonlítás" << std::endl;
        }else std::cout << "Sikertelen összehasonlítás" << std::endl;

     std::cout << "\twrite  metódus:" << std::endl;

        std::cout << "Kiiírjuk a teszt embert" << std::endl;
        i2.write(std::cout);
}

void Test_3(){
std::cout << "\tPhoneBook osztály tesztje:" << std::endl;

    std::cout << "PhoneBook ctor:" << std::endl;
        std::ifstream in;
        in.open("teszt.txt");
        PhoneBook* b = new PhoneBook(in);

        std::cout << "Létrehoztuk, írjuk is ki:" << std::endl;
        b->write(std::cout);

    std::cout << "add(PhoneBookRecord*):" << std::endl;
        Institution i1("Snack Fun", "Szekszárd Mag utca 43", "0620 876 12 43", "1234-4567");
        Person p1("Kis Bela", "Budapest Janos utca 43", "0670 337 28 34", "0670 342 33 83", "bubus");

        b->add(&i1);
        b->write(std::cout);

        delete b;
        in.close();
}

int main(){
    Test_1();
    Test_2();
    Test_3();
    return 0;
}
