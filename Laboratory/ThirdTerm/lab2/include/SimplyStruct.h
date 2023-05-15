#pragma once
#include <iostream> 

typedef struct TItem{    
    int value;
    TItem *next;
}TItem;

#ifndef SimplyStruct_h
TItem* InitItem();
void push(TItem** head, int value);
int pop(TItem** head);
void clear(TItem** head);
void show(TItem *titem);
#endif
