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

void swap(int* x, int* y){
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
                swap(&head->data, &head->next->data);
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



int main(){
    Node* list = initList(list);
    list = insertEnd(list, 4);
    list = insertEnd(list, 6);
    list = insertEnd(list, 2);
    list = insertEnd(list, 3);
    list = deleteBeginning(list);
    displayList(list); 
    
    Node* test = initList(test);
    test = insertEnd(test, 10);
    test = insertEnd(test, 8);
    test = insertEnd(test, 7);
    test = insertEnd(test, 1);
    test = deleteBeginning(test);
    displayList(test); 
    /*
    AddEnd output:       4 -> 6 -> 2 -> 3 -> NULL
    AddBegining output:  3 -> 2 -> 6 -> 4 -> NULL
    */

    sortListBubble(list);
    sortListBubble(test);

    displayList(list); 
    displayList(test); 

    Node* result = initList(result);
    result = mergeSortedLists(list, test, result);
    displayList(result); 


    Node* find = searchValue(list, 5);
    if(find == NULL){
        printf("This value does'nt in list !");
    }else{
        printf("the value is: %d \n", find->data);
    }

    return 0;
}