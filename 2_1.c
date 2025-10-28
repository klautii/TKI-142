#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
*@brief функция для вычисления значения а
* param count значение переменной cnt
* param f значение переменной f
* @return результат  вычисления а
*/

double get_a(const double count, const double f);

/*
*@brief функция для вычисления значения sr_arifm
* param count значение переменной cnt
* param f значение переменной f
* @return результат  вычисления sr_arifm
*/

double sr_arifm(const double count, const double f);

/*
*@brief функция считывает ввод пользователя с проверкой
* @return введенное число типа double
*/

double input(void);


/*
*@brief точка входа в программу
* @return в случае успеха
*/

int main(void) {
    puts("Enter the count:");
    double count = input();
    puts("Enter the f:");
    double f = input();
    printf("a = %f\n", get_a(count, f));
    printf("%f", sr_arifm(count, f));
    return 0;
}
double input(void)
{
    double number = 0.0;
    if (scanf_s("%lf", &number) != 1)
    {
        puts("Неверный ввод");
        exit(EXIT_FAILURE);
    }

    return number;
}
double get_a(const double count, const double f) {
    return sqrt(fabs(pow(count, 3)) * fabs(pow(f, 3)));
}
double sr_arifm(const double cnt, const double f) {
    return (fabs(pow(cnt, 3)) * fabs(pow(f, 3))) / 2;
}