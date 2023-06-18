#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Задана строка символов, каждое слово – последовательность, состоящая из одних цифр.
// Рассматривая каждое слово как число, определить сумму четных и нечетных значений элементов массива.

int main() {
    FILE *fp;
    fp = fopen("../practice/p5.txt", "r");
    char line[100];
    fgets(line, 100, fp);
    char *temp;
    int count = 0;

    int ch_sum, nech_sum;
    ch_sum = 0;
    nech_sum = 0;

    temp = strtok(line, " ");
    printf("Введённые числа: ");
    while (temp != NULL) {
        int number = atoi(temp);
        count++;

        if (number % 2 == 0) ch_sum += number; else nech_sum += number;

        printf("%d ", number);
        temp = strtok(NULL, " ");
    }
    printf("\nСумма чётных элементов: %d\n", ch_sum);
    printf("Сумма нечётных элементов: %d\n", nech_sum);

    fclose(fp);
    return 0;
}