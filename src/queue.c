#include "../include/queue.h"

void initQueue(Queue* Q)
{
  Q->front = NULL;
  Q->rear = NULL;
  Q->count = 0;
}

// to link the new node with the rear and we have the new rear
int enqueue(Queue* Q, int value)
{
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = value;
   newNode->next = NULL;

   if (Q->rear == NULL) {
       Q->front = newNode;
       Q->rear = newNode;
   } else {
       Q->rear->next = newNode;
       Q->rear = newNode;
   }
   Q->count++;
   return 0;
}

int dequeue(Queue* Q)
{
    if (Q->front == NULL) {
        printf("Empty Queue\n");
        return -1;
    }
    Node* temp = Q->front;
    int value = temp->data;
    Q->front = Q->front->next;

    if (Q->front == NULL) {
        Q->rear = NULL;
    }

    free(temp);
    Q->count--;
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
