#include <stdio.h>
#include <stdlib.h>
// a record that represent the elements of the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// this record used to follow the front and rear
typedef struct Queue{
    // we use node* to follow the elements 
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* Q)
{
  Q->front = NULL;
  Q->rear = NULL;
}

// to link the new node with the rear and we have the new rear
int enqueue(Queue* Q, int value)
{
    // add an element in the end (rear)
   Node* newNode = (Node*)malloc(sizeof(Node));
   //to link the newnode with value...

   newNode->data = value;
   // we should put NULL to limit the range of the elements
   newNode->next = NULL;

   if (Q->rear == NULL) {
       Q->front = newNode;
       Q->rear = newNode;
   } else {
       Q->rear->next = newNode;
       Q->rear = newNode;
   }
   return 0;
}

int dequeue(Queue* Q)
{
    if (Q->front == NULL) {
        printf("Empty Queue\n");
        return -1;
    }
// we should create the temp to store the head of the queue (front)
    Node* temp = Q->front;
    int value = temp->data;
    Q->front = Q->front->next;

    if (Q->front == NULL) {
        Q->rear = NULL;
    }
//delete the front by the temp
    free(temp);
 // return the value of the deleted element   
    return value;
}

int rear_front (Queue* Q)
{
    if (Q->front == NULL){
        printf("empty Queue\n");
        return -1;
    }else{
        printf("front : %d\n", Q->front->data);
    }
    if (Q->rear == NULL){
        printf("empty Queue\n");
        return -1;
    }else{
        printf("rear : %d\n", Q->rear->data);
    }
}

int main(){
     Queue Q;
     int deletedValue;
     initQueue(&Q);
     enqueue(&Q, 50);
     enqueue(&Q, 60);
     enqueue(&Q, 70);
     deletedValue = dequeue(&Q);
     printf("Deleted value: %d\n", deletedValue);
     rear_front(&Q);

    return 0;
}