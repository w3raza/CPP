/*
1. Szablon my_for_each jest funkcją ogólnego przeznaczenia, która przyjmuje iterator początku i końca dowolnej kolekcji oraz funkcję, 
którą należy zastosować do każdego elementu kolekcji. 
Iteruje od początku do końca kolekcji, stosując funkcję f do każdego elementu.

2. print to wyrażenie lambda, które przyjmuje jeden argument (liczbę całkowitą) i drukuje go na ekranie.

3. print_eol to wyrażenie lambda, które nie przyjmuje żadnych argumentów i drukuje nową linię.

4. add to wyrażenie lambda, które przyjmuje referencję do liczby całkowitej i dodaje do niej wartość add_value. 
Ponieważ add_value jest używane w wyrażeniu lambda, musi być przechwycone przez referencję w ramach wyrażenia lambda ([&add_value]). 
W przeciwnym razie otrzymalibyśmy kopię add_value w momencie tworzenia wyrażenia lambda, 
a zmiana add_value później nie wpłynęłaby na działanie wyrażenia lambda.
*/
#include <iostream>
#include <functional>

template <typename Iterator, typename Func>
void my_for_each(Iterator start, Iterator end, Func f)
{
    for (auto it = start; it != end; ++it) {
        f(*it);
    }
}

int main() { 
    using namespace std;
    int c[] = {1, 2, 3, 4, 5};

    auto print = [](int i) { cout << i << " "; };
    auto print_eol = []() { cout << endl; };

    my_for_each(begin(c), end(c), print); 
    print_eol();

    int add_value = 1;
    auto add = [&add_value](int& i) { i += add_value; };
    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print); 
    print_eol();

    add_value = 10;
    my_for_each(begin(c), end(c), add);
    my_for_each(begin(c), end(c), print); 
    print_eol();
}

/*
1 2 3 4 5 
2 3 4 5 6 
12 13 14 15 16  
*/

// // Proszę dokończyć program wg. std. C++11, tak aby działał w podany w komentarzu sposob.
// // Prosze dokładnie uzasaednić odpowiedź

// #include <iostream>
// #include <functional>

// template </*Uzupelnij 1*/>
// void my_for_each(/*Uzupelnij 2*/)
// {
//     /*Uzupelnij 3*/
// }

// int main(){ using namespace std;
//     int c[] = {1, 2, 3, 4, 5};

//     auto print = /*Uzupelnij 4*/ ;
//     auto print_eol = /*Uzupelnij 5*/ ;
//     my_for_each(begin(c), end(c), print); print_eol();

//     int add_value = 1;
//     auto add = /*Uzupelnij 6*/ ;
//     my_for_each(begin(c), end(c), add);
//     my_for_each(begin(c), end(c), print); print_eol();

//     add_value = 10;
//     my_for_each(begin(c), end(c), add);
//     my_for_each(begin(c), end(c), print); print_eol();
// }
// /* Wyjście
// 1 2 3 4 5 
// 2 3 4 5 6 
// 12 13 14 15 16  
// */