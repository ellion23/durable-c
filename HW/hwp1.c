#include <stdio.h>


void read_file(FILE *fp, int matrix[4][4]) {
    int i, j;
    // Открываем файл для чтения
    // Считываем матрицу из файла
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }

}


void print_minors(int matrix[4][4]) {
    int i, j, m, n;

    for (m = 0; m < 4; m++) {
        for (n = 0; n < 4; n++) {
            printf("\n Минор: \n");
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    if (m != i && n != j) {
                        printf("%4d", matrix[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
}


void printf_matrix(int matrix[4][4]) {
    int i, j;
    // Выводим исходную матрицу
    printf("Matrix: \n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


int main() {
    system("chcp 1251");
    int n = 4;
    int matrix[n][n];

    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 2;
    }

    read_file(fp, matrix);

    printf_matrix(matrix);

    print_minors(matrix);

    int matrix2[n][n];

    read_file(fp, matrix2);

    printf_matrix(matrix2);

    print_minors(matrix2);


    return 0;
}
