#include <stdio.h>


void cyclic_shift(int array[], int k) {
    int i, temp;
    temp = array[k - 1];
    for (i = k - 1; i >= 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = temp;
}


void print_array(int array[], const int array_length) {
    for (int i = 0; i < array_length; i++) printf("%3d ", array[i]);
    printf("\n");
}


int main() {
    int i, n, k, array_length;

//    printf("Введите длину массива: ");
//    int check = scanf("%d", &array_length);
//    if (check != 1) {
//        printf("Некорректный ввод\n");
//        return 0;
//    }
//    int array[array_length];
//    for (i = 0; i < array_length; i++) { array[i] = i; }
    array_length = 3;
    int array[] = {1, 2, 3};

    k = array_length;
    n = array_length;
    while (k >= 0) {
        print_array(array, array_length);
        k = n;
        cyclic_shift(array, array_length);
        while ((array[k-1] == k) && (k >= 0)) {
            k = k - 1;
            cyclic_shift(array, array_length);
        }
    }
    return 0;
}
