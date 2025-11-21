#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

/**
 * @brief считывает целочисленное значение.
 * @return целое значение.
 */
int GetInt(void);

/**
 * @brief считывает неотрицательное целое число.
 * @return неотрицательное целое значение.
 */
int GetNonNegativeInt(void);

/**
 * @brief вычисляет сумму на основе заданного значения count.
 * @param count количество слагаемых, используемых при расчете суммы.
 * @return вычисленную сумму в виде double.
 */
double GetSumCount(const int count);

/**
 * @brief вычисляет значение на основе рекуррентного отношения.
 * @param k - параметр, используемый при повторном вычислении.
 * @return вычисленное значение в виде double.
 */
double GetReccurent(const int k);

/**
 * @brief считывает число с плавающей запятой.
 * @return число типа double.
 */
double GetDouble(void);

/**
 * @brief считывает положительное число с плавающей запятой.
 * @return положительное число типа double.
 */
double GetEpsilon(void);

/**
 * @brief вычисляет сумму на основе значения epsilon.
 * @param epsilon - пороговое значение, используемое для остановки вычисления суммы.
 * @return вычисленную сумму на основе указанного значения epsilon.
 */
double GetSumEpsilon(const double epsilon);

/**
 * @brief точка входа в программу
 * @return возвращает 0 в случае успеха
 */
int main(void)
{
    puts("Введите верхний порог");
    int count = GetNonNegativeInt();
    puts("Введите погрешность");
    double epsilon = GetEpsilon();
    printf("Сумма %d членов: %lf\n", count, GetSumCount(count));
    printf("Сумма членов с погрешностью: %lf\n", GetSumEpsilon(epsilon));
    return 0;
}

int GetInt(void)
{
    int a = 0;
    int result = scanf("%d", &a);
    if (result != 1)
    {
        fprintf(stderr, "Ошибка ввода: введенное значение не является целым числом\n");
        exit(EXIT_FAILURE);
    }

    return a;
}

int GetNonNegativeInt(void)
{
    int a = GetInt();
    if (a <= 0)
    {
        fprintf(stderr, "Ошибка ввода: число должно быть положительным\n");
        exit(EXIT_FAILURE);
    }

    return a;
}

double GetSumCount(const int count)
{
    double summ = 0;
    double current = -8.0;
    for (int k = 1; k <= count; ++k)
    {
        summ += current;
        if (k < count) {
            current *= GetReccurent(k);
        }
    }

    return summ;
}

double GetReccurent(const int k)
{
    return -(pow(k + 2, 3)) / (pow(k + 1, 3) * (k + 1));
}

double GetDouble(void)
{
    double a = 0.0;
    int result = scanf("%lf", &a);
    if (result != 1)
    {
        fprintf(stderr, "Ошибка ввода: введенное значение не является числом\n");
        exit(EXIT_FAILURE);
    }

    return a;
}

double GetEpsilon(void)
{
    double epsilon = GetDouble();
    if (epsilon <= DBL_EPSILON)
    {
        fprintf(stderr, "Ошибка ввода: погрешность должна быть больше машинного эпсилон\n");
        exit(EXIT_FAILURE);
    }

    return epsilon;
}

double GetSumEpsilon(const double epsilon)
{
    double summ = 0;
    double current = -8.0;
    int k = 1;

    while (fabs(current) >= epsilon)
    {
        summ += current;
        current *= GetReccurent(k);
        k++;
    }

    return summ;
}