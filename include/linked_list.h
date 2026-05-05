#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//singly linked list
Node* initList(Node* list);
Node* createnewNode(int value);
Node* insertBeginning(Node* list, int value);
Node* insertEnd(Node* list, int value);
Node* insertAtPosition(Node* list, int pos, int value);
Node* deleteEnd(Node* list);
Node* deleteBeginning(Node* list);
Node* deleteByValue(Node* list, int value);
Node* searchValue(Node* list, int value);
Node* reverseList(Node* list);
void sortListBubble(Node* list);
Node* mergeSortedLists(Node* a, Node* b, Node* list);
void displayList(Node* list);


//doublly linked list
void displayBackward(DNode* list);
void displayForward(DNode* list);
int deleteByValueDLL(DNode** list, int value);
int insertEndDLL(DNode* list, int value);
int insertBeginningDLL(DNode** list, int value);
void initListDLL(DNode** list);



