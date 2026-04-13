#include <stdio.h>
#include <common.h>



typedef struct Node{
    int data;
    struct Node* next;
}Node;


void initList(Node* node);