#include "../include/linked_list.h"


void initList(ArrayList* list){
    list->head = 0;
    list->size = 0;
    for(int i = 0; i < MAX_LIST_SIZE; i++){
        list->next[i] = Null;
    } 
}

int findFree(ArrayList* list){
    for(int i = 0; i < MAX_LIST_SIZE; i++){
        if(list->next[i] == Null && i != list->head)return i;
    }
    return Null;
}
int insertBeginning(ArrayList* list, int value){
    int index = findFree(list);
    if(index == Null){
        printf("List is full");
        return Null;
    }
    list->data[index] = value;
    list->next[index] = list->head;
    list->head = index;
    list->size++;
    
}

void displayList(ArrayList* list){
    int index = list->head;
    for(int i = 0; i < list->size; i++){
        if(index != Null){
            printf("%d -> ", list->data[index]);
            index = list->next[index];
        } 
    }
    printf("NULL! ");
}



int main(){
    ArrayList list;
    initList(&list);
    insertBeginning(&list, 4);
    insertBeginning(&list, 6);
    insertBeginning(&list, 2);
    insertBeginning(&list, 1);
    insertBeginning(&list, 3);
    displayList(&list); 
    return 0;
}