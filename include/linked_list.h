#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define Null -1


Node* initList(Node* list);
Node* createnewNode(int value);
Node* insertBeginning(Node* list, int value);
Node* insertEnd(Node* list, int value);
Node* insertAtPosition(Node* list, int pos, int value);
Node* deleteEnd(Node* list);
Node* deleteBeginning(Node* list);
Node* deleteByValue(Node* list, int value);


void displayList(Node* list);


