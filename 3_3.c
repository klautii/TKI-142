#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Проверяет корректность ввода размера массива и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
float validate_input(const char* message);

/**
 * @brief Вычисляет значение atan(x).
 * @param x - Аргумент функции.
 * @return Значение atan(x).
 */
double GetEPowerX(double x);

/**
 * @brief Вычисляет текущий член рекуррентного ряда.
 * @param x - Аргумент ряда.
 * @param n - Порядковый номер члена ряда.
 * @return Значение текущего члена рекуррентного ряда.
 */
double GetRecurrent(double x, double n);

/**
 * @brief Вычисляет сумму ряда с заданной точностью e.
 * @param x - Аргумент ряда.
 * @param e - Точность вычисления суммы ряда.
 * @return Значение суммы ряда.
 */
double GetSumOfSeries(double x, double e);

/**
 * @brief Форматирует вывод для заданных значений аргумента, функции и ряда.
 * @param argument - Значение аргумента.
 * @param function - Значение функции (atan(x)).
 * @param series - Значение суммы ряда.
 */
void FormatOutput(double argument, double function, double series);

/**
 * @brief Проверяет корректность интервала и шага.
 * @param xStart Начальное значение интервала.
 * @param xFinish Конечное значение интервала.
 * @param xStep Шаг интервала.
 */
void check_interval(double xStart, double xFinish, double xStep);

/**
 * @brief Проверяет условия для значения epsilon.
 * @param e - Значение точности для проверки.
 * @param firstTerm - Значение первого члена последовательности.
 * @return true, если условия выполняются, иначе false.
*/
void checkEpsilonConditions(float e, float firstTerm);

/**
 * @brief Основная функция программы.
 * @return Возвращает 0 в случае успешного выполнения программы, иначе 1.
 */
int main() {

    const float xStart = validate_input("Введите начальное значение x: ");
    const float xFinish = validate_input("Введите конечное значение x: ");
    const float xStep = validate_input("Введите шаг x: ");
    const float e = validate_input("Введите точность epsilon: ");

    check_interval(xStart, xFinish, xStep);
    checkEpsilonConditions(e, xStart);

    double x = xStart;
    while (x <= xFinish + DBL_EPSILON)
    {
        FormatOutput(x, GetEPowerX(x), GetSumOfSeries(x, e));
        x += xStep;
    }

    return 0;
}

float validate_input(const char* message) {
    float input;
    printf("%s", message);

    if (scanf_s("%f", &input) != 1) {
        printf("Ошибка ввода\a");
        exit(EXIT_SUCCESS);
    }

    return input;
}

double GetEPowerX(const double x)
{
    return atan(x);
}

double GetRecurrent(double x, double n)
{
    return -(n * 2 + 1) * pow(x, 2) / (n * 2 + 3);
}

double GetSumOfSeries(const double x, const double e)
{
    double current = x;
    double sum = 0;
    double n = 0;

    while (fabs(current) > e - DBL_EPSILON) {
        sum += current;
        current *= GetRecurrent(x, n);
        n++;
    }

    return sum;
}

void FormatOutput(const double argument, const double function, const double series)
{
    printf("%10.1f | %15.6f | %15.6f\n", argument, function, series);
}

void check_interval(double xStart, double xFinish, double xStep) {
    if (xFinish - xStart < DBL_EPSILON) {
        printf("Неправильно введен интервал");
        exit(EXIT_FAILURE);
    }
    else if (xStep < DBL_EPSILON) {
        printf("Неправильно введен шаг");
        exit(EXIT_FAILURE);
    }
}

void checkEpsilonConditions(float e, float firstTerm) {
    if (e > -DBL_EPSILON || e <= fabs(firstTerm)) {
        puts("Ошибка ввода");
        exit(EXIT_FAILURE);
    }
}