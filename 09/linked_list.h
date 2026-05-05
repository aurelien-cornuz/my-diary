#pragma once

#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct linked_list
{
    Node *head;
    Node *tail;
} LinkedList;

void linked_list_init(LinkedList *list);
void linked_list_push_back(LinkedList *list, int *value);
