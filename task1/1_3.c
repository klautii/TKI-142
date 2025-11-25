#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/**
* @brief Функция для безопасного ввода числа с плавающей точкой
* @return Введенное пользователем число
*/
double Input(void);

/**
* @brief Функция для вычисления потенциальной энергии пружины.
* @param rigidity Жёсткость пружины в Н / м.
* @param lengthening Растяжение пружины в мм.
* @return Потенциальная энергия пружины в джоулях.
*/
double get_potential_energy(const double rigidity, double lengthening);

/**
*@brief Точка входа в программу
* @return Выводит 0 в случае успеха
*/
int main() {
    setlocale(LC_ALL, "Russian");
    const double rigidity;
    double lengthening, potential_energy;

    puts("Введите значение растяжения (или сжатия) пружины в мм: ");
    lengthening = Input();

    puts("Введите значение жёсткости пружины: ");
    const rigidity = Input();

    if (rigidity < 0) {
        fprintf(stderr, "Ошибка: жёсткость не может быть отрицательной!\n");
        exit(EXIT_FAILURE);
    }

    potential_energy = get_potential_energy(rigidity, lengthening);
    printf("Потенциальная энергия пружины: %f джоулей", potential_energy);

    return 0;
}

double Input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        fprintf(stderr, "Ошибка ввода\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

double get_potential_energy(const double rigidity, double lengthening) {
    lengthening /= 1000; // Переводим миллиметры в метры
    return (rigidity * lengthening * lengthening) / 2;
}