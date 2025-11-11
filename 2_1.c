#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Объявления функций

/**
 * @brief Вычисляет площадь одной грани куба.
 * @param a Длина ребра куба.
 * @return Площадь одной грани.
 */
    double face_area(double a);

/**
 * @brief Вычисляет площадь полной поверхности куба.
 * @param a Длина ребра куба.
 * @return Площадь полной поверхности.
 */
double total_surface_area(double a);

/**
 * @brief Вычисляет объем куба.
 * @param a Длина ребра куба.
 * @return Объем куба.
 */
double volume(double a);

/**
 * @brief Безопасно считывает число с плавающей точкой.
 * @return Число типа double.
 */
double input(void);


int main(void) {
    printf("Введите длину ребра куба: ");
    double a = input();

    printf("Площадь одной грани: %.2f\n", face_area(a));
    printf("Площадь полной поверхности: %.2f\n", total_surface_area(a));
    printf("Объем куба: %.2f\n", volume(a));

    return 0;
}


double face_area(double a) {
    return a * a;
}

double total_surface_area(double a) {
    return 6 * a * a;
}

double volume(double a) {
    return a * a * a;
}

double input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        fprintf(stderr, "Ошибка: введенное значение не является числом\n");
        exit(EXIT_FAILURE);
    }
    return value;
}
