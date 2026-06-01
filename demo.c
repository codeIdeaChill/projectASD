#include <stdio.h>
#include "include/common.h"
#include "include/array.h"
#include "include/linked_list.h"
#include "include/stack.h"
#include "include/queue.h"
#include "include/file_utils.h"
#include "include/string_utils.h"

void arrayMenu() {
    int choice, arr[MAX_1D], size = 0, value, index;
    do {
        printf("\n=== ARRAY MENU ===\n");
        printf("1. Insert element\n2. Delete element\n"
               "3. Search\n4. Sort\n5. Display\n6. Back\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Index and value: ");
                scanf("%d %d", &index, &value);
                insertAt(arr, &size, index, value);
                break;
            case 2:
                printf("Index for deleting: ");
                scanf("%d", &index);
                deleteAt(arr, &size, index);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("chose the algorithm to search: \n");
                printf("1. binary search\n"
                        "2. linear search\n""3. Back\n");
                printf("CHOICE: ");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                        printf("the value in %d index\n",binarySearch(arr, size, value));
                        break;
                    case 2:
                        printf("the value in %d index\n",linearSearch(arr, size, value));
                        break;
                    case 3:
                        arrayMenu();
                        break;
                    default:
                        printf("Not in cases!\n");
                        break;
                }
                break;
            case 4:
                printf("choise the algorithm to sort: \n");
                printf("1. bubble Sort\n""2. selection Sort\n""3. merge Sort\n""4. insertion Sort\n""5. Back\n");
                printf("CHOICE: ");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                        bubbleSort(arr, size);
                        break;
                    case 2:
                        selectionSort(arr, size);
                        break;
                    case 3:
                        mergeSort(arr, 0, size - 1);
                        break;
                    case 5:
                        arrayMenu();
                        break;
                    default:
                        printf("Not in cases!\n");
                        break;
                }
                break;
            case 5:
                printArray(arr, size);
                break;
            case 6:
                return;
                break;
            default:
                printf("Not in cases!\n");
                break;
        }
    } while (choice != 0);
}

void linked_list(){
    int choice, value, index;
    Node* list = initList(list);
    do {
        printf("\n=== LINKED LIST MENU ===\n");
        printf("1. Insert value\n2. Delete value\n3. Display\n4. Search\n5. Sort\n6. Back\n"
            "CHOICE: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("chose where do you want to add the value\n");
                printf("1. Inset at beginning\n2. Insert at end\n3. Insert at position\n4. Back\n"
                    "CHOICE:");
                scanf("%d",&choice);
                switch(choice){
                    case 1:
                        printf("Enter the value: ");
                        scanf("%d", &value);
                        insertBeginning(&list, value);
                        break;
                    case 2:
                        printf("Enter the value: ");
                        scanf("%d", &value);
                        insertEnd(list, value);
                        break;
                    case 3:
                        printf("Enter the value: ");
                        scanf("%d", &value);
                        printf("Enter the position: ");
                        scanf("%d", &index);
                        list = insertAtPosition(list, index, value);
                        break;
                    case 4:
                        linked_list();
                        break;
                    default:
                        printf("Not in cases!");
                        break;
                }
                break;
            case 2:
                printf("1. Delete at begining\n2. Delete at end\n3. Delete by value\n4. Back\n"
                    "CHOSE: ");
                scanf("%d", &choice);
                switch(choice){
                    case 1:
                        list = deleteBeginning(list);
                        break;
                    case 2:
                        list = deleteEnd(list);
                        break;
                    case 3:
                        printf("Enter the value: ");
                        scanf("%d", &value);
                        deleteByValue(list, value);
                        list = insertAtPosition(list, index, value);
                        break;
                    case 4:
                        linked_list();
                        break;
                    default:
                        printf("Not in cases!\n");
                        break;
                }
                break;
            case 3:
                displayList(list);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* found = searchValue(list, value);
                if(found)printf("the value found in %p and their data: %d\n", found, found->data);
                if(!found)printf("this value does't exist in this list!\n");
                break;
            case 5:
                sortListBubble(list);
                break;
            case 6:
                return;
                break;
            default:
                printf("Not in cases!\n");
                break;
        }
    }while(choice != 0); 
}

int main() {
    int choice;
    do {
        printf("\n=== ADS2 PROJECT DEMO ===\n");
        printf("1. Arrays\n2. Linked Lists\n3. Stacks\n"
               "4. Queues\n5. File Handling\n6. String Utils\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arrayMenu(); break;
            case 2: linked_list(); break;
            case 3: linked_list(); break;
            case 4: linked_list(); break;
            case 5: linked_list(); break;
            case 6: linked_list(); break;
            case 0: linked_list(); break;
        }
    } while (choice != 0);
    return 0;
}

