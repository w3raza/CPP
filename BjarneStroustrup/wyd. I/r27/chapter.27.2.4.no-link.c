/*
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.2.4 „WskaŸniki na funkcje” ksi¹¿ki
// „Programming -- Principles and Practice Using C++” Bjarne'a Stroustrupa
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
    /* Rysuje jako ko³o */
    break;
case rectangle:
    /* Rysuje jako prostok¹t */
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
