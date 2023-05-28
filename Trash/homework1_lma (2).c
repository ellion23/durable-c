#include <stdio.h> //12 вариант
#include <stdlib.h>

int main() {
    system("chcp 1251");
    char Fname[20]; //Создаем список
    int i = 0;
    int det; //Переменная под определитель матрицы
    int part1; //Так как определитель мы высчитываем по правилу треугольнику, то создаем переменные со знаком + и -
    int part2;

    printf("Enter the name of the text file:");
    scanf("%s", Fname); //вводим нужный файл

    FILE *f1; //Создаем переменную под файл и открываем ее с режимом чтения
    int z;
    f1 = fopen(Fname, "r");
    if (f1 == NULL) { //проверка файла на успех открытия
        printf("File is not created.\n");
        system("PAUSE");
        return 0;
    }

    int *A = (int *) malloc(sizeof(int) * 9); //Создаем массив и выделяем память для 9 элементов матрицы
//    printf("The resulting matrix: \n");
    int flag = 0;

//    while (!feof(f1)) //пока положение в файле не достигнет конца
//    {
//        if ((i >= 3) && (i % 3 == 0)){ //принтуем на следующую строку матрицы 3 на 3
//            printf("\n");
//        }
//
//         //считываем элемент списка и проверяем на корректность
//        printf("%8.3d ", z);
//        A[i] = z; //записываем в массив значение
//        i++;
//    }



// -------------------------------------
for (int k = 0; k < 2; k++) {
	flag = 0;
        for (i = 0; i < 9; i++) {
            int y = fscanf(f1, "%d", &z);
        	if (y != 1){
        		flag = 1;
        		break;
			}
            A[i] = z;
            printf("%3d", A[i]);
            if (i == 2 || i == 5 || i == 8) {
                printf("\n");
            }
        }
    if (flag){
        printf("\nError\n");
        continue;
        }

        if (i != 9) //Проверяем на успех введенных данных
        {
            printf("\n Data not entered.");
            system("PAUSE");
            return 0;
        }

//        // Вывести матрицу
//        printf("Matrix: \n");
//        for (i = 0; i < 9; i++) {
//
//        }

        part1 = (A[0] * A[4] * A[8]) + (A[2] * A[3] * A[7]) +
                (A[1] * A[5] * A[6]); //сумма первого треугольника по главной диагонали
        part2 = (A[2] * A[4] * A[6]) + (A[3] * A[1] * A[8]) +
                (A[7] * A[5] * A[0]); //сумма второго треугольника по побочной диагонали
        det = part1 - part2; //Полученный определитель по формуле

        printf("\n3rd order matrix determinant = %d ", det); //Вывод
        printf("\n");
}

// -------------------------------------



    free(A);
    fclose(f1);
    system("PAUSE");
    return 0;
}