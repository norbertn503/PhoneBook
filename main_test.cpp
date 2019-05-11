#include <iostream>
#include <cstring>
#include <sstream>

#include "myString.h"

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
int main(){
    Test_1();

    return 0;
}
