#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

/**
* @brief Выделяет память под массив целых чисел.
* @param size Размер массива.
* @return Указатель на выделенную память под массив.
*/
int* IntArray(const size_t size);

/*
* @brief Функция проверки ввода размера массива.
* @return Возвращает значение размера массива, если верное, иначе выдает ошибку.
*/
int InputArray(void);

/**
 * @brief Получает выбор пользователя для способа заполнения массива.
 * @return Выбор пользователя.
 */
int getFillChoice();

/**
* @brief Заполняет массив, считывая значения с клавиатуры.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void FillingArrayKeyboard(int* arr, const size_t size);

/**
* @brief Заполняет массив случайными числами в заданном диапазоне.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void FullRandomArray(int* arr, const size_t size);

/**
* @brief Выводит массив на экран.
* @param arr Указатель на массив.
* @param size Размер массива.
*/
void PrintArray(const int* arr, const size_t size);

/**
 * @brief Находит индекс минимального по модулю отрицательного элемента в массиве.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 * @return Индекс минимального по модулю отрицательного элемента или -1, если такого нет.
 */
int MinAbsNegativeElement(const int* arr, const size_t size);

/**
 * @brief Заменяет минимальный по модулю отрицательный элемент массива первым элементом.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат замены.
 * @param size Размер исходного массива.
 * @return Новый массив после замены минимального по модулю отрицательного элемента.
 */
void ReplaceTask1(const int* arr, int* arr2, const size_t size);

/**
 * @brief Проверяет, оканчивается ли число на 0.
 * @param number Целое число, которое необходимо проверить.
 * @return true Если число оканчивается на 0, иначе false.
 */
bool EndsWithZero(int number);

/**
 * @brief Подсчитывает количество элементов, которые не оканчиваются на 0.
 * @param arr Указатель на исходный массив.
 * @param size Количество элементов в массиве.
 * @return Количество элементов, которые не оканчиваются на 0.
 */
size_t CountElementsNotEndWithZero(const int* arr, const size_t size);

/**
 * @brief Удаляет элементы, оканчивающиеся на 0, из массива.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будут скопированы элементы после удаления.
 * @param size Размер исходного массива.
 * @return Новый массив после удаления элементов, оканчивающихся на 0.
 */
void RemoveElementsEndWithZero(const int* arr, int* arr2, const size_t size);

/**
 * @brief Преобразует массив по правилу: если номер четный, то Mi=i*Pi , если нечетный, то Mi=-Pi.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат преобразования.
 * @param size Размер исходного массива.
 * @return Новый массив после преобразования.
 */
void ChangeArray(const int* arr, int* arr2, const size_t size);

/**
* @brief Перечисление для выбора способа заполнения массива.
*/
enum TASK {
    RANDOM,
    KEYBOARD
};

/*
* @brief Точка входа в программу.
* @return Возвращает значение функции с заданным в цикле корнем.
*/
int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    puts("Введите количество элементов в массиве: ");
    size_t size = (size_t)InputArray();

    int* arr = IntArray(size);

    // Выбор способа заполнения массива
    printf("\nКаким способом вы хотите заполнить массив?\n"
        "Случайные числа - %d\n"
        "Ввод с клавиатуры - %d\n", RANDOM, KEYBOARD);

    int choice = getFillChoice();

    switch (choice) {
    case RANDOM:
        FullRandomArray(arr, size);
        break;
    case KEYBOARD:
        FillingArrayKeyboard(arr, size);
        break;
    default:
        fprintf(stderr, "Неправильный номер задания!\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    printf("\nИсходный массив: ");
    PrintArray(arr, size);

    printf("Массив после замены минимального по модулю отрицательного элемента: ");
    int* arr2 = IntArray(size);
    ReplaceTask1(arr, arr2, size);
    PrintArray(arr2, size);

    free(arr2);

    size_t newsize = CountElementsNotEndWithZero(arr, size);
    printf("Массив после удаления элементов, оканчивающихся на 0: ");
    int* arr3 = IntArray(newsize);
    RemoveElementsEndWithZero(arr, arr3, size);
    PrintArray(arr3, newsize);

    free(arr3);

    printf("Массив M после преобразований: ");
    int* arr4 = IntArray(size);
    ChangeArray(arr, arr4, size);
    PrintArray(arr4, size);

    free(arr4);
    free(arr);

    return 0;
}

int InputArray(void)
{
    int value;
    printf("Введите размер массива: ");
    if (scanf("%d", &value) != 1 || value <= 0)
    {
        fprintf(stderr, "Размер массива должен быть больше нуля.\n");
        exit(EXIT_FAILURE);
    }

    return value;
}

int getFillChoice()
{
    int input;
    printf("Введите ваш выбор: ");
    if (scanf("%d", &input) != 1)
    {
        fprintf(stderr, "Ошибка ввода выбора способа заполнения массива!\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

int* IntArray(const size_t size)
{
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

void FullRandomArray(int* arr, const size_t size)
{
    int DownBound, UpBound;

    printf("Введите минимальную границу случайных чисел: ");
    if (scanf("%d", &DownBound) != 1)
    {
        fprintf(stderr, "Ошибка ввода нижней границы!\n");
        exit(EXIT_FAILURE);
    }

    printf("Введите максимальную границу случайных чисел: ");
    if (scanf("%d", &UpBound) != 1)
    {
        fprintf(stderr, "Ошибка ввода верхней границы!\n");
        exit(EXIT_FAILURE);
    }

    if (DownBound > UpBound)
    {
        fprintf(stderr, "Неправильно введена граница чисел!\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (UpBound - DownBound + 1) + DownBound;
    }
}

void FillingArrayKeyboard(int* arr, const size_t size)
{
    printf("\nВведите %zu целых чисел для заполнения массива:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("Элемент [%zu]: ", i);
        int value;
        if (scanf("%d", &value) != 1)
        {
            fprintf(stderr, "Ошибка ввода элемента массива!\n");
            exit(EXIT_FAILURE);
        }
        arr[i] = value;
    }
}

void PrintArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MinAbsNegativeElement(const int* arr, const size_t size)
{
    int minIndex = -1;
    int minAbsValue = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            int absValue = abs(arr[i]);
            if (minIndex == -1 || absValue < minAbsValue)
            {
                minIndex = i;
                minAbsValue = absValue;
            }
        }
    }
    return minIndex;
}

void ReplaceTask1(const int* arr, int* arr2, const size_t size)
{
    int minIndex = MinAbsNegativeElement(arr, size);

    for (size_t i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }

    if (minIndex != -1)
    {
        arr2[minIndex] = arr[0];
    }
}

bool EndsWithZero(int number)
{
    return (abs(number) % 10 == 0);
}

size_t CountElementsNotEndWithZero(const int* arr, const size_t size)
{
    size_t newSize = 0;
    for (size_t i = 0; i < size; i++) {
        if (!EndsWithZero(arr[i]))
        {
            newSize++;
        }
    }

    return newSize;
}

void RemoveElementsEndWithZero(const int* arr, int* arr2, const size_t size)
{
    size_t index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (!EndsWithZero(arr[i]))
        {
            arr2[index] = arr[i];
            index++;
        }
    }
}

void ChangeArray(const int* arr, int* arr2, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr2[i] = i * arr[i];
        }
        else
        {
            arr2[i] = -arr[i];
        }
    }
}