#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include <stdbool.h>
typedef struct{
    struct node *next;
    void *value;
}node;

typedef struct {
    node *head;
    free_function free_func;
}linked_list;


linked_list *create(free_function free_func){
    linked_list *list;
    list = calloc(1,sizeof(list));
    list->head = calloc(1,sizeof(node));
    list->head->next = NULL;
    list->free_func = free_func;

    return list;
}

bool is_empty(const linked_list *list){
    return list->head->next == NULL;
}

