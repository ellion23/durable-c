#ifndef CLIONPROJECT_USEFUL_H
#define CLIONPROJECT_USEFUL_H


// example of function call: swap(&x, &y);
void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


// print array to std output; array, length
void print_array(int array[], const int n) {
    for (int i = 0; i < n; i++) printf("%5d ", array[i]);
    printf("\n");
}


// array you want to be sorted; its length
void selection_sort(int *array, const int n, int *count) {
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


// need to use srand(time(NULL)) in start of prog
void fill_array(int array[], const int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 2000 - 1000;
    }
}


#endif //CLIONPROJECT_USEFUL_H
