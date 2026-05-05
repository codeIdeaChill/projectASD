#include "../include/linked_list.h"

// signly liked list

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

Node* deleteBeginning(Node* list){
    if(list == NULL){
        printf("List is empty! \n");
        return NULL;
    }
    Node* head = list->next;
    free(list);

    return head;

}

Node* deleteEnd(Node* list){
    Node* head = list;
    if(head == NULL){
        printf("List is empty! \n");
        return NULL;
    }
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    while(head->next->next != NULL){
        head = head->next;
    }
    Node* temp = head->next;
    head->next = NULL;
    free(temp);
    return list;
}

Node* deleteByValue(Node* list, int value){
    if(list == NULL){
        printf("List is empty! \n");
        return NULL;
    }
    if(list->data == value){
        Node* temp = list;
        list = list->next;
        free(temp);
        return list;
    }
    
    Node* head = list;
    while(head->next != NULL){
        if(head->next->data == value){
            Node* temp = head->next;
            head->next = temp->next;
            free(temp);
            return list;
        }
        head = head->next;
    }

    return list;
}


Node* searchValue(Node* list, int value){
    if(list == NULL){
        printf("List is empty! \n");
        return NULL;
    }
    Node* head = list;
    while(head != NULL){
        if(head->data == value){
            return head;
        }
        head = head->next;
    }
    return NULL;
}


Node* reverseList(Node* list){
    if(list == NULL){
        printf("List is empty! \n");
        return NULL;
    }
    Node* head = list;
    while(head->next != NULL){
        head = head->next;
    }
    Node* temp = list;
    Node* curr = head;
    while(curr != list){
        while(temp->next != curr){
            temp = temp->next;
        }
        curr->next = temp;
        curr = temp;
        temp = list;
    }
    list->next = NULL;
    return head;
}

void swaplist(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

bool isSorted(Node* list){
    Node* head = list;
    while(head->next != NULL){
        if(head->data > head->next->data)return false;
        head = head->next;
    }
    return true;
}

void sortListBubble(Node* list){
    if(list == NULL){
        printf("List is empty! ");
        return;
    }
    Node* head = list;
    while(head != NULL){
        while(head->next != NULL){
            if(head->data > head->next->data){
                swaplist(&head->data, &head->next->data);
            }
            head = head->next;
        }
        if(isSorted(list))return;
        head = list;
    }
}

Node* mergeSortedLists(Node* a, Node* b, Node* list){
    if(a == NULL && b == NULL){
        printf("List is empty to merge! \n");
        return NULL;
    }
    Node* ahead = a;
    Node* bhead = b;
    while(ahead != NULL){
        if(ahead->data > bhead->data){
            list = insertEnd(list, bhead->data);
            bhead = bhead->next;
        }else{
            list = insertEnd(list, ahead->data);
            ahead = ahead->next;
        }
    }
    while(bhead != NULL){
        list = insertEnd(list, bhead->data);
        bhead = bhead->next;
    }
    return list;
}

//doubly linked list

void initListDLL(DNode** list){
    (*list) = (DNode*)malloc(sizeof(DNode));
    (*list)->next = (*list)->prev = NULL;
    (*list)->data = 0;
}

int insertBeginningDLL(DNode** list, int value){
    DNode* new = (DNode*)malloc(sizeof(DNode));
    new->data = value;
    (*list)->prev = new;
    new->next = *list;
    new->prev = NULL;
    *list = new;
}

int insertEndDLL(DNode* list, int value){
    DNode* new = (DNode*)malloc(sizeof(DNode));
    if(!new)return -1;
    new->data = value;
    new->next = NULL;
    DNode* tail = list;
    DNode* temp = tail;
    while(tail != NULL){
        temp = tail;
        tail = tail->next;
    }
    new->prev = temp;
    temp->next = new;
}

void displayForward(DNode* list){
    if(list == NULL){
        printf("list is empty! \n");
        return;
    }
    DNode* head = list;
    printf("null");
    while(head != NULL){
        printf("<- [%d] ->", head->data);
        head = head->next;
    }
    printf("null\n");

}

int deleteByValueDLL(DNode** list, int value){
    if((*list) == NULL){
        printf("list is empty! \n");
        return -1;
    }
    DNode* head = *list;
    while(head->data != value){
        head = head->next;
        if(head == NULL){
            printf("the value does not exist! \n");
            return -1;
        }
    }
    if(head == *list){
        head->next->prev = NULL;
        *list = head->next;
        free(head);
        return 0;
    }
    if(head->next == NULL){
        head->prev->next = NULL;
        free(head);
        return 0;
    }
    head->prev->next = head->next;
    head->next->prev = head->prev;
    
    free(head);
    return 0;

}

void displayBackward(DNode* list){
    if(list == NULL){
        printf("list is empty! \n");
        return;
    }
    DNode* tail = list;
    while(tail->next != NULL){
        tail = tail->next;
    }
    printf("null");
    while(tail != NULL){
        printf("<- [%d] ->", tail->data);
        tail = tail->prev;
    }
    printf("null\n");
}


// function for display linked list
void displayList(Node* list){
    Node* head = list;
    while(head != NULL){
        printf("[%d] -> ", head->data);
        if(head->next == NULL)printf("[NULL]");
        head = head->next;
    } 
    printf("\n");
}
