#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int createBinaryFile(const char *filename);
int writeRecord(const char *filename, const Record *r);
int appendRecord(const char *filename, const Record *r);
int countRecords(const char *filename);
int readRecord(const char *filename, int index, Record *r);
int searchRecordById(const char *filename, int id, Record *result);
int updateRecord(const char *filename, int index, const Record *newData);
int copyBinaryFile(const char *src, const char *dest);



