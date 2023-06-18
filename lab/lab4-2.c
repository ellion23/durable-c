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


void comb_sort(int array[], int n, int *count) {
    int gap = n;
    int swaps = 1;
    int i, j;

    while (gap > 1 || swaps) {
        gap = (int) (gap / 1.24733);
        if (gap < 1)
            gap = 1;
        (*count)++;
        swaps = 0;
        for (i = 0; i < n - gap; ++i) {
            j = i + gap;
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
                (*count)++;
                swaps = 1;
            }
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
    FILE *f = fopen("../lab/data3.csv", "w");
    for (int n = 100; n <= 10000; n += 100) {
        all = 0;
        for (i = 0; i < 40; i++) {
            count = 0;
            array = malloc(n * sizeof(int));
            fill_array(array, n);
            comb_sort(array, n, &count);
            free(array);
            all += count;
        }
        count = all / i;
        fprintf(f, "%d; %d\n", n, count);
    }

    fclose(f);
    return 0;
}