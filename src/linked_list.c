#include "../include/linked_list.h"


//WARNNING
//don't touch my pain please go ahead from here



Node* initList(Node* list){
    list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    return list;
}


Node* createnewNode(int value){
    Node* newnode = (Node*)malloc(sizeof(Node*));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

Node* insertBeginning(Node* list, int value){
    Node* newnode = createnewNode(value); 
    newnode->next = list;
    return newnode;
}


Node* insertEnd(Node* list, int value){
    Node* tail = createnewNode(value);
    Node* head = list;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = tail;
    return list;
}


Node* insertAtPosition(Node* list, int pos, int value){
    Node* newNode = createnewNode(value);
    Node* curr = list;
    int i = 0;
    while(i != pos - 1 && curr != NULL){
        curr = curr->next;
        i++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return list;
}





// function for display linked list
void displayList(Node* list){
    Node* head = list;
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    } 
    printf("NULL! ");
}



int main(){
    Node* list = initList(list);
    list = insertEnd(list, 4);
    list = insertEnd(list, 6);
    list = insertEnd(list, 2);
    list = insertEnd(list, 3);
    displayList(list); 
    list = insertAtPosition(list, 2, 5);
    
    /*
    AddEnd output:      1 -> 4 -> 6 -> 2 -> 3 -> NULL
    AddBegining output: 1 -> 3 -> 2 -> 6 -> 4 -> NULL
    */
    displayList(list); 


    return 0;
}