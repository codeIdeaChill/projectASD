#include "../include/linked_list.h"


//WARNNING
//don't touch my pain please go ahead from here



void initList(Node* list){
    list->next = NULL;
}

int insertBeginning(Node* list, int value){
    list->data = value;
    Node* newnode = (Node*)malloc(sizeof(Node*));
    newnode->next = list; 

}


int insertEnd(ArrayList* list, int value){
    if(list->size >= MAX_LIST_SIZE){
        printf("List is full");
        return Null;
    }
    int index = list->size;
    list->data[index] = value;
    list->next[index] = Null;
    if(list->head == Null){
        list->head = index;
    }else{
        int current = list->head;
        while(list->next[current] != Null){
            current = list->next[current]; 
        }
        list->next[current] = index;
    }
    list->size++;
}

int insertAtPosition(ArrayList* list, int pos, int value){
    int index = findFree(*list);
    if(index == Null){
        printf("List is Full \n");
        return Null;
    }
    if(pos == 0){
        list->data[index] = value; 
        list->next[index] = list->head;
        list->head = index;
    }else{
        list->data[index] = value; 
        list->next[index] = list->next[pos - 1];
        list->next[pos - 1] = index;
    }
    list->size++;

}

void displayList(ArrayList* list){
    int index = list->head;
    int i = 0;
    while(index != Null && i < list->size){
        printf("%d -> ", list->data[index]);
        index = list->next[index];
        i++;
    } 
    printf("NULL! ");
}



int main(){
    ArrayList list;
    initList(&list);
    insertEnd(&list, 4);
    insertEnd(&list, 6);        
    insertEnd(&list, 2);
    insertEnd(&list, 3);

    
    /*
    AddEnd output:     4 -> 6 -> 2 -> 3 -> NULL
    AddBegining output: 3 -> 2 -> 6 -> 4 -> NULL
    */
    displayList(&list); 


    insertAtPosition(&list, 3, 5);
    displayList(&list); 
    return 0;
}