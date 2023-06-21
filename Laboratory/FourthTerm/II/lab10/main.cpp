/*
 LinkedList, czyli struktura danych, w której elementy danych przechowywane są 
 w postaci węzłów (Node) zawierających dane oraz wskaźnik na następny element w liście,
 znamy już z wczesniejszych zajęć.
 Tym razem zaimplementujemy listę szablonową, oczywiście bez użycia żadnych standardowych kontenerów
 a dodatkowo z inteligentnymi wskaźnikami, a dla urozmaicenia będzie to lista cykliczna, 
 czyli ostatni element wskazuje na pierwszy.
 Dla ułatwienia warto przechowywać dwa wskaźniki na head i tail.
 Metody klasy CircularList mają być zdefiniowane poza klasą.
*/

#include <iostream>
#include "circularList.h" 

// #define EXTENDED

int main() {
    CircularList<int> intList;
    intList.push_front(4);
    intList.push_back(5).push_back(6); 
    intList.push_front(3);
    intList.print();

    CircularList<std::string> stringList;
    stringList.push_back("cytryna").push_front("banan").push_back("mandarynka");
    stringList.push_front("ananas");
    stringList.print();

    CircularList<double> doubleList;
    doubleList.add_sorted(3.14);
    doubleList.add_sorted(2.71);
    doubleList.add_sorted(1.1).add_sorted(2.99);
    doubleList.print();

    CircularList<int> list;
    list.print();

    std::shared_ptr<Node<std::string>> found_node = stringList.find("banan");
    std::cout << "Banan - " << (found_node? "Znaleziono" : "Nie znaleziono") << std::endl;
    std::cout << "Granat - " << (stringList.find("granat")? "Znaleziono" : "Nie znaleziono") << std::endl;
    stringList.add_sorted("granat");
    found_node = stringList.find("granat");
    std::cout << "Granat - " << (found_node ? "Znaleziono" : "Nie znaleziono") << std::endl;
    stringList.print();
    std::cout << stringList.getNext(found_node)->data() << std::endl;
    std::cout << stringList.getNext(stringList.find("mandarynka"))->data() << std::endl;
#ifdef EXTENDED 
    stringList.remove("ananas");
    stringList.remove("mandarynka");
    stringList.print();
    doubleList.remove(1.1);
    doubleList.remove(2.99);
    doubleList.print();        
#endif
    return 0;
}  

/* oczekiwany wynik ./main
3 4 5 6
ananas banan cytryna mandarynka
1.1 2.71 2.99 3.14
Lista pusta
Banan - Znaleziono        
Granat - Nie znaleziono
Granat - Znaleziono
ananas banan cytryna granat mandarynka
mandarynka
ananas
banan cytryna granat
2.71 3.14
*/