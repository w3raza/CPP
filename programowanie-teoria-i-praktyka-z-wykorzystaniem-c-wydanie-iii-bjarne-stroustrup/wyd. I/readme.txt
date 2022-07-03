Kompilowanie przyk�ad�w

  Windows

   Je�li masz w swoim komputerze Microsoft Visual C++ w wersji 7.1, 8.0 lub 9.0, wystarczy uruchomi� plik  build.bat  z poziomu wiersza polece�. Spowoduje to skompilowanie wszystkich plik�w z wszystkich rozdzia��w przy u�yciu najnowszej zainstalowanej wersji MSVC. Je�li masz zainstlowanych kilka wersji Visual C++ i chcesz wykona� kompilacj� za pomoc� wybranej wersji, przeka� podczas uruchamiania pliku build.bat jeden z nast�puj�cych argument�w:  msvc71, msvc80, msvc90; np.:        
           build.bat msvc71
Aby oczy�ci� wszystkie skompilowane przyk�ady, wpisz polecenie:    
        build.bat clean
        
Aby skompilowa� jeden przyk�ad lub kilka przyk�ad�w, przeka� w argumentach nazwy plik�w wykonywalnych, kt�re maj� zosta� utworzone. Na przyk�ad:
        build chapter.12.3.exe chapter.12.7.7.exe
Je�li masz zainstalowany kompilator GNU C++, mo�esz skompilowa� wszystkie przyk�ady za pomoc� pliku Makefile (opis poni�ej).
  Unix
Ka�dy rozdzia� zawiera w�asny plik Makefile, kt�ry mo�na uruchomi� niezale�nie od innych. Aby skompilowa� przyk�adowe programy z wszystkich rozdzia��w, nale�y napisa� nast�puj�ce polecenie    
        make 
w odpowiednim katalogu. Wszystkie pliki Makefile powinny dzia�a� w systemach Uniksowych i Windows pod Cygwin. W tym drugim przypadku wymagane jest, aby pliki wykonywalne mia�y rozszerzenie .exe, dlatego pliki Makefile generuj� pliki z tym rozszerzeniem. Oznacza to r�wnie�, �e je�li zechcesz skompilowa� tylko wybrane pliki, musisz poda� nazwy plik�w docelowych z rozszerzeniem .exe, np.:
 make chapter.12.3.exe chapter.12.7.7.exe
Wymagania
FLTK
Kopia biblioteki FLTK zosta�a do��czona do tego archiwum. Trzeba j� przed u�yciem skompilowa�, post�puj�c zgodnie ze wskaz�wkami jej tw�rc�w. Uwaga: je�li masz FLTK w wersji 2 lub wy�szej, nie b�dziesz m�g� skompilowa� tych przyk�ad�w. U�yj starszej wersji, kt�ra znajduje si� w tym archiwum.
�r�d�a FLTK s� wyszukiwane w �cie�ce podanej w zmiennej �rodowiskowej FLTK. Je�li nie ma takiej zmiennej, spr�bujemy u�y� lokalnej kopii z tego archiwum. Je�li np. biblioteka FLTK zosta�a zainstalowana w domy�lnym katalogu /usr/local, to jej nag��wki zosta�y umieszczone w katalogu /usr/local/include, a wi�c nale�y utworzy� FLTK=/usr/local/include.

  Boost
W przyk�adach w rozdziale 23 u�yto biblioteki boost/regex, co oznacza, �e do ich uruchomienia potrzebne jest zainstalowanie biblioteki boost. Mo�na j� pobra� pod adresem http://www.boost.org/.
Wymagane jest utworzenie zmiennej �rodowiskowej BOOST zawieraj�cej �cie�k� do tej biblioteki.
Konwencje
W niekt�rych nazwach plik�w u�yto pewnych przyrostk�w oznaczaj�cych okre�lone w�a�ciwo�ci tych plik�w lub skrypt�w:
 - *.no-link.cpp: te pliki nie powinny by� poddawane konsolidacji po skompilowaniu, poniewa� nie udost�pniaj� punktu wej�cia do aplikacji.
 - *.crash.cpp: te pliki zawieraj� niezdefiniowane zachowania w C++. Ich opis mo�na znale�� w odpowiednich rozdzia�ach ksi��ki. Uruchamianie tych plik�w mo�e zako�czy� si� niepowodzeniem.
Pomoc i komentarze
Strona ksi��ki znajduje si� pod adresem http://www.stroustrup.com/Programming/.
Wszelkie komentarze prosz� przysy�a� na adres e-mail bs@cs.tamu.edu.
