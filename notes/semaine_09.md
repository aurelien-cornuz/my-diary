# NOTE du journal de cours semaine 9

## PUSH_BACK 
 rajoute un élément a la fin du tableau 
## PUSH_FRONT 
 rajoutre un élément au début du tableau
## POP_BACK 
 enlever un élément a la fin du tableau ¨
## POP_FRONT
 enlever un élément au début du tableau 

## INDEX
revient a faire a[3] 

## INSERT 
rajout un élement ( au début, millieu, fin etc...)

## DELETE
supprimer un élément (au début, millieu, fin etc...)

# BLIBLIO DE TABLEAU DYNAMIQUE

dans fichier .h toujours commencer avec un **#pragma once** qui est une directive de préprocesseur qui empêche un fichier d'en-tête (.h) d'être inclus plusieurs fois dans le même fichier source lors de la compilation.
```c
#pragma once

typedef struct node {
    int value;
    struct node *next;
} Node; 

typedef struct linked_list [
    Node *head;
    Node *tail; 
] linkedList; 

void linked_list_init(LinkedList *list); 
void linked_list_push_back(Linked *list, int *value);
void linked_list_push_front(Linked *list, int *value);
void linked_list_get(Linked *list, size_t index, int *value)
void linked_list_push_back(Linked *list, Node *node, int *value) // Node *node adresse a laquelle se trouve un élement. 
