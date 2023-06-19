#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) // example of function call: swap(&x, &y);
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


void merge(int array[], int n, int *count) {
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int *c = (int *) malloc(n * sizeof(int));
    int step;
    while (h < n) {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid) {
            while ((i < step) && (j < n) && (j < (mid + step))) { // пока не дошли до конца пути
                // заполняем следующий элемент формируемой последовательности
                // меньшим из двух просматриваемых
                if (array[i] < array[j]) {
                    c[k] = array[i];
                    (*count)++;
                    i++;
                    k++;
                } else {
                    c[k] = array[j];
                    (*count)++;
                    j++;
                    k++;
                }
                (*count)++;
            }
            while (i < step) { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = array[i];
                (*count)++;
                i++;
                k++;
            }
            while ((j < (mid + step)) &&
                   (j < n)) {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                (*count) += 2;
                c[k] = array[j];
                j++;
                k++;
            }
            step = step + h; // переходим к следующему этапу
            (*count)++;
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < n; i++) {
            array[i] = c[i];
            (*count)++;
        }
    }
}


void print_array(int array[], const int n) // print array to std output; array, length
{
    for (int i = 0; i < n; i++) printf("%5d ", array[i]);
    printf("\n");
}


void fill_array(int array[], const int n) {
    int maxvalue = 10000;
    int maxvalue2 = maxvalue * 2;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % maxvalue2 - maxvalue;
    }
}


int main() {
    srand(time(NULL));
    int *array;
    int count;
    int i;
    int all;
    FILE *f = fopen("../lab/data4.csv", "w");
    for (int n = 100; n <= 100; n += 100) {
        all = 0;
        for (i = 0; i < 40; i++) {
            count = 0;
            array = malloc(n * sizeof(int));
            fill_array(array, n);
            merge(array, n, &count);
            free(array);
            printf("%d\n", count);
            all += count;
        }
        count = all / i;
        printf("%d\n", count);
        fprintf(f, "%d; %d\n", n, count);
    }

    fclose(f);
    return 0;
}