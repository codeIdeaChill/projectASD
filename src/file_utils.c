#include "../include/file_utils.h"

typedef struct{
    int id;
    char name[50];
    float score;
    char category[20];
} Record;

// create Binary File_function
int createBinaryFile(const char *filename)
{
    if (!filename){
        return -1;}
    FILE *fp = fopen(filename, "wb");
    if (!fp){
        return -1;}
    if (fclose(fp) != 0){
        return -1;}
    return 0;
}
//write Record_function
int writeRecord(const char *filename, const Record *r)
{
    if (!filename || !r){
        return -1;}
    FILE *fp = fopen(filename, "ab");
    if (!fp){
        return -1;}
    size_t written = fwrite(r, sizeof(Record), 1, fp);
    int status = (written == 1) ? 0 : -1;
    if (fclose(fp) != 0){
        status = -1;}
    return status;
}
//append Record_function
int appendRecord(const char *filename, const Record *r)
{
    return writeRecord(filename, r);
}
//count Records_function
int countRecords(const char *filename)
{
    if (!filename){
        return -1;}
    FILE *fp = fopen(filename, "rb");
    if (!fp){
        return -1; }
    if (fseek(fp, 0, SEEK_END) != 0){
        fclose(fp);
        return -1;}
    long fileSize = ftell(fp);
    if (fileSize < 0){
        fclose(fp);
        return -1;}
    if (fclose(fp) != 0){
        return -1;}
    return (int)(fileSize / sizeof(Record));
}
//read Record_function
int readRecord(const char *filename, int index, Record *r)
{
    if (!filename || !r || index < 0){
        return -1;
    }
    FILE *fp = fopen(filename, "rb");
    if (!fp){
        return -1;
    }
    if (fseek(fp, 0, SEEK_END) != 0){
    fclose(fp);
        return -1;
    }
    long fileSize = ftell(fp);
    if (fileSize < 0){
    fclose(fp);
        return -1;
    }
    long recordCount = fileSize / sizeof(Record);
    if (index >= recordCount){
    fclose(fp);
        return -1;
    }
    long offset = (long)index * sizeof(Record);
    if (fseek(fp, offset, SEEK_SET) != 0){
    fclose(fp);
        return -1;
    }
    size_t read = fread(r, sizeof(Record), 1, fp);
    int status = (read == 1) ? 0 : -1;
    if (fclose(fp) != 0){
        status = -1;}
    return status;
}
//search Record By Id_function
int searchRecordById(const char *filename, int id, Record *result)
{
    if (!filename || !result){
        return -1;}
    FILE *fp = fopen(filename, "rb");
    if (!fp){
        return -1; }
    Record temp;
    int index = 0;
    int foundIndex = -1;
    while (fread(&temp, sizeof(Record), 1, fp) == 1){
        if (temp.id == id){
            *result = temp;
            foundIndex = index;
            break;}
        index++;}
    if (fclose(fp) != 0){
        return -1;}
    return foundIndex;
}
//update Record_function
int updateRecord(const char *filename, int index, const Record *newData)
{
    if (!filename || !newData || index < 0){
        return -1;}
    FILE *fp = fopen(filename, "r+b");
    if (!fp){
        return -1; }
    if (fseek(fp, 0, SEEK_END) != 0){
        fclose(fp);
        return -1;}
    long fileSize = ftell(fp);
    if (fileSize < 0){
        fclose(fp);
        return -1;}
    long recordCount = fileSize / sizeof(Record);
    if (index >= recordCount){
        fclose(fp);
        return -1;}
    long offset = (long)index * sizeof(Record);
    if (fseek(fp, offset, SEEK_SET) != 0){
        fclose(fp);
        return -1;}
    size_t written = fwrite(newData, sizeof(Record), 1, fp);
    int status = (written == 1) ? 0 : -1;
    if (fclose(fp) != 0){
        status = -1;
    }
    return status;
}
//copy Binary File_function
int copyBinaryFile(const char *src, const char *dest)
{
    if (!src || !dest){
        return -1;}
    FILE *srcFp = fopen(src, "rb");
    if (!srcFp){
        return -1;}
    FILE *destFp = fopen(dest, "wb");
    if (!destFp){
        fclose(srcFp);
        return -1;}
    Record temp;
    int status = 0;
    while (fread(&temp, sizeof(Record), 1, srcFp) == 1){
        if (fwrite(&temp, sizeof(Record), 1, destFp) != 1){
            status = -1;
            break;}}
    if (fclose(srcFp) != 0){
        status = -1;}
    if (fclose(destFp) != 0){
        status = -1;}
    return status;
}
int main() {
    //functions in the main program 
    const char *filename = "records.bin";
    createBinaryFile(filename);
    Record r1 = {1, "LYNA", 85.5, "Math"};
    Record r2 = {2, "ZIED", 90.0, "Science"};
    writeRecord(filename, &r1);
    writeRecord(filename, &r2);
    Record readR;
    readRecord(filename, 0, &readR);
    printf("Read Record: ID=%d\n, Name=%s\n, Score=%.2f\n, Category=%s\n\n", readR.id, readR.name, readR.score, readR.category);
    Record searchResult;
    int foundIndex = searchRecordById(filename, 2, &searchResult);
    if (foundIndex != -1) {
        printf("Found Record at index %d: ID=%d\n, Name=%s\n, Score=%.2f\n, Category=%s\n", foundIndex, searchResult.id, searchResult.name, searchResult.score, searchResult.category);}
    else {
        printf("Record with ID=2 not found.\n");}
    Record newData = {2, "ZIED", 95.0, "Science"};
    updateRecord(filename, 1, &newData);
    copyBinaryFile(filename, "records_copy.bin");
    return 0;
}
