#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

/**
* @brief Безопасный ввод числа
* @return введенное число
*/
double Input(void);

/**
* @brief вычисляет функцию по заданной формуле
* @param a параметр a = 0.3
* @param x значение, введенное пользователем
* @return значение функции y
*/
double y(const double a, const double x);

/**
* @brief точка входа в программу
* @return 0 в случае успеха
*/
int main(void)
{
    const double a = 0.3;

    puts("Введите значение x:");
    const double x = Input();
    printf("Значение функции: %lf при x равном %lf\n", y(a, x), x);

    return 0;
}

double Input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        fprintf(stderr, "Ошибка: введенное значение не является числом\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double y(const double a, const double x)
{
    double product = a * x;

    if (product < 1.0 + DBL_EPSILON)
    {
        return a * sin((pow(x, 2) + 1) / 10);
    }
    else
    {

        return a * cos((x - 1) / 10);
    }
}

