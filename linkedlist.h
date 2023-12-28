
#pragma once
#include <stdlib.h>
#include"circle.h"
#ifndef DATA_TYPE
    #define DATA_TYPE Circles
#endif

typedef struct Node {
    struct Node* pPrev;
    struct Circles* pData;
    struct Node* pNext;
}Node;

typedef struct List {

    Node* pHead;
    Node* pTail;
    int size;
}List;

typedef struct Iterator {
    List* pIteratedList;
    Node* pCurrentNode;
}Iterator;


void Listrmv(List* pList);
void Listadd(List* pList, DATA_TYPE* pData);
List* ListCreate();

Iterator* IteratorCreate(List* pList);
int IteratorNext(Iterator* pIterator);
int IteratorPrevious(Iterator* pIterator);
DATA_TYPE* IteratorGet(Iterator* pIterator);