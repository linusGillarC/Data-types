#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
typedef struct{
    size_t low;
    size_t  high;
    int array_size;
    void** value;
    free_function free_func
}ArrayList;

ArrayList *init(size_t low, size_t high,free_function free_func){
    ArrayList *list;
    list = calloc(1,sizeof(list));
    list->low = low;
    list->high = high;
    list->array_size = high - low + 1; /// <----??
    list->free_func = free_func;

    list->value = calloc(list->array_size,sizeof(void*));

    if(list->value == NULL){
        free(list);
        list = NULL;
    }

    return list;
}

int arrayList_high(const ArrayList *list){
    return list->high;
}

int arrayList_low(const ArrayList *list){
    return list->low;
}

void *inspect(const ArrayList *list, int i){
    int index = i - list->low;
    return list->value[index];
    
}

