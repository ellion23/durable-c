#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double func(double x) {
    // Здесь задаем функцию, корень которой мы ищем
    // В комментарии после функции указаны приблизительные значения
    return pow(x, 4) - 0.48*pow(x, 3) - 5.792*pow(x, 2) + 0.486*x + 4.792; // -2, -1, 1, 2
//    return 0.1*sin(x) + pow(x, 3) - 1;  // 1
//    return 0.1*exp(x) - pow(sin(x), 2) + 0.5; // -1 в периоде, 1
}


double proisvodnaya(double x) {
    // Здесь задаем производную функции
    return 4*pow(x, 3) - 36*pow(x, 2)/25 - 1448*x/125 + 243 / 500;
//    return 3*x*x + 0.1*cos(x);
//    return 0.1*exp(x) - 2*sin(x)*cos(x);
}


double method_kasatelnyh(double x0, double epsilon) {
    double x1 = x0 - func(x0) / proisvodnaya(x0);
    while(fabs(x1 - x0) > epsilon) {
        x0 = x1;
        x1 = x0 - func(x0) / proisvodnaya(x0);
    }
    return x1;
}


int main() {
    double x0;   // Задаем начальное приближение
    double epsilon;     // Задаем точность
    printf("Введите начальное приближение и точность вычислений: ");
    int check = scanf("%lf %lf", &x0, &epsilon);
    if (check != 2) {
        printf("Некорректный ввод\n");
        exit(0);
    }
    double root = method_kasatelnyh(x0, epsilon);   // Находим корень
    printf("Корень: %lf\n", root);
    return 0;
}
