//all the lib is declared in array.h 
#include "../include/array.h"

// the initializition the size of array to 0 to become an empty array
void initArray(int arr[], int* size){
    *size = 0;
}

void printArray(int arr[], int size){
    printf("[");
    for(int i = 0; i < size; ++i){
        printf("%d", arr[i]);
        if(i < size - 1)printf(", ");
    }
    printf("]\n");
}

int insertAt(int arr[], int *size, int index, int value){
    //check for errors
    if(index < 0 || index > *size)return -1;
    if(*size >= MAX_1D)return -1;

//this for loop for shift all element after the index to right and put the volue in the index position
    for(int i = *size; i > index; i--)arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}

int deleteAt(int arr[], int* size, int index){
    if(index < 0 || index > *size)return -1;
    if(*size >= MAX_1D)return -1;
    for(int i = index; i < *size; i++)arr[i] = arr[i + 1];
    (*size)--;
    return 0;
}
int linearSearch(int arr[], int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value)return i;
    }
    return -1;

}

int minPos(int arr[], int size, int index){
    int min = arr[index];
    int pos = index;
    for(int i = index; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

void sort(int arr[], int size){
    int tmp = 0;
    for (int i = 0; i < size - 1; ++i){
        int pos = minPos(arr, size, i + 1);
        if(arr[i] > arr[pos]){
            tmp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = tmp;
        }
    }

}



int binarySearch(int arr[], int size, int value){
    sort(arr, size);

    int low = 0, hight = size - 1;
    int mid = (hight + low) / 2;
    while(arr[mid] != value){
        if(arr[mid] > value){
            hight = mid - 1;
            mid = (hight + low) / 2;
        }else{
            low = mid + 1;
            mid = (hight + low) / 2;
       }
       if(arr[mid] == value)return mid;
       if(low > hight)return -1;
    }
    if(arr[mid] == value)return mid;

}


int main(){
    int size = 0;
    int arr[MAX_1D];
    initArray(arr, &size);


    insertAt(arr, &size, 0, 5);
    insertAt(arr, &size, 1, 3);
    insertAt(arr, &size, 2, 4);
    insertAt(arr, &size, 3, 1);


    printArray(arr, size);

    printf("the value in %d position \n", binarySearch(arr, size, 1)); 
    printArray(arr, size);
    
    
    
    return 0;
}

