/*
Zadanie służy przetestowaniu konstruktorów kopiujących i przenoszących oraz operatora = w dziedziczeniu.
Należy uzupełnić kod klasy Virus o mutację w konstruktorze kopiującym i zaimplementować dodatkowo klasę:
* AnimalVirus (animalvirus.h) - klasa pochodna klasy Virus, implementująca wirusy przenoszone przez zwierzęta. 
  Dodatkową cechą klasy AnimalVirus jest:
  - nazwa zwierzęcia, które jest hostem wirusa.
  Niektóre konstruktory w klasie AnimalVirus mogłyby być niepotrzebne, ale z uwagi na edukacyjny charakter są potrzebne do uzyskania prawidłowego outputu.
Uwaga:
Za brak zastosowania reguły five zostaną odjęte 2 punkty.
Wskazówka:
Do łączenia stringów proszę zastosować operator +, 
a do zmiany int na string std::to_string
*  
*/

#include <iostream>

#include "rna.h"
#include "dna.h"
#include "virus.h"
#include "animalvirus.h"

using namespace std;

/// Funkcja pomocnicza, do sprawdzania konstruktora przenoszącego.
template<class T> T my_copy(T a) {
	return a; }

//----------------------------------------------------
int main() {
	// tworzymy dwie sekwencje genów
	RNA rna1( vector<Nukleotyp>({A,C,A,T,A,G,A,C,T,A,G,T,C,A,T}) );
	RNA rna2( vector<Nukleotyp>({C,A,T,C,C,A,G,A,G,T,A,C,T,C,A}) );
	cout << "RNA1: " << rna1 << "RNA2: " <<rna2;
	// mutujemy RNA - przesuwamy rotacyjnie w lewo
	cout << "MUTATED RNA2: " << rna2.mutate();
	
	// tworzymy kod DNA
	DNA kodDNA(rna1,rna2);
	cout << kodDNA << endl;
	
	// tworzymy nowego wirusa (z pustą informacją o kodzie RNA)
	Virus vir1("RSV");
	cout << "Wirus: " << vir1.get_name() << " " << vir1.get_RNA() << endl;
	// dodajemy sekwencję RNA
	vir1.set_RNA(vector<Nukleotyp>({A,C,U,A,G,G,U,A,U,G,A}));	
	cout << "RNA: " << *vir1.get_RNA() << endl;

	// reprodukcja i zliczanie pokoleń wirusów (my_copy jest moje)
	// trzeba podefiniować odpowiednie konstruktory i op =
	// nie zapomnieć o mutacji
	Virus vir2= Virus(my_copy(vir1));  // z mutacją
	Virus vir3;
	vir3 = vir1;  					// bez mutacji
	Virus vir4(my_copy(vir2));  	// z mutacją
	cout << "Pokolenia: " << endl;	//0 1 2
	cout << "Vir1: " << vir1.get_name() << "\tWiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir2: " << vir2.get_name() << "\tWiek: " << vir2.get_age() << "  RNA: " << *vir2.get_RNA();
	cout << "Vir3: " << vir3.get_name() << "\tWiek: " << vir3.get_age() << "  RNA: " << *vir3.get_RNA();
	cout << "Vir4: " << vir4.get_name() << "\tWiek: " << vir4.get_age() << "  RNA: " << *vir4.get_RNA() << endl;;

	Virus vir5 = Virus(std::move(vir1)); //z mutacją
	cout << "Pokolenia:" << endl;	
	cout << "Vir1: " << vir1.get_name() << "\tWiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir5: " << vir5.get_name() << "\tWiek: " << vir5.get_age() << "  RNA: " << *vir5.get_RNA();
	vir5 = std::move(vir2); //z mutacją
	Virus vir6;
	vir6 = vir6; //bez mutacji
	vir6 = Virus(my_copy(vir5));  //z mutacją
	cout << "Vir5: " << vir5.get_name() << "\tWiek: " << vir5.get_age() << "  RNA: " << *vir5.get_RNA();
	cout << "Vir6: " << vir6.get_name() << "\tWiek: " << vir6.get_age() << "  RNA: " << *vir6.get_RNA() << endl;

	// tworzymy nowego wirusa przenoszonego przez zwierzęta, 
	// podając nazwę wirusa, nazwę zwierzęcia, od którego pochodzi oraz kod RNA
	AnimalVirus avir("Koronawirus","nietoperz", rna1.get_RNA());
	cout << "Wirus: " <<avir.get_name() << endl;
	cout << "Nosiciel: " << avir.get_animal_host() << endl;
	cout << "RNA: " << *avir.get_RNA()<<endl;

	AnimalVirus avir1("Chikungunya","komar",vector<Nukleotyp>({U,C,A,A,U,C,C,U,C,A,U,C,A}));
	cout << "Wirus: " << avir1.get_name() << endl;
	cout << "Nosiciel: " << avir1.get_animal_host() << endl;
	cout << "RNA: " << *avir1.get_RNA();
	
	avir1 = my_copy(avir);	// z mutacją

	cout << "---------------\n";
	AnimalVirus avir2 =  AnimalVirus() = AnimalVirus(std::move(avir1));   // z mutacją = AnimalVirus(my_copy (avir1))
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	cout << "---------------\n";
	AnimalVirus avir3(avir1);	//bez mutacji
	cout << "Wirus: " << avir2.get_name() << endl;
	cout << "Nosiciel: " << avir2.get_animal_host() << endl;
	cout << "Pokolenia: " << endl;
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	cout << "AVir2 - Wiek: " << avir2.get_age() << "  RNA: " << *avir2.get_RNA();
	cout << "AVir3 - Wiek: " << avir3.get_age() << "  RNA: " << *avir3.get_RNA() << endl;
return 0;
}
// =======================================================================

