//all the lib is declared in array.h 
#include "../include/array.h"

// the initializition the size of array to 0 to become an empty array
void initArray(int arr[], int* size){
    *size = 0;
}

//print array
void printArray(int arr[], int size){
    if(arr == NULL){
        printf("Array is empty! \n");
        return;
    }
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


void merge(int arr[], int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid; 
    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j){
        R[j] = arr[mid + 1 +j];
    }
    int i = 0, j = 0, k = left;
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
        return 0;
    }
    int sum=0;
    for(int i = 0;i < size; i++){
        sum = sum + arr[i];
    }
    return sum;
}
//array average
double averageArray(int arr[], int size){
    if (size == 0)return 0;
    int sum = sumArray(arr, size);
    return (double)sum / (double)size;
}
//find max 
int findMax(int arr[], int size){
    int Max = arr[0];   
    for(int i=1;i<size;i++){
        if (arr[i] > Max) {
            Max = arr[i];
        }
    }

    return Max;
}
//find Min
int findMin(int arr[], int size) {
    int Min = arr[0];  
    for(int i = 1; i < size; i++) { 
        if (arr[i] < Min) { 
            Min = arr[i]; 
        }
    }
    
    return Min;
}

int partition(int arr[], int low, int high){
    int poiv = arr[high];

    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < poiv){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// create a daynmaique array
int* createDynamicArray(int capacity) {

    int* arr = malloc(capacity * sizeof(int));

    // check for observing space 
    if (arr == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }

    return arr;
}
//fillArray
void fillArray(int* arr, int* size){
    printf("enter size: ");
    scanf("%d", size);
    if(size < 0){
        printf("error");
    }
    for(int i = 0; i < *size; i++){
        printf("arr[%d]",i);
        scanf("%d",&arr[i]);
    }
}


int* freeArray(int* arr) {
    free(arr);
    return NULL;

}

//resizeArray
int* resizeArray(int* arr, int newCapacity){
    int* temp = (int*)realloc(arr, newCapacity * sizeof(int));
    if(temp==NULL){
        printf("error");
        return NULL;
    }
  return temp;  
}



//init MATRIX
void initMatrix(int m[][MAX_COLS], int* rows, int* cols){
    if(*rows > MAX_ROWS || *cols > MAX_COLS){
        printf("error");
    }
    for(int i=0;i<*rows;i++){
        for(int j=0;j<*cols;j++){
            printf("enter [%d][%d]: ", i, j);
            scanf("%d",&m[i][j]);
        }
    }

}


// print Matrix
void printMatrix(int m[][MAX_COLS], int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%4d",m[i][j]);
        }
        printf("\n");
    }
}

//addMatrices
void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            r[i][j]=a[i][j]+b[i][j];
        }
    }
}

//multiplyMatrices
void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int n){
    for(int i = 0;i < n; ++i){
        for(int j = 0; j < n; ++j){
            r[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                r[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

//transposeMatrix
void transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            out[i][j] = m[j][i];
        }
    }
}
 //isSymmetric 
int isSymmetric(int m[][MAX_COLS], int n){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(m[i][j] != m[j][i])
                return 0;
    return 1;
}
