//all the lib is declared in array.h 
#include "../include/array.h"

// the initializition the size of array to 0 to become an empty array
void initArray(int arr[], int* size){
    *size = 0;
}

//print array
void printArray(int arr[], int size){
    printf("[");
    for(int i = 0; i < size; ++i){
        printf("%d", arr[i]);
        if(i < size - 1)printf(", ");
    }
    printf("]\n");
}

// insert value in specific position 
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

//delete value from array
int deleteAt(int arr[], int* size, int index){
    if(index < 0 || index > *size)return -1;
    if(*size >= MAX_1D)return -1;
    for(int i = index; i < *size; i++)arr[i] = arr[i + 1];
    (*size)--;
    return 0;
}

// linear search for the value 
int linearSearch(int arr[], int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value)return i;
    }
    return -1;

}

// function for swap two number use it in sorting 
void swap(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//bubble sort sotring each two element
void bubbleSort(int arr[], int size){
    bool swapped;
    for(int i = 0; i < size - 1; ++i){
        swapped = false;
        for(int j = 0; j < size - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if(swapped == false)break;
    }
}


// find position of min of an array 
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

// selection sort need minpos function
void selectionSort(int arr[], int size){
    
    for (int i = 0; i < size - 1; ++i){
        int pos = minPos(arr, size, i + 1);
        if(arr[i] > arr[pos]){
            swap(&arr[i], &arr[pos]);
        }
    }

}



int binarySearch(int arr[], int size, int value){
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

    bubbleSort(arr, size);
    printArray(arr, size);

    printf("the value in %d position \n", binarySearch(arr, size, 1)); 
    
    
    
    return 0;
}

