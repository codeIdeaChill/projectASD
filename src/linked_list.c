#include "../include/linked_list.h"


//WARNNING
//don't touch my pain please go ahead from here



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


int insertEnd(ArrayList* list, int value){
    static int end = 0;
    int index = findFree(list);
    if(index == Null){
        printf("List is full");
        return Null;
    }
    list->data[index] = value;
    list->next[end] = index;
    end = index;
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
    insertEnd(&list, 4);
    insertEnd(&list, 6);        
    insertEnd(&list, 2);
    insertEnd(&list, 3);

    /*
    output:     4 -> 6 -> 2 -> 3 -> NULL
    */
    displayList(&list); 
    return 0;
}