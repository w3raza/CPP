/*
Celem zadania jest napisanie standardowego kontenera, jakim jest tablica liczb całkowitych. Tablica ta musi mieć rozmiar określany dynamicznie podczas działania programu i zawiera elementy klasy MyInt, w której przeładowane są operatory new[] i delete[]. Operatory te są głośne, a dzięki konstruktorowi klasy zawartość jest wypełniana szczęśliwymi siódemkami :).
Klasa MyArray wykorzystuje te operatory do tworzenia dynamicznych tablic, a ponadto zawiera zestaw konstruktorów, operatorów i destruktor, zgodnie z regułą  rule of five.
Brak dynamicznej alokacji pamięci (korzystanie z kontenerów biblioteki standardowej) jest oceniane na 0 punktów!

Proszę zadbać o zarządzanie pamięcią. Powodzenia!
*/

#include "MyArray.h"
#include "MyInt.h"
#include <iostream>

/**
 * @brief Funkcja wypisująca tablicę w postaci: nazwa = zawartość
 * 
 * @param s - nazwa tablicy
 * @param arr - zawartość tablicy.
 */
void print(std::string &&s, MyArray& arr) {
  std::cout << s << " = " << arr << std::endl;
}

int main() 
{
    std::cout << "Operatory new[] i delete[]" << std::endl;
    MyInt *tabInt = new MyInt[4]; //przeładowanie operatora new[]
    tabInt[1].value() = 5; 
    for(int i = 0; i< 4; ++i)
        std::cout << tabInt[i] << " ";
    std::cout << std::endl;
    delete[] tabInt;  //przeładowanie operatora delete[]

    //-------------------------------------------
    std::cout << "\nTablica liczb calkowitych" << std::endl;
    MyArray arr(6); // 6 - rozmiar
    std::cout << "arr = " << arr << std::endl;
    for(int i = 0; i<arr.size(); ++i)
        arr[i] = i;
    for(int i = 0; i< arr.size(); ++i)
        std::cout << arr[i] << " ";
   
    //-------------------------------------------
    std::cout << "\n\nKonstruktor kopiujacy i inkrementacja" << std::endl;
    const MyArray arr_cp = arr;
    std::cout << "arr_cp = " << arr_cp << std::endl;
    std::cout << arr++ << std::endl;
    std::cout << arr << std::endl;
    arr[4] = 55;
    std::cout <<  "arr[4] = " << arr[4] << ", " << 
                 "arr_cp[4] = " << arr_cp[10] << std::endl; //to samo co arr_cp[4], indeksujemy cyklicznie
        
    //-------------------------------------------
    std::cout << "\nKonstruktor przenoszacy" << std::endl;
    print("arr",arr);
    MyArray arr_mv = std::move(arr);
    print("arr",arr);
    print("arr_mv",arr_mv);
    
    //-------------------------------------------
    std::cout << "\nOperatory przypisania" << std::endl;
    // MyArray arr2(4);
    // print("arr2", arr2);
    arr = arr = arr_mv;
    print("arr", arr);
    MyArray arr2_mv;
    arr2_mv = std::move(arr_mv);
    print("arr2_mv",arr2_mv);
    //-------------------------------------------
    std::cout << "\nDestruktory" << std::endl;
}

/* Oczekiwany wynik ./main

Operatory new[] i delete[]
--- NEW[] --- rozmiar = 4  sizeof = 24
7 5 7 7 
--- DELETE[] --- rozmiar = 4

Tablica liczb calkowitych
--- NEW[] --- rozmiar = 6  sizeof = 32
arr = [7, 7, 7, 7, 7, 7]
0 1 2 3 4 5 

Konstruktor kopiujacy i inkrementacja
--- NEW[] --- rozmiar = 6  sizeof = 32
arr_cp = [0, 1, 2, 3, 4, 5]
--- NEW[] --- rozmiar = 6  sizeof = 32
[0, 1, 2, 3, 4, 5]
--- DELETE[] --- rozmiar = 6
[1, 2, 3, 4, 5, 6]
arr[4] = 55, arr_cp[4] = 4

Konstruktor przenoszacy
arr = [1, 2, 3, 4, 55, 6]
arr = []
arr_mv = [1, 2, 3, 4, 55, 6]

Operatory przypisania
--- NEW[] --- rozmiar = 6  sizeof = 32
arr = [1, 2, 3, 4, 55, 6]
arr2_mv = [1, 2, 3, 4, 55, 6]

Destruktory
--- DELETE[] --- rozmiar = 6
--- DELETE[] --- rozmiar = 6
--- DELETE[] --- rozmiar = 6

*/
