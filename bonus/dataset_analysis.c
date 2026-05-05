#include <stdio.h>
#include <stdlib.h>

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

int main(){

    Record temp[] = {{0, "professor", 10, "teacher"},{1, "adem", 15.9, "student"},{2, "mokrani", 24.3, "school"}};
    size_t count = sizeof(temp)/sizeof(Record);
    createBinarfile("list.bin", temp, count);
    int size = 0;
    Record* array = (Record*)malloc(count * sizeof(Record));
    loadDataset("list.bin", array, &size);
    displayDataset(array, size);
    free(array);

}