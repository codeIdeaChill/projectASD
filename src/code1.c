#include <stdio.h>
#include <stdlib.h>

int main() {

    /* ── 1. WRITE to a text file ── */
    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "%-20s %5s\n", "Name", "Grade");
    fprintf(fp, "%-20s %5d\n", "Ali Benali",    15);
    fprintf(fp, "%-20s %5d\n", "Sara Khelif",   17);
    fprintf(fp, "%-20s %5d\n", "Mohamed Amine", 12);

    fclose(fp);  /* Always close after writing */
    printf("[OK] File 'students.txt' created.\n");

    /* ── 2. READ from the text file ── */
    fp = fopen("students.txt", "r");
    if (fp == NULL) { perror("Error"); exit(1); }

    char line[100];
    printf("\n--- Content of students.txt ---\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);  /* fgets keeps '\n' */
    }

    fclose(fp);

    /* ── 3. APPEND a new student ── */
    fp = fopen("students.txt", "a");
    fprintf(fp, "%-20s %5d\n", "Yasmine Hadj", 19);
    fclose(fp);
    printf("\n[OK] Appended new student.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* ── Write 5 integers in binary ── */
    int grades[] = {14, 17, 9, 15, 20};
    int n = sizeof(grades) / sizeof(grades[0]);

    FILE *fp = fopen("grades.bin", "wb");
    if (!fp) { perror("Error"); exit(1); }

    /*  fwrite(data, element_size, count, file) */
    size_t written = fwrite(grades, sizeof(int), n, fp);
    printf("Written: %zu integers (%zu bytes total)\n",
           written, written * sizeof(int));
    fclose(fp);

    /* ── Read back ── */
    int read_grades[10];
    fp = fopen("grades.bin", "rb");
    if (!fp) { perror("Error"); exit(1); }

    size_t read = fread(read_grades, sizeof(int), 10, fp);
    printf("Read back: %zu integers\n", read);

    printf("Values: ");
    for (int i = 0; i < (int)read; i++) {
        printf("%d ", read_grades[i]);
    }
    printf("\n");
    fclose(fp);

    return 0;
}#include <stdio.h>
#include <stdlib.h>

int main() {

    /* ── Write 5 integers in binary ── */
    int grades[] = {14, 17, 9, 15, 20};
    int n = sizeof(grades) / sizeof(grades[0]);

    FILE *fp = fopen("grades.bin", "wb");
    if (!fp) { perror("Error"); exit(1); }

    /*  fwrite(data, element_size, count, file) */
    size_t written = fwrite(grades, sizeof(int), n, fp);
    printf("Written: %zu integers (%zu bytes total)\n",
           written, written * sizeof(int));
    fclose(fp);

    /* ── Read back ── */
    int read_grades[10];
    fp = fopen("grades.bin", "rb");
    if (!fp) { perror("Error"); exit(1); }

    size_t read = fread(read_grades, sizeof(int), 10, fp);
    printf("Read back: %zu integers\n", read);

    printf("Values: ");
    for (int i = 0; i < (int)read; i++) {
        printf("%d ", read_grades[i]);
    }
    printf("\n");
    fclose(fp);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {

    /* ── Write 5 integers in binary ── */
    int grades[] = {14, 17, 9, 15, 20};
    int n = sizeof(grades) / sizeof(grades[0]);

    FILE *fp = fopen("grades.bin", "wb");
    if (!fp) { perror("Error"); exit(1); }

    /*  fwrite(data, element_size, count, file) */
    size_t written = fwrite(grades, sizeof(int), n, fp);
    printf("Written: %zu integers (%zu bytes total)\n",
           written, written * sizeof(int));
    fclose(fp);

    /* ── Read back ── */
    int read_grades[10];
    fp = fopen("grades.bin", "rb");
    if (!fp) { perror("Error"); exit(1); }

    size_t read = fread(read_grades, sizeof(int), 10, fp);
    printf("Read back: %zu integers\n", read);

    printf("Values: ");
    for (int i = 0; i < (int)read; i++) {
        printf("%d ", read_grades[i]);
    }
    printf("\n");
    fclose(fp);

    return 0;
}