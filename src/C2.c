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