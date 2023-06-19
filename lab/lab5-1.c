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


void print_array(int array[], const int n) // print array to std output; array, length
{
    for (int i = 0; i < n; i++) printf("%5d ", array[i]);
    printf("\n");
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
                    i++;
                    k++;
                } else {
                    c[k] = array[j];
                    j++;
                    k++;
                }
            }
            while (i < step) { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = array[i];
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


void fill_array(int array[], const int n) {
    int maxvalue = 100;
    int maxvalue2 = maxvalue * 2;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % maxvalue2 - maxvalue;
    }
}


int main() {
    int count = 0;
    int n;
    printf("Введите размерность массива: ");
    int check = scanf("%d", &n);
    if (!check || n <= 0) {
        printf("Input error\n");
        exit(2);
    }
    srand(time(NULL));
    int *array = malloc(n * sizeof(int));
    printf("До:\n");
    fill_array(array, n);
    print_array(array, n);
    printf("После:\n");
    merge(array, n, &count);
    print_array(array, n);
    printf("%d\n", count);

    return 0;
}