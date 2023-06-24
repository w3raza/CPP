
/**
  Polimorfizm i dziedziczenie wielokrotne na przykładzie rysowania kształtów.
  
  Dane są klasy reprezentujące kształty takie jak prostokąt i koło.
  Prostokąt (Rectangle) opisany jest przez dwa punkty, natomiast koło (Circle) przez promień i środek koła. 
  Jest jeszcze klasa  (shapeComposite) stanowiąca kompozycję kształtów na zasadzie sumy,
  iloczynu albo różnicy dwóch figur, zawierająca wskaźniki shared_ptr<Shape> oraz klasę enum z wartościami {INTERSECTION, SUM, DIFFERENCE}.

  Wszystkie te klasy te posiadają funkcję isIt zwracającą, czy podany punkt znajduje się w obrębie figury, dzięki czemu mozna ją narysować.
  Aby sprawdzić, czy punkt należy do koła, odległość punktu od środka powinna być mniejsza lub równa promieniowi, z prostokatem sobie poradzicie. 
  Ponadto klasy Circle i Rectangle należą do grupy figur podstawowych (BasicShape), dla których istnieje zdefiniowany wzór na pole figury (dla prostokąta (x2-x1)*(y2-y1))
  Natomiast klasa Rectangle należy do grupy wielokątów mających przekątne (funkcja diagonal).
  UWAGA!
  Dla ułatwienia rysowania kształtów wszystkie współrzędne oraz promień są typu int/unsigned.
  Klasa i funkcja rysująca jest już zdefiniowana przeze mnie, rysuje figury tylko w I ćwiarce układu współrzędnych.
  Struktura plików została już utworzona, proszę uważnie czytać komentarze w środku.
  Prosze pamiętać o const i override.
**/

#include <iostream>
#include <memory>
#include <cmath>
#include "shapes.h"
#include "stage.h"
#include "circle.h"
#include "rectangle.h"
#include "shapeComposite.h"

#ifndef M_PI
    constexpr double M_PI = 3.1415926;
#endif

using std::cout;
using std::endl;

/// @brief funkcja wykorzystywana do rysowania
void printShape(const Shape* shape, size_t width, size_t heigh)
{
        const Stage stage(width, heigh);
        stage.drawShape(shape, std::cout); ///definiujemy obszar i figurę do narysowania
}

