#include <stdio.h>
#include <stdlib.h>
// Вычислить количество цифр натурального числа


int recursive_digit_count(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + recursive_digit_count(n / 10);
    }
}


int digit_count(int n) {
    int s = 0;
    while (n != 0) {
        n = n / 10;
        s++;
    }

    return s;
}


int main() {
    int n;

    printf("Введите натуральное число: ");
    int check = scanf("%d", &n);
    if (check != 1) {
        printf("Некорректный ввод\n");
        exit(2);
    }
    printf("Количество цифр (рекурсивная функция): %d\n", recursive_digit_count(n));
    printf("Количество цифр (нерекурсивная функция): %d\n", digit_count(n));
    return 0;
}
