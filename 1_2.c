#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
* @brief Функция вычисления среднего арифметического кубов двух чисел
* @param a - Первое число
* @param b - Второе число
* @return Возвращает среднее арифметическое кубов чисел
*/
double srednee_arif(const double a, const double b);

/**
* @brief Функция вычисления среднего геометрического модулей двух чисел
* @param a - Первое число
* @param b - Второе число
* @return Возвращает среднее геометрическое модулей чисел
*/
double srednee_geom(const double a, const double b);

/**
* @brief Функция ввода чисел. Считывание значений с клавиатуры
* @param num - Указатель на переменную для сохранения введённого числа
* @return Возвращает 1 если ввод корректен, иначе 0
*/
int getValue(void);

/**
* @brief Точка входа в программу
* @return Возвращает 0 если программа выполнена корректно, иначе 1
*/
int main(void)
{
    char* locale = setlocale(LC_ALL, "");

    printf("Введите первое число: ");
    double a = getValue();
    printf("Введите второе число: ");
    double b = getValue();
    printf("Среднее арифметическое кубов чисел: %.2f\n", srednee_arif(a,b));
    printf("Среднее геометрическое модулей чисел: %.2f\n", srednee_geom(a,b));

    return 0;
}

int getValue(void)
{
    double num = 0;
    scanf("%lf", &num);
    return num;
}

double srednee_arif(const double a, const double b)
{
    return (pow(a, 3) + pow(b, 3)) / 2.0;
}

double srednee_geom(const double a, const double b)
{
    return sqrt(fabs(a) * fabs(b));
}
