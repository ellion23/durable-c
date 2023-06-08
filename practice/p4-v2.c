#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x, int equation) {
    switch (equation) {
        case 1:
            return pow(x, 4) - 0.48 * pow(x, 3) - 5.792 * pow(x, 2) + 0.486 * x + 4.792; // -2, -1, 1, 2
        case 2:
            return 0.1 * sin(x) + pow(x, 3) - 1;  // 1
        case 3:
            return 0.1 * exp(x) - pow(sin(x), 2) + 0.5; // -1 в периоде, 1; -4 -2.5 -1 1 1.5
    }
    printf("Неверный номер уравнения.");
    exit(0);
}

double df(double x, int equation) {
    switch (equation) {
        case 1:
            return 4 * pow(x, 3) - 36 * pow(x, 2) / 25 - 1448 * x / 125 + 243. / 500;
        case 2:
            return 3 * x * x + 0.1 * cos(x);
        case 3:
            return 0.1 * exp(x) - 2 * sin(x) * cos(x);
    }
}

double method_kasatelnih(double x0, double epsilon, int equation) {
    double x = x0;
    int iter = 0;
    double delta = fabs(f(x, equation) / df(x, equation));

    while (delta >= epsilon) {
        x = x - f(x, equation) / df(x, equation);
        delta = fabs(f(x, equation) / df(x, equation));
        iter++;
    }

    printf("Корень: %.5lf, найденный за %d итераций", x, iter);


    return x;
}

void check_input(int a, int b) {
    if (a != b) {
        printf("Некорректный ввод");
        exit(0);
    }
}

int main() {
    system("chcp 65001");
    double x0;
    double epsilon;
    int eq;
    printf("Введите номер уравнения: ");
    int check = scanf("%d", &eq);
    check_input(check, 1);
    printf("Введите приближённое значение и точность: ");
    check = scanf("%lf %lf", &x0, &epsilon);
    check_input(check, 2);
    method_kasatelnih(x0, epsilon, eq);
    return 0;
}
