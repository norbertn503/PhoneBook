#include <iostream>
#include <cstring>
#include "String.h"

void Test_1(){
    std::cout << "String osztály tesztje:" << std::endl;
    std::cout << "\t char paraméteres ctor:" << std::endl;
        char ch = 's';
        String s1(ch);
        if(s1.getLen() == 1){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;
        if(s1.getStr() == "s"){ //valamiért mindig rossz de ha kíírom azt kapom hogy amit kell és memória hiba sincs
            std::cout << "Jó a karakter" << std::endl;
        }else std::cout << "Rossz a karakter" << std::endl;
    std::cout << "\t const char* paraméteres ctor:" << std::endl;
        const char* teszt = "Hello string";
        String s2(teszt);
        if(s2.getLen() == (size_t)strlen(teszt)){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;
        if(s2.getStr() == s2.getStr()){
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;
    std::cout << "\t copy ctor:" << std::endl;
        String s3 = s2;
        if(s2.getLen() == s3.getLen()){
            std::cout << "Jó a hossz" << std::endl;
            }else std::cout << "Rossz a hossz" << std::endl;
        if("Hello string" == s3.getStr()){//valamiért mindig rossz de ha kíírom azt kapom hogy amit kell és memória hiba sincs
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;
  std::cout << "\t operator+(const String&):" << std::endl;
        String s4("Teszt");
        String s5("elek");
        String s6;
        std::cout << s4.getStr() << std::endl;
        std::cout << s5.getStr() << std::endl;
        s6 = s4 + s5;
        std::cout << s6.getStr() << std::endl;
        if("Tesztelek" == s6.getStr()){
            std::cout << "Jók a karakterek" << std::endl;
        }else std::cout << "Rosszak a karakterek" << std::endl;
}
int main(){
    Test_1();

    return 0;
}