int main()
{
    cout << "=== RYSUJEMY PROSTOKAT ===" << endl;
    int xFrom = 0, yFrom = 0, xTo = 6, yTo = 4;
    const Point from(0,0), to(4,3);
    const Rectangle rectangle(from.x(), from.y(), xTo, yTo);
    const Rectangle rectangle2(from, to);
    cout << "Area = " << rectangle2. area() << std::endl;
    cout << "Diagonal = " << rectangle2.diagonal() << std::endl;
    cout << std::boolalpha 
      << rectangle.isIn(1, 3) << endl //true
      << rectangle.isIn(0, 0) << endl //true
      << rectangle.isIn(6, 4) << endl //true
      << rectangle.isIn(1, 7)<< endl //false
      << rectangle.isIn(7, 6)<< endl //false
      << rectangle.isIn(-1, 5)<< endl; //false
    printShape(&rectangle2, 4, 3);
   
    cout << "=== RYSUJEMY KOLO ===" << endl;
    const Point center(xFrom +(xTo-xFrom)/2, yTo);
    auto radius = (xTo - xFrom)/2;
    const Circle circle(center.x(), center.y(), radius);
    cout << "Area = " << circle. area() << std::endl;
    cout << std::boolalpha 
      << circle.isIn(4,0) << endl //false
      << circle.isIn(3,1) << endl //true
      << circle.isIn(6,4) << endl; //true
    printShape(&circle, xTo, yTo + radius);

    /// zabawa z klasą shapeComposite powstałej jako suma, różnica albo iloczyn figur
    cout << "=== RYSUJEMY PROSTOKAT + KOLO ===" << endl;
    std::shared_ptr<Rectangle> prectangle = std::make_shared<Rectangle>(rectangle);
    std::shared_ptr<const Shape> composite1(new ShapeComposite(prectangle, std::make_shared<const Circle>(circle), ShapeOperation::SUM));
    printShape(composite1.get(), xTo, yTo+radius);
    cout << "=== RYSUJEMY PROSTOKAT * KOLO ===" << endl;
    std::shared_ptr<Shape> composite2(new ShapeComposite(prectangle, std::make_shared<Circle>(circle), ShapeOperation::INTERSECTION));
    printShape(composite2.get(), xTo, yTo+radius-2);
    cout << "=== RYSUJEMY PROSTOKAT - KOLO ===" << endl;
    ShapeComposite composite3(ShapeComposite(prectangle, std::make_shared<Circle>(circle), ShapeOperation::DIFFERENCE));
    printShape(&composite3, xTo, yTo+radius-3);

    cout << "=== SPRAWDZAMY DZIEDZICZENIE ===" << endl;
    unsigned numObj = 4;
	  const Shape *list[]{prectangle.get(), new Circle(center, 3), composite1.get(), &composite3};
	  for (unsigned i = 0; i < numObj; ++i){
		  std::cout << "*** Obiekt " << i+1 << " ***\n";
      // printShape(list[i], xTo, yTo+radius); //można go wydrukować
    /// tylko dla Circle i Rectangle możemy obliczyć pole ze wzoru
      const BasicShape* closed = dynamic_cast<const BasicShape*>(list[i]);
		  if (closed) std::cout << "Area = " << closed->area() << std::endl;
    /// tylko Rectangle ma przekątną, którą możemy obliczyć
		  const HasDiagonal* diag = dynamic_cast<const HasDiagonal*>(list[i]);
  		if(diag) std::cout << "Diagonal = " << diag->diagonal() << std::endl;
	  }

   /// na koniec trochę zabawy, ta część sama powinna się już narysować
    cout << "=== I NA KONIEC DLA WYTRWALYCH DOMEK ===" << endl;
    std::shared_ptr<Shape> home(new Rectangle(0, 0, 20, 10));
    std::shared_ptr<Shape> roof(new Circle(10, 11, 10));
    std::shared_ptr<Shape> homeWithRoof(new ShapeComposite(home, roof, ShapeOperation::SUM));
    std::shared_ptr<Shape> door(new Rectangle(3, 1, 9, 11));
    std::shared_ptr<Shape> homeWithDoor(new ShapeComposite(homeWithRoof, door, ShapeOperation::DIFFERENCE));
    std::shared_ptr<Shape> window(new Rectangle(13, 7, 17, 11));
    std::shared_ptr<Shape> homeWithDoorAndWindow(new ShapeComposite(homeWithDoor, window, ShapeOperation::DIFFERENCE));
    printShape(homeWithDoorAndWindow.get(), 20, 20);

}

/* wynik ./main
=== RYSUJEMY PROSTOKAT ===
Area = 12
Diagonal = 5
true
true
true
false
false
false
3:      *****
2:      *****
1:      *****
0:      *****
=== RYSUJEMY KOLO ===
Area = 28.2743
false
true
true
7:         *
6:       *****
5:       *****
4:      *******
3:       *****
2:       *****
1:         *
0:
=== RYSUJEMY PROSTOKAT + KOLO ===
7:         *
6:       *****
5:       *****
4:      *******
3:      *******
2:      *******
1:      *******
0:      *******
=== RYSUJEMY PROSTOKAT * KOLO ===
5:
4:      *******
3:       *****
2:       *****
1:         *
0:
=== RYSUJEMY PROSTOKAT - KOLO ===
4:
3:      *     *
2:      *     *
1:      *** ***
0:      *******
=== SPRAWDZAMY DZIEDZICZENIE ===
*** Obiekt 1 ***
Area = 24
Diagonal = 7.2111
*** Obiekt 2 ***
Area = 28.2743
*** Obiekt 3 ***
*** Obiekt 4 ***
=== I NA KONIEC DLA WYTRWALYCH DOMEK ===    
20:           *********
19:         *************
18:        ***************
17:       *****************
16:       *****************
15:      *******************
14:      *******************
13:      *******************
12:      *******************
11:     ***       ***     ***
10:     ***       ***     ***
9:      ***       ***     ***
8:      ***       ***     ***
7:      ***       ***     ***
6:      ***       ***********
5:      ***       ***********
4:      ***       ***********
3:      ***       ***********
2:      ***       ***********
1:      ***       ***********
0:      *********************
*/
