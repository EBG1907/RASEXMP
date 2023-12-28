#pragma once
#include <stdio.h>
#include <stdlib.h>
#include"circle.h"
#include"linkedlist.h"

//create a list consisting of pointers of Circle structures
 List* ListCreate() {
     
     
     List* Listptr =malloc(sizeof(List));
     
     Listptr->pHead = NULL;
     Listptr->pTail = NULL;
     Listptr->size = 0;
     return Listptr;
}
 //adding circle pointer to end of the list
 
 
 void Listadd(List* pList,Circles* pData) {

     Node* newNode =malloc(sizeof(Node));
     
     if (pList->pHead == NULL) {
         pList->pHead = newNode;
         pList->pTail = newNode;
         newNode->pData = pData;
         newNode->pPrev = newNode;
         newNode->pNext = newNode;
     }
     else {
         newNode->pNext = pList->pHead;
         newNode->pPrev = pList->pTail;
         newNode->pData = pData;
         
         pList->pHead->pPrev = newNode;
         pList->pTail->pNext = newNode;
         pList->pTail = newNode;
     }

     pList->size+=1;
 }
 //removing from the end of the list
 void Listrmv(List* pList) {

     if (pList == NULL || pList->pHead == NULL) {
         return;
     }
     Node* temp = pList->pTail;

     if (pList->pHead == pList->pTail) {
         pList->pHead = NULL;
         pList->pTail = NULL;
     }
     else {
         pList->pHead->pPrev = pList->pTail->pPrev;
         pList->pTail->pPrev->pNext = pList->pHead;
         pList->pTail = pList->pTail->pPrev;
     }
     free(temp);
     pList->size--;
 }

 Iterator* IteratorCreate(List* pList) {
     Iterator* iterator = malloc(sizeof(Iterator));
     if (pList->pHead != NULL) {
         
         iterator->pIteratedList = pList;
         
         iterator->pCurrentNode = iterator->pIteratedList->pHead;
     }
     return iterator;

 }

 
 int IteratorNext(Iterator * pIterator) {
         if (pIterator == NULL || pIterator->pCurrentNode == NULL) {
             return 0;
         }
         if (pIterator->pCurrentNode->pNext != NULL) {
             pIterator->pCurrentNode = pIterator->pCurrentNode->pNext;
             return 1; 
         }
         return 0; 
     }
 
 
 
 int IteratorPrevious(Iterator* pIterator) {
     if (pIterator == NULL || pIterator->pCurrentNode == NULL) {
         return 0;
     }

     if (pIterator->pCurrentNode->pPrev != NULL) {
         pIterator->pCurrentNode = pIterator->pCurrentNode->pPrev;
         return 1;
     }

     return 0;
 }

 Circles* Iteratorgets(Iterator* pIterator) {

     if (pIterator == NULL || pIterator->pCurrentNode == NULL) {
         return NULL; 
     }

     return pIterator->pCurrentNode->pData;
 }






 



 














































/*
Node* head = NULL;














void add(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void printing() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void clean() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

*/

