
#include <stdio.h>
#include <math.h>

/**
* @brief Рассчитывает значение функции A
* @param x - значение параметра x
* @return Рассчитанное значение
*/
double getA(const double x, const double y, const double z);
/**
* @brief Рассчитывает значение функции B
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return Рассчитанное значение
*/
double getB(const double x, const double y, const double z);
/**
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена корректно, иначе 1
*/
int main(void)
{
    /*Объявляем константы*/
    const double x = 2.2;
    const double y = 9.2;
    const double z = 10.2;

    /*Вывод с нужной точностью*/
    printf("A = %.6f\n", getA(x, y, z));
    printf("B = %.6f\n", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (log(z + x * x) + pow(sin(x / y), 2));
}
double getB(const double x, const double y, const double z)
{
    return exp(-(z)) * ((x + sqrt(x + z)) / (x - sqrt(fabs(x - y))));
}
