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
   
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
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

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; ++i){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void merge(int arr[], int l, int m, int r){

    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; ++j){
        R[j] = arr[m + 1 +j];
    }


    int i =0, j=0, k =l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int m = left + (right - left)/2;

        mergeSort(arr, left, m);
        mergeSort(arr, m +1, right);

        merge(arr, left, m, right);
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

//array sum
int sumArray(int arr[], int size) {

    if(arr == NULL || size == 0){   //you should check if size == 0 
                                    //not size <= 0
        return 0;
    }
    int sum=0;
    for(int i=1;i<size;i++){
        sum=sum+arr[i];
    }
    return sum;
}
//array average
double averageArray(int arr[], int size){
    if (size==0){
        return 0;

    }
    int sum = sumArray(arr, size);
    return (double)sum / (double)size;
}
//find max 
int findMax(int arr[], int size){
    int Max; 
     Max= arr[0];   
      for(int i=1;i<size;i++){
           if (arr[i] > Max) {
    Max = arr[i];
           }


       }

return Max;




}
    



int main(){
    int size = 0;   //definition size
    int arr[MAX_1D];//difinition of array

    // initialization the array with size = 0
    initArray(arr, &size);


    insertAt(arr, &size, 0, 5);//insert 5 in position 0
    insertAt(arr, &size, 1, 3);//insert 3 in position 1
    insertAt(arr, &size, 2, 4);//insert 4 in position 2 
    insertAt(arr, &size, 3, 1);//insert 1 in position 3 
    // 1. calling the function
    double avg = averageArray(arr, size);

    // 2. displaying avg
    printf("the average of array is %f\n", avg);
    
    
    int finale_Max; 
    finale_Max = findMax(arr, size);// calling the function find max
    
    // displaying the max 
    printf("the max is %d\n", finale_Max);
    


    //bubbleSort(arr, size);// this func for sort the array
    //insertionSort(arr,size);
    mergeSort(arr,0,size - 1);
    printArray(arr, size);// to print the array

    printf("the value in %d position \n", binarySearch(arr, size, 1)); 
    printf("the sum of array %d \n", sumArray(arr, size)); 
    
    
    
    return 0;
}

