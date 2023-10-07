#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node* get_last(struct node *first);
struct node* get_n(struct node *first, uint64_t index);


struct list* 
LL_create(){
    struct list* holder;
    holder = malloc(sizeof(struct list));
    if(holder == NULL){
        exit(0);
    }
    holder->size = 0;
    holder->next = NULL;
    
    return holder;
}

uint8_t 
LL_enqueue(struct list *container, void *ptr){
    
    struct node *holder = malloc(sizeof(struct node));
    
    if(holder == NULL){
        exit(1);
    }
    
    holder->next=NULL;
    holder->ptr=ptr;
    
    if(container->next == NULL){
        container->next = holder;
        container->size++;
    }else{
        struct node *pivot = get_last(container->next);
        pivot->next = holder;
        container->size++;
    }
    
    return 0;
}

struct node*
get_last(struct node *first){
    struct node *pivot = first;
    while(pivot->next != NULL){
        pivot = pivot->next;
    }
    return pivot;
}

uint8_t 
LL_insert(struct list *container, int64_t index, void *ptr){
    
    struct node *holder = malloc(sizeof(struct node));
    
    if(holder == NULL){
        exit(1);
    }
    
    holder->next=NULL;
    holder->ptr=ptr;
    
    if(index > container->size){
        return 1;
    }
    
    if(container->next == NULL){
        container->next = holder;
        container->size++;
        
    }else if(index == 0) {
        holder->next = container->next;
        container->next = holder;
        container->size++;
        
    }else{
        struct node *pivot = get_n(container->next, index-1);
        holder->next = pivot->next;
        pivot->next = holder;
        container->size++;
        /*
        struct node *pivot = get_last(container->next);
        pivot->next = holder;
        container->size++;
        */
    }
    
    return 0;
    
}


struct node*
get_n(struct node *first, uint64_t index){
    struct node *pivot = first;
    for(int32_t iter=0; iter<index; iter++){
        pivot = pivot->next;
    }
    return pivot;
}


void 
bdg_print(struct list *container){
    printf("size:  %d\n", container->size);
    printf("first: %p\n", container->next);
}
