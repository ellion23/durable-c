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

    for (i = 2; i < n; i++) {
        element = array[i];
        index = i - 1;
        while (array[index] > element) {
            array[index + 1] = array[index];
            (*count)++;
            index = index - 1;
        }
        array[index + 1] = element;
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
    insertion_sort(array, n, &count);
    print_array(array, n);
    printf("%d\n", count);

    return 0;
}