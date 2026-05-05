#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char name[50];
    float score;
    char category[20];
} Record;

int createBinaryFile(const char *filename);


