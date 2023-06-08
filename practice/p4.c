#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int vall;

double func(double x) {
    // Здесь задаем функцию, корень которой мы ищем
    // В комментарии после функции указаны приблизительные значения
    return pow(x, 4) - 0.48*pow(x, 3) - 5.792*pow(x, 2) + 0.486*x + 4.792; // -2, -1, 1, 2
//    return 0.1*sin(x) + pow(x, 3) - 1;  // 1
//    return 0.1*exp(x) - pow(sin(x), 2) + 0.5; // -1 в периоде, 1
}

Алгоритм метода.
1. Определяем по графику приближённое значение корня

x^4 - 0.48 * x^3 - 5.792 * x^2 + 0.486 * x + 4.792
0.1 * sin(x) + x^3 - 1
0.1 * exp(x) - (sin(x))^2 + 0.5

double proisvodnaya(double x) {
    // Здесь задаем производную функции
    return 4*pow(x, 3) - 36*pow(x, 2)/25 - 1448*x/125 + 243. / 500;
//    return 3*x*x + 0.1*cos(x);
//    return 0.1*exp(x) - 2*sin(x)*cos(x);
}


double method_kasatelnyh(double x0, double epsilon) {
    double x1 = x0 - func(x0) / proisvodnaya(x0);
    while(fabs(x1 - x0) > epsilon) {
        x0 = x1;
        x1 = x0 - func(x0) / proisvodnaya(x0);
        vall++;
    }
    return x1;
}


int main() {
    system("chcp 65001");
    double x0;
    double epsilon;
    x0 = 2.;
    epsilon = 10.;
    double root;

    for (int i = 0; i < 7; i++) {
        printf("-----my-----\n");
        epsilon /= 10;
        vall = 0;
        root = method_kasatelnyh(x0, epsilon);
        printf("Корень: %lf Итерации: %d      | %lf\n", root, vall, epsilon);
        printf("-not-my-----\n");
        printf("\n");
    }

    return 0;
}
