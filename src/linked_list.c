#include "../include/linked_list.h"


//WARNNING
//don't touch my pain please go ahead from here



void initList(Node* list){
    list->next = NULL;
}

int insertBeginning(Node* list, int value){
    Node* newnode = (Node*)malloc(sizeof(Node*));
    newnode->data = value;
    newnode->next = list; 

}



void displayList(Node* list){
    while(list->next != NULL){
        printf("%d -> ", list->data);
        list = list->next;
    } 
    printf("NULL! ");
}



int main(){
    Node list;
    initList(&list);
    insertBeginning(&list, 4);
    insertBeginning(&list, 6);        
    insertBeginning(&list, 2);
    insertBeginning(&list, 3);

    
    /*
    AddEnd output:     4 -> 6 -> 2 -> 3 -> NULL
    AddBegining output: 3 -> 2 -> 6 -> 4 -> NULL
    */
    displayList(&list); 


    return 0;
}