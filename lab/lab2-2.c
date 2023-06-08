#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int count;


void swap(int *a, int *b) // example of function call: swap(&x, &y);
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


void selection_sort(int *array, const int n) // array you want to be sorted; its length
{
    int min_value_index, i, j;
    for (i = 0; i < n; i++) {
        min_value_index = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_value_index]) {
                min_value_index = j;
            }
            count++;
        }
        swap(&array[i], &array[min_value_index]);
        count++;
    }
}


void print_array(int array[], const int n) // print array to std output; array, length
{
    for (int i = 0; i < n; i++) printf("%5d ", array[i]);
    printf("\n");
}


void fill_array(int array[], const int n)
{
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 2000 - 1000;
    }
}


int main()
{
    srand(time(NULL));
    int *array;
    FILE *f = fopen("data.csv", "w");
    for (int n = 100; n <= 10000; n += 100) {
        count = 0;
        array = malloc(n * sizeof(int));
        fill_array(array, n);
        selection_sort(array, n);
        fprintf(f, "%d; %d\n", n, count);
    }

    fclose(f);
    return 0;
}