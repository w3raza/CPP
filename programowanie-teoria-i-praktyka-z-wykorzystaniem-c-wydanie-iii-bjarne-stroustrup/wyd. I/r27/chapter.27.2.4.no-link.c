/*
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.2.4 �Wska�niki na funkcje� ksi��ki
// �Programming -- Principles and Practice Using C++� Bjarne'a Stroustrupa
//
*/

/*----------------------------------------------------------------------------*/

struct Shape1 {
    enum Kind { circle, rectangle } kind;
    /* ... */
};

/*----------------------------------------------------------------------------*/

void draw(struct Shape1* p)
{
    switch (p->kind) {
case circle:
    /* Rysuje jako ko�o */
    break;
case rectangle:
    /* Rysuje jako prostok�t */
    break;
    }
}

/*----------------------------------------------------------------------------*/

int f(struct Shape1* pp)
{
    draw(pp);
    /* ... */
}

/*----------------------------------------------------------------------------*/

typedef void (*Pfct0)(struct Shape2*); 
typedef void (*Pfct1int)(struct Shape2*,int);

/*----------------------------------------------------------------------------*/

struct Shape2 {
    Pfct0 draw;
    Pfct1int rotate;
    /* ... */
};

/*----------------------------------------------------------------------------*/

void draw1(struct Shape2* p)
{
    (p->draw)(p);
}

/*----------------------------------------------------------------------------*/

void rotate(struct Shape2* p)
{
    (p->rotate)(p,90);
}

/*----------------------------------------------------------------------------*/

int f1(struct Shape * pp)
{
    draw(pp);
    /* ... */
}

/*----------------------------------------------------------------------------*/