/* *** Oczekiwany wynik
RNA1: A C A T A G A C T A G T C A T 
RNA2: C A T C C A G A G T A C T C A
MUTATED RNA2: A T C C A G A G T A C T C A C
A C A T A G A C T A G T C A T
| | | | | | | | | | | | | | |
A T C C A G A G T A C T C A C

Wirus: RSV 0
RNA: A C U A G G U A U G A

Pokolenia:
Vir1: RSV       Wiek: 2  RNA: A C U A G G U A U G A      
Vir2: RSV-1     Wiek: 1  RNA: C U A G G U A U G A A      
Vir3: RSV       Wiek: 0  RNA: A C U A G G U A U G A      
Vir4: RSV-1-1   Wiek: 0  RNA: U A G G U A U G A A C      

Pokolenia:
Vir1: RSV       Wiek: 3  RNA: A C U A G G U A U G A      
Vir5: RSV-3     Wiek: 0  RNA: C U A G G U A U G A A      
Vir5: RSV-1     Wiek: 1  RNA: C U A G G U A U G A A      
Vir6: RSV-1-1   Wiek: 0  RNA: U A G G U A U G A A C      

Wirus: Koronawirus
Nosiciel: nietoperz
RNA: A C A T A G A C T A G T C A T

Wirus: Chikungunya
Nosiciel: komar
RNA: U C A A U C C U C A U C A
nietoperz replikacja -> Koronawirus Wiek: 1
nietoperz mutacja -> Koronawirus-1 Wiek: 1
nietoperz mutacja= -> Koronawirus-1 Wiek: 1
---------------
nietoperz mutacja -> Koronawirus-1-1 Wiek: 1
nietoperz mutacja= -> Koronawirus-1-1 Wiek: 1
nietoperz replikacja -> Koronawirus-1-1 Wiek: 1
AVir1 - Wiek: 1  RNA: C A T A G A C T A G T C A T A      
---------------
nietoperz replikacja -> Koronawirus-1 Wiek: 2
Wirus: Koronawirus-1-1
Nosiciel: nietoperz
Pokolenia:
AVir1 - Wiek: 2  RNA: C A T A G A C T A G T C A T A      
AVir2 - Wiek: 0  RNA: A T A G A C T A G T C A T A C      
AVir3 - Wiek: 0  RNA: C A T A G A C T A G T C A T A  

*/
