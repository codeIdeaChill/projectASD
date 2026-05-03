#include "../include/stack.h"


Stack* initStack(Stack* stack){
    stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int push(Stack* stack, int value){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL)return -1;
    newnode->data = value;
    newnode->next = stack->top;
    stack->top = newnode;
    return 0;
}


int pop(Stack* S){
    if(S->top == NULL)return -1;
    Node* temp = S->top;
    int value = temp->data;
    S->top = temp->next;
    free(temp);
    return value;

}

int peek(Stack* S){
    if(S->top == NULL)return -1;
    printf("top element: %d \n", S->top->data);
    return 0;
}
int isEmpty(Stack* S){
    return S->top == NULL;
}

int main(){

    Stack* stack = initStack(stack);
    push(stack, 5);
    push(stack, 4);
    printf("is empty : %d \n", isEmpty(stack));
    peek(stack);

    return 0;
}