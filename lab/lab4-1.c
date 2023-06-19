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


void comb_sort(int array[], int n, int *count) {
    int step = n;
    int swaps = 1;
    int i, j;

    while (step > 1 || swaps) {
        step = (int) (step / 1.24733);
        if (step < 1)
            step = 1;
        (*count)++;
        swaps = 0;
        for (i = 0; i < n - step; ++i) {
            j = i + step;
            if (array[i] > array[j]) {
                swap(&array[i], &array[j]);
                (*count)++;
                swaps = 1;
            }
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
    comb_sort(array, n, &count);
    print_array(array, n);
    printf("%d\n", count);

    return 0;
}