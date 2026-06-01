#include "../include/file_utils.h"

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

