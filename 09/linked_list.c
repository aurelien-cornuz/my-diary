#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


void linked_list_init(LinkedList *list){

    list->head = NULL; 
    list->tail = NULL; 

}
void linked_list_push_back(LinkedList *list, int *value){

    if(list->head == NULL){

    }else{
        Node *node = malloc(sizeof(Node));
        if(node == NULL) abort(); 
    }

}