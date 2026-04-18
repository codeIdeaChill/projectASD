#include <stdio.h>

/* =================================================================
   1. تعريف الوحدات الفرعية (Sub-programs Definitions)
   ================================================================= */

/** * إجراء التحويل: يحول من سيلسيوس إلى فهرنهايت.
 * المعامل الأول بالقيمة (لا يتغير)، الثاني بالعنوان (لتخزين النتيجة).
 */
void ConvertToF(float C, float *F_conv) {
    // استخدام 9.0 و 5.0 لضمان القسمة العشرية [cite: 1237]
    *F_conv = C * (9.0 / 5.0) + 32.0;
}

/** * إجراء التعديل: يضيف 5 للأول ويطرح 3 من الثاني.
 * التغييرات يجب أن تؤثر على المتغيرات الأصلية (Call by Address)[cite: 1239, 1240].
 */
void AdjustTemps(float *T1, float *T2) {
    *T1 = *T1 + 5.0;
    *T2 = *T2 - 3.0;
}

/** * دالة الحرارة الأعلى: تعيد القيمة الأكبر بين درجتين[cite: 1241].
 * تمرير بالقيمة لأنها لا تعدل المدخلات.
 */
float HigherTemp(float T1, float T2) {
    if (T1 > T2) {
        return T1;
    } else {
        return T2;
    }
}

/** * إجراء التبديل: يبدل بين قيمتين بدون متغير مؤقت (Swap without temp variable)[cite: 1242].
 * يجب استخدام المؤشرات (*) للتأثير على المتغيرات الأصلية[cite: 1248].
 */
void Swap(float *X, float *Y) {
    *X = *X + *Y;
    *Y = *X - *Y;
    *X = *X - *Y;
}

/* =================================================================
   2. البرنامج الرئيسي (Main Program)
   ================================================================= */
int main() {
    // تعريف المتغيرات الأصلية [cite: 1236]
    float TempC, TempFconverted;

    // أ. طلب إدخال البيانات [cite: 1244]
    printf("Enter Temp in Celsius (TempC) and Fahrenheit (TempFconverted): \n");
    scanf("%f %f", &TempC, &TempFconverted);

    // ب. استدعاء إجراء التحويل [cite: 1245]
    // نمرر عنوان المتغير الثاني ليتم تحديثه داخل الإجراء
    ConvertToF(TempC, &TempFconverted);

    // ج. استدعاء إجراء التعديل [cite: 1247]
    // نمرر العناوين لأن التغيير يجب أن يؤثر على المتغيرات الأصلية
    AdjustTemps(&TempC, &TempFconverted);

    // د. المقارنة والتبديل [cite: 1248]
    // إذا كانت الحرارة الأعلى هي TempC، نقوم بالتبديل
    if (HigherTemp(TempC, TempFconverted) == TempC) {
        Swap(&TempC, &TempFconverted);
    }

    // هـ. عرض النتائج النهائية [cite: 1249]
    printf("\n--- Final Results ---\n");
    printf("Final TempC = %.2f\n", TempC);
    printf("Final TempFconverted = %.2f\n", TempFconverted);

    return 0;
}