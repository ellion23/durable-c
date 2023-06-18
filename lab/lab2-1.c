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


void selection_sort(int *array, const int n, int *count) // array you want to be sorted; its length
{
    int min_value_index, i, j;
    for (i = 0; i < n; i++) {
        min_value_index = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_value_index]) {
                min_value_index = j;
            }
            (*count)++;
        }
        swap(&array[i], &array[min_value_index]);
        (*count)++;
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

    fill_array(array, n);
    print_array(array, n);
    selection_sort(array, n, &count);
    print_array(array, n);
    printf("%5d", count);

    return 0;
}