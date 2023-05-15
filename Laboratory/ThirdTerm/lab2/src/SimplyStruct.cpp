#ifndef SIMPLYSTRUCT_H
#define SIMPLYSTRUCT_H

#include <iostream>
#include "SimplyStruct.h"

TItem* InitItem() {
    return new TItem();
}

void push(TItem** head, int value) {
    TItem* newItem = InitItem();
    newItem->value = value;
    newItem->next = *head;
    *head = newItem;
}

int pop(TItem** head)
{
    int result = (*head)->value;
    TItem* next = (*head)->next;
    free(*head);
    *head = next;
    return result;
}

void clear(TItem** head) {
    TItem* current = *head;
    while (current != NULL) {
        TItem* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void show(TItem* head) {
    std::cout << "Aktualny stan listy:" << std::endl;
    std::cout << "<";
    while (head != nullptr) {
        std::cout << head->value;
        if (head->next != nullptr) {
            std::cout << ",";
        }
        head = head->next;
    }
    std::cout << ">" << std::endl;
}

#endif /* SIMPLYSTRUCT_H */
