#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* @brief функция для вычисления значения а
* @param count значение переменной cnt
* @param f значение переменной f
* @return результат  вычисления а
*/

double Input(void);
/**
* @brief вычисляет функцию
* @param a параметр, данный в таблице
* @param x значение, введенное пользователем
* @return значение функции
*/

double y(const double a, const double x);

/**
* @brief точка входа в программу
* @return 0 в случае успеха
*/

int main(void)
{
    const double a = 0.3;
    puts("Введите значение x");
    const double x = Input();
    printf("Значение функции:%lf при x равном %lf", y(a, x), x);
    return 0;
}
double Input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        printf("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}
double y(const double a, const double x)
{
    if (a * x < 1)
    {
        return a * sin((pow(x, 2) + 1) / 10);
    }
    return a * cos((x - 1) / 10);
}