#include "../include/linked_list.h"


//WARNNING
//don't touch my pain please go ahead from here



void initList(ArrayList* list){
    list->head = -1;
    list->size = 0;
    for(int i = 0; i < MAX_LIST_SIZE; i++){
        list->next[i] = -1;
    } 
}

int findFree(ArrayList list){
    for(int i = 0; i < MAX_LIST_SIZE; i++){
        if(list.next[i] == Null)return i;
    }
    return Null;
}



int insertBeginning(ArrayList* list, int value){
    int index = list->size;
    if(index == Null){
        printf("List is full");
        return Null;
    }
    list->data[index] = value;
    list->next[index] = list->head;
    list->head = index;
    list->size++;
    
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
    return 0;
}