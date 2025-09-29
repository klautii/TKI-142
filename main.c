
#include <stdio.h>
#include <math.h>

/**
* @brief Рассчитывает значение функции A
* @param x - значение параметра x
* @return Рассчитанное значение
*/
double getA(double x, const double y, const double z);
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
    const double x = 2.2f;
    const double y = 9.2f;
    const double z = 10.2f;

    /*Вывод с нужной точностью*/
    printf("A = %.6f\n", getA(x, y, z));
    printf("B = %.6f\n", getB(x, y, z));
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return (log(z + x * x) + sin(x / y) * sin(x / y));
}
double getB(const double x, const double y, const double z)
{
    return ((-z) * (x + sqrt(x + z))) / (x - sqrt(abs(x - y)));
}