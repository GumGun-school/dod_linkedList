#include "linkedlist.h"


int main() {
    linkedList *dataStruct;
    dataStruct = LL_create();
    bdg_print(dataStruct);
    LL_enqueue(dataStruct, (void*)1);
    LL_enqueue(dataStruct, (void*)3);
    LL_enqueue(dataStruct, (void*)4);
    LL_enqueue(dataStruct, (void*)5);
    LL_enqueue(dataStruct, (void*)6);
    LL_enqueue(dataStruct, (void*)7);
    bdg_print(dataStruct);
    
    /*
    LL_insert(dataStruct, NULL);
    LL_insert(dataStruct, NULL);
    */
    return 0;
}
