#define HOME
#include "mystring.h"
#include <iostream>
#ifdef HOME
	#include "strequal.h"
#endif

using namespace mystring;

int main() {
	String s0("Swieta tuz tuz.");  
	String s1("Swieta tuz tuz");
	const String s2(s0);  

	s0.print("S0: "); s1.print("S1: "); s2.print("S2: "); 
	std::cout << "\n*** Porownywanie napisow ***" << std::endl;
	std::cout << "Napisy s0 i s2 " << (s0 == s2 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	std::cout << "Napisy s2 i s1 " << (s2 == s1 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	std::cout << "Napisy s2 i \"Swieta tuz tuz.\" " << (s2 == "Swieta tuz tuz." ? "sa identyczne" :"nie sa identyczne") << std::endl;
	
	std::cout << "\n*** Dodawanie i przypisywanie napisow ***" <<  std::endl;
	s2.print("S2: :");
	s1 = "Duzo zdrowia i szczescia!!!";
	std::cout << "S1: " << s1 << std::endl;
	String s3 = s2 + " Tu i teraz...";
	s3.print("S3: " );
	String s4 = s2 + ".. " + s1 + "\n\t" + s3;// + '!'; // uwaga na typ char
	s4.print("S4: " );
	
	std::cout << "\n*** Powielanie napisow ***" << std::endl;
  	String s5 = 2 * String(":-)");
  	s5.print("S5: ");
  	String s6 = 4 * s5 + ":-D ";
	s6.print("S6: " );
	String const s7 = std::move(s1);
  	std::cout << "S7: "<< s7 << std::endl; 
 	s1.print("S1: ");

#ifdef HOME
   const StrEqual seq(s2); 
   std::cout << "Napisy s2 i s0 " << (seq(s0) ? "sa identyczne" :"nie sa identyczne") << std::endl;
   std::cout << "Napisy s2 i s1 " << (seq(s1) ? "sa identyczne" :"nie sa identyczne") << std::endl;
#endif
}

/* Oczekiwany wynik ./main
S0: Swieta tuz tuz.
S1: Swieta tuz tuz
S2: Swieta tuz tuz.

*** Porownywanie napisow ***
Napisy s0 i s2 sa identyczne
Napisy s2 i s1 nie sa identyczne
Napisy s2 i "Swieta tuz tuz." sa identyczne

*** Dodawanie i przypisywanie napisow ***
S2: Swieta tuz tuz.
S1: Duzo zdrowia i szczescia!!!
S3: Swieta tuz tuz. Tu i teraz...
S4: Swieta tuz tuz... Duzo zdrowia i szczescia!!!
    Swieta tuz tuz. Tu i teraz...!

*** Powielanie napisow ***
S5: :-):-)
S6: :-):-):-):-):-):-):-):-):-D 
S7: Duzo zdrowia i szczescia!!!
S1: 
*/
