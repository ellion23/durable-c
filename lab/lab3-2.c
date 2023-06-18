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


void insertion_sort(int array[], int n, int *count) {
    int element, index, i;
    index = 0;
    for (i = 1; i < n; i++) {
        if (array[i] < array[index]) {
            index = i;
        }
        (*count)++;
    }
    (*count)++;
    swap(&array[index], &array[0]);

    for (i = 1; i < n; i++) {
        element = array[i];
        index = i - 1;
        while (index >= 0 && array[index] > element) {
            array[index + 1] = array[index];
            (*count) += 2;
            index = index - 1;
        }
        array[index + 1] = element;
    }
}


void print_array(int array[], const int n) // print array to std output; array, length
{
    for (int i = 0; i < n; i++) printf("%5d ", array[i]);
    printf("\n");
}


void fill_array(int array[], const int n) {
    int maxvalue = 10000;
    int maxvalue2 = maxvalue*2;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % maxvalue2 - maxvalue;
    }
}


int main()
{
    srand(time(NULL));
    int *array;
    int count;
    FILE *f = fopen("../lab/data.csv", "w");
    for (int n = 100; n <= 10000; n += 100) {
        count = 0;
        array = malloc(n * sizeof(int));
        fill_array(array, n);
        selection_sort(array, n, &count);
        fprintf(f, "%d; %d\n", n, count);
    }

    fclose(f);
    return 0;
}