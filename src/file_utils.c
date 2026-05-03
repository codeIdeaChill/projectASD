#include <stdio.h>
// create a record to store the data of the students
typedef struct
{
    int id;
    char name[50];
    float score;
    char category[20];
} Record;

int createBinaryFile(const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        return -1;
    }
    fclose(file);
    return 0;
}

int 

int main()
{
    FILE *students;
    createBinaryFile("students.bin");

    return 0;
}