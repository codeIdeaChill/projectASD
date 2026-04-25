#include "../include/stack.h"


void initStack(Stack* stack){
    stack->top = NULL;
}

int push(Stack* stack, int value){
    Stack* head = stack;
    Stack* newnode = (Stack*)malloc(sizeof(Stack));
    if(newnode == NULL)return -1;
    newnode->top->data = value;
    newnode->top->next = head->top;
    stack->top = newnode->top;
}

void displayStack(Stack* stack){
    Stack* head = stack;
    while(head->top->next != NULL){
        printf("| %d | \n", head->top->data);
        head->top = head->top->next;
    }
}

int main(){

    Stack* stack;
    initStack(stack);
    push(stack, 5);
    push(stack, 2);
    push(stack, 4);
    displayStack(stack);


    return 0;
}