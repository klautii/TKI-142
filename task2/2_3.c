#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

/**
* @brief считывает вещественное число
* @return вещественное число
*/

double Input(void);

/**
* @brief считывает вещественное число с проверкой знака
* @return вещественное число в случае, если оно больше нуля
*/

double PInput(void);

/**
* @brief определяет существует ли треугольник со сторонами x y z
* @param x длина 1 стороны треугольника
* @param y длина 2 стороны треугольника
* @param z длина 3 стороны треугольника
* @return true, если подходит и false, если не подходит
*/

bool isSharpTriangle(const double x, const double y, const double z);

/**
* @brief точка входа в программу
* @return 0 в случае успеха
*/

int main(void)
{
    printf("Введите длину 1 стороны x треугольника \n");
    const double x = PInput();
    printf("Введите длину 2 стороны y треугольника \n");
    const double y = PInput();
    printf("Введите длину 3 стороны z треугольника \n");
    const double z = PInput();
    if (isSharpTriangle(x, y, z))
    {
        printf("треугольник остроугольный\n");
    }
    else
    {
        printf("треугольник неостроугольный\n");
    }

    return 0;
}

double Input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}

double PInput(void)
{
    double value = Input();
    if (value <= DBL_EPSILON)
    {
        puts("Некорректное значение длины");
        exit(EXIT_FAILURE);
    }
    return value;
}

bool isSharpTriangle(const double x, const double y, const double z)
{
    return (pow(x, 2) < (pow(y, 2) + pow(z, 2)));
}
