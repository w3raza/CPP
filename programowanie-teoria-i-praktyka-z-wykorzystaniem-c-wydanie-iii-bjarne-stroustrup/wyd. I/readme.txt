Kompilowanie przyk³adów

  Windows

   Jeœli masz w swoim komputerze Microsoft Visual C++ w wersji 7.1, 8.0 lub 9.0, wystarczy uruchomiæ plik  build.bat  z poziomu wiersza poleceñ. Spowoduje to skompilowanie wszystkich plików z wszystkich rozdzia³ów przy u¿yciu najnowszej zainstalowanej wersji MSVC. Jeœli masz zainstlowanych kilka wersji Visual C++ i chcesz wykonaæ kompilacjê za pomoc¹ wybranej wersji, przeka¿ podczas uruchamiania pliku build.bat jeden z nastêpuj¹cych argumentów:  msvc71, msvc80, msvc90; np.:        
           build.bat msvc71
Aby oczyœciæ wszystkie skompilowane przyk³ady, wpisz polecenie:    
        build.bat clean
        
Aby skompilowaæ jeden przyk³ad lub kilka przyk³adów, przeka¿ w argumentach nazwy plików wykonywalnych, które maj¹ zostaæ utworzone. Na przyk³ad:
        build chapter.12.3.exe chapter.12.7.7.exe
Jeœli masz zainstalowany kompilator GNU C++, mo¿esz skompilowaæ wszystkie przyk³ady za pomoc¹ pliku Makefile (opis poni¿ej).
  Unix
Ka¿dy rozdzia³ zawiera w³asny plik Makefile, który mo¿na uruchomiæ niezale¿nie od innych. Aby skompilowaæ przyk³adowe programy z wszystkich rozdzia³ów, nale¿y napisaæ nastêpuj¹ce polecenie    
        make 
w odpowiednim katalogu. Wszystkie pliki Makefile powinny dzia³aæ w systemach Uniksowych i Windows pod Cygwin. W tym drugim przypadku wymagane jest, aby pliki wykonywalne mia³y rozszerzenie .exe, dlatego pliki Makefile generuj¹ pliki z tym rozszerzeniem. Oznacza to równie¿, ¿e jeœli zechcesz skompilowaæ tylko wybrane pliki, musisz podaæ nazwy plików docelowych z rozszerzeniem .exe, np.:
 make chapter.12.3.exe chapter.12.7.7.exe
Wymagania
FLTK
Kopia biblioteki FLTK zosta³a do³¹czona do tego archiwum. Trzeba j¹ przed u¿yciem skompilowaæ, postêpuj¹c zgodnie ze wskazówkami jej twórców. Uwaga: jeœli masz FLTK w wersji 2 lub wy¿szej, nie bêdziesz móg³ skompilowaæ tych przyk³adów. U¿yj starszej wersji, która znajduje siê w tym archiwum.
ród³a FLTK s¹ wyszukiwane w œcie¿ce podanej w zmiennej œrodowiskowej FLTK. Jeœli nie ma takiej zmiennej, spróbujemy u¿yæ lokalnej kopii z tego archiwum. Jeœli np. biblioteka FLTK zosta³a zainstalowana w domyœlnym katalogu /usr/local, to jej nag³ówki zosta³y umieszczone w katalogu /usr/local/include, a wiêc nale¿y utworzyæ FLTK=/usr/local/include.

  Boost
W przyk³adach w rozdziale 23 u¿yto biblioteki boost/regex, co oznacza, ¿e do ich uruchomienia potrzebne jest zainstalowanie biblioteki boost. Mo¿na j¹ pobraæ pod adresem http://www.boost.org/.
Wymagane jest utworzenie zmiennej œrodowiskowej BOOST zawieraj¹cej œcie¿kê do tej biblioteki.
Konwencje
W niektórych nazwach plików u¿yto pewnych przyrostków oznaczaj¹cych okreœlone w³aœciwoœci tych plików lub skryptów:
 - *.no-link.cpp: te pliki nie powinny byæ poddawane konsolidacji po skompilowaniu, poniewa¿ nie udostêpniaj¹ punktu wejœcia do aplikacji.
 - *.crash.cpp: te pliki zawieraj¹ niezdefiniowane zachowania w C++. Ich opis mo¿na znaleŸæ w odpowiednich rozdzia³ach ksi¹¿ki. Uruchamianie tych plików mo¿e zakoñczyæ siê niepowodzeniem.
Pomoc i komentarze
Strona ksi¹¿ki znajduje siê pod adresem http://www.stroustrup.com/Programming/.
Wszelkie komentarze proszê przysy³aæ na adres e-mail bs@cs.tamu.edu.
