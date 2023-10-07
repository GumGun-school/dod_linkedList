#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node{
    void *ptr;
    //int32_t value;
    struct node *next;
};

typedef struct list{
    struct node *next;
    uint64_t size;
} linkedList;

uint64_t LL_size(struct list *container);

struct list* LL_create();

uint8_t LL_insert(struct list *container, int64_t index, void *ptr);

uint8_t LL_enqueue(struct list *container, void *ptr);

uint8_t LL_delete(struct list *container, int64_t index);

uint8_t LL_delteList(struct list *container);

uint8_t LL_editNode(struct list *container, int64_t index, void *ptr);

int32_t LL_get(struct list *container, int64_t index);

void bdg_print(struct list *container);

