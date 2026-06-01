#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//adem who gonna do the bonus don't touch it

typedef struct{
    int   id;
    char  name[50];
    float score;
    char  category[20];
}Record;

int loadDataset(const char* filename, Record arr[], int* count){
    FILE* file = fopen(filename, "rb");
    if(file == NULL)return -1;
    fseek(file, 0, SEEK_END);
    long sizeFile = ftell(file);
    rewind(file);
    *count = sizeFile / sizeof(Record);
    for(int i=0; i< *count; ++i)fread((arr + i), sizeof(Record), 1, file);
    fclose(file);
}

size_t sizeofFile(const char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL)return -1;
    fseek(file, 0, SEEK_END);
    long sizeFile = ftell(file);
    rewind(file);
    return sizeFile / sizeof(Record);
}


void displayDataset(Record arr[], int count){
    if(arr == NULL)return;
    printf("\n%-5s | %-15s | %-8s | %-15s \n","ID", "NAME", "SCORE", "CATEGORY");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        printf("%-5d | %-15s | %-8.2f | %-15s \n",  arr[i].id, 
                            arr[i].name, 
                            arr[i].score, 
                            arr[i].category);
    }
    printf("-------------------------------------------------\n");
}

void createBinarfile(const char* filename, Record* r, size_t count){
    FILE* f = fopen(filename, "wb");
    if(f == NULL)printf("error while opening file! \n");
    size_t resu = fwrite(r, sizeof(Record), count, f);
    if(resu != count)printf("error writing! \n");
    fclose(f);
}
int findMin(Record arr[], int count, int index, int pram){
    int pos = index;
    switch(pram){
        case 1:
            float mini = arr[index].score;
            for(int i = index; i < count; i++){
                if(mini > arr[i].score){
                    mini = arr[i].score;
                    pos = i;
                }
            }
            return pos;
            break;
        case 2:
            int min = arr[index].id;
            for(int i = index; i < count; i++){
                if(min > arr[i].id){
                    min = arr[i].id;
                    pos = i;
                }
            }
            return pos;

            break;
        case 3:
            for(int i = index; i < count - 1; i++){
                if(strcmp(arr[i].name, arr[i+1].name) < 0){
                    pos = i;
                }else if(strcmp(arr[i].name, arr[i+1].name) > 0){
                    pos = i+1;
                }else{
                    pos = i;
                }
            }
            return pos;
            break;
    }
}

void swap(Record* x, Record* y){
    Record tmp = *x;
    *x = *y;
    *y = tmp;
}

void selectionSort(Record arr[], int count, int pram){
    for(int i = 0; i < count - 1; ++i){
        int pos = findMin(arr, count, i + 1, pram);
        switch(pram){
            case 1:
                if(arr[i].score > arr[pos].score){
                    swap(&arr[i], &arr[pos]);
                }
                break;
            case 2:
                if(arr[i].id > arr[pos].id){
                    swap(&arr[i], &arr[pos]);
                }
                break;
            case 3:
                if(strcmp(arr[i].name, arr[pos].name) > 0){
                    swap(&arr[i], &arr[pos]);
                }
                break;
        }
    }
}

void sortDatasetByField(Record arr[], int count, char* field){
    if(arr == NULL)return;
    if(field == "name"){
        selectionSort(arr, count, 3);
    }else if(field == "id"){
        selectionSort(arr, count, 2);
    }else if(field == "score"){
        selectionSort(arr, count, 1);
    }else{
        printf("no sorting match :( \n");
        return;
    }
}

Record findMaxByField(Record arr[], int count){
    if(arr == NULL || count == 0){
        printf("there is no element!\n");
        Record x = {0};
        return x;
    }
    float max = arr[0].score;
    for(int i = 1; i < count; i++){
        int j = 0;
        if(max < arr[i].score){
            max = arr[i].score;
            j = i;
        }
        if(i == count - 1){
            return arr[j];
        }
    }
    return arr[0]; 
}

Record findMinByField(Record arr[], int count){
    if(arr == NULL || count == 0){
        printf("there is no element!\n");
        Record x = {0};
        return x;
    }
    float min = arr[0].score;
    for(int i = 1; i < count; i++){
        int j = 0;
        if(min > arr[i].score){
            min = arr[i].score;
            j = i;
        }
        if(i == count - 1){
            return arr[j];
        }
    }
    return arr[0]; 
}

float averageByField(Record arr[], int count){
    if(arr == NULL || count == 0){
        return 0.0;
    }
    float avr = 0.0;
    for(int i = 0; i < count; i++){
        avr += arr[i].score;
    }
    return avr / (float)count;
}

int filterByCondition(Record arr[], int count, float threshold, Record out[]){
    if(arr == NULL){
        printf("there is no element !\n");
        return -1;
    }
    int j = 0;
    for(int i = 0; i < count; i++){
        if(arr[i].score >= threshold){
            out[j] = arr[i];
            j++;
        }
    }
    return j;
}

int saveBinaryReport(const char* filename, Record arr[], int count){
    FILE* f = fopen(filename, "wb");
    if(f == NULL)printf("error while opening file! \n");
    size_t resu = fwrite(arr, sizeof(Record), count, f);
    if(resu != count)printf("error writing! \n");
    fclose(f);
    return 0;
}

int main(){
    bool exit = false;
    start:
    printf("====DATA SET ANALYSIS====\n");
    size_t count = sizeofFile("list.bin");
    int size = 0;
    Record* array = (Record*)malloc(count * sizeof(Record));
    Record* out = (Record*)malloc(sizeof(Record) * count);
    int x = 0;
    do{
        printf("\n----------------------------\n");
        printf("1. Load data from file.\n2. Display data.\n3. Sort data.\n4. Filter by thershold\n"
            "5. Save data log.\n6. EXIT\n");
        int choice = 0;
        printf("----------------------------\n");
        printf("choise: ");
        scanf("%d", &choice);
        printf("----------------------------\n");
        switch(choice){
            case 1:
                printf("Loading data...\n");
                loadDataset("list.bin", array, &size);
                break;
            case 2:
                displayDataset(array, size);
                break;
            case 3:
                int sort = 0;
                printf("Which one do you want to sort?\n1. Name\n2. Id\n3. Score\n");
                scanf("%d", &sort);
                switch(sort){
                    case 1:
                        sortDatasetByField(array, size, "name");
                        break;
                    case 2:
                        sortDatasetByField(array, size, "id");
                        break;
                    case 3:
                        sortDatasetByField(array, size, "score");
                        break;
                }
                break;
            case 4:
                float filter = 0;
                printf("Enter filter value: ");
                scanf("%f", &filter);
                x = filterByCondition(array, size, filter, out);
                displayDataset(out, x);
                break;
            case 5:
                printf("what will you save?\n1. Filtered list\n2. Sorted list\n");
                int ch = 0;
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        if(saveBinaryReport("save.bin", out, x) == 0)
                            printf("success to save a file \n");
                    case 2:
                        if(saveBinaryReport("save.bin", array, count) == 0)
                            printf("success to save a file \n");

                }
                break;
            case 6:
                printf("Exiting...\n");
                printf("good night :)\n");
                exit = true;
                break;
        }
    }while(!exit);
    free(array);
    free(out);


    return 0;
}