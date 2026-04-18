#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
typedef struct {
    int   id;
    char  name[50];
    float grade;
    int   year;
} Student;

int main() {

    /* ── A. Measure file size with SEEK_END ── */
    FILE *fp = fopen("students.db", "rb");
    if (!fp) { perror("Run records.c first!"); exit(1); }

    fseek(fp, 0, SEEK_END);                   /* go to end */
    long file_size = ftell(fp);               /* position = size */
    long num_records = file_size / sizeof(Student);

    printf("File size  : %ld bytes\n", file_size);
    printf("Num records: %ld\n\n", num_records);

    /* ── B. Read records in REVERSE order ── */
    printf("Records in reverse:\n");
    Student s;

    for (long i = num_records - 1; i >= 0; i--) {
        fseek(fp, i * (long)sizeof(Student), SEEK_SET);
        fread(&s, sizeof(Student), 1, fp);
        printf("  [%d] %s — %.1f\n", s.id, s.name, s.grade);
    }

    fclose(fp);

    /* ── C. UPDATE record[1] grade in-place ── */
    fp = fopen("students.db", "r+b");   /* r+b = read+write binary */

    long target = 1;   /* Sara Khelif, index 1 */

    /* Step 1: seek to the grade field inside record[1] */
    long offset = target * sizeof(Student)
                + offsetof(Student, grade);
    fseek(fp, offset, SEEK_SET);

    /* Step 2: check where we are */
    printf("\nCursor before write: byte %ld\n", ftell(fp));

    /* Step 3: write new grade directly */
    float new_grade = 18.5f;
    fwrite(&new_grade, sizeof(float), 1, fp);

    printf("Cursor after write : byte %ld\n", ftell(fp));
    fclose(fp);

    /* ── D. Verify the update ── */
    fp = fopen("students.db", "rb");
    fseek(fp, 1 * sizeof(Student), SEEK_SET);
    fread(&s, sizeof(Student), 1, fp);
    printf("Updated Sara: grade = %.1f\n", s.grade);
    fclose(fp);

    return 0;
}