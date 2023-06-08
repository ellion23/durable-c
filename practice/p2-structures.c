#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  По индивидуальному варианту написать функции:
//  1.	Считывания данных из текстового файла в массив (В текстовом файле должно находиться не менее 20 записей)
//  2.	Поиска нужной информации в полученном массиве.
//  Использовать структурные переменные.
//
//  Исходные данные хранятся в файле.
//
//         Страна.	Наименование товара. 	Объем экспорта.
//
//  Составить список по заданному наименованию товара и объему экспорта.
//  Использовать структурные переменные.


typedef struct  {
    char country[50];
    char name[50];
    int export_volume;
} export_data;


int read_file(FILE* file, export_data* data) {
    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%s %s %d", data[i].country, data[i].name, &data[i].export_volume);
//        printf("%s %s %d \n", data[i].country, data[i].name, data[i].export_volume);
        i++;
    }
    return i;
}

void find(export_data* data, int n) {
    char name[50];
    int exp;
    printf("Введите наименование товара и объём экспорта: ");
    int check = scanf("%s %d", name, &exp);
    if (check != 2) {
        printf("Неверный ввод\n");
        exit(1);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        check = strcmp(name, data[i].name);

        if (!check && exp == data[i].export_volume) {
            printf("%s %s %d\n", data[i].country, data[i].name, data[i].export_volume);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Данных не найдено\n");
    }

}

int main() {
    char* filename = "../practice/p2.txt";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    export_data data[50];
    int count = read_file(file, data);
    find(data, count);
    return 0;
}