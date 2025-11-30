#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
* @brief Выделяет память под массив целых чисел.
* @param size Размер массива.
* @return Указатель на выделенную память под массив.
*/
int* IntArray(const size_t size);

/**
* @brief Функция проверки ввода размера массива.
* @return Возвращает значение размера массива, если верное, иначе выдает ошибку.
*/
int InputArraySize(void);

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
void FullRandomArray(int* arr, const size_t size, const int DownBound, const int UpBound);

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
 */
void ReplaceTask1(const int* arr, int* arr2, const size_t size);

/**
 * @brief Проверяет, оканчивается ли число на 0.
 * @param number Целое число, которое необходимо проверить.
 * @return 1 Если число оканчивается на 0, иначе 0.
 */
int EndsWithZero(int number);

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
 */
void RemoveElementsEndWithZero(const int* arr, int* arr2, const size_t size);

/**
 * @brief Преобразует массив по правилу: если номер четный, то Mi=i*Pi , если нечетный, то Mi=-Pi.
 * @param arr Указатель на исходный массив.
 * @param arr2 Указатель на массив, в который будет скопирован результат преобразования.
 * @param size Размер исходного массива.
 */
void ChangeArray(const int* arr, int* arr2, const size_t size);

/**
 * @brief Функция для безопасного ввода целого числа.
 * @return Введенное целое число.
 */
int InputInt(void);

/*
* @brief Точка входа в программу.
* @return Возвращает значение функции с заданным в цикле корнем.
*/
int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");

    size_t size = (size_t)InputArraySize();
    int* arr = IntArray(size);

    printf("\nКаким способом вы хотите заполнить массив?\n"
        "Случайные числа - 0\n"
        "Ввод с клавиатуры - 1\n");

    printf("Введите ваш выбор: ");
    int choice = InputInt();

    switch (choice) {
    case 0: {
        printf("Введите минимальную границу случайных чисел: ");
        const int DownBound = InputInt();
        printf("Введите максимальную границу случайных чисел: ");
        const int UpBound = InputInt();

        if (DownBound > UpBound) {
            fprintf(stderr, "Ошибка: нижняя граница не может быть больше верхней!\n");
            free(arr);
            return 1;
        }

        FullRandomArray(arr, size, DownBound, UpBound);
        break;
    }
    case 1:
        FillingArrayKeyboard(arr, size);
        break;
    default:
        fprintf(stderr, "Неправильный выбор!\n");
        free(arr);
        return 1;
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

int InputArraySize(void)
{
    int value = 0;
    printf("Введите размер массива: ");
    if (scanf("%d", &value) != 1 || value <= 0)
    {
        fprintf(stderr, "Ошибка: размер массива должен быть целым числом больше нуля.\n");
        exit(EXIT_FAILURE);
    }
    return value;
}

int* IntArray(const size_t size)
{
    if (size == 0) {
        fprintf(stderr, "Ошибка: размер массива не может быть нулевым\n");
        exit(EXIT_FAILURE);
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

void FullRandomArray(int* arr, const size_t size, const int DownBound, const int UpBound)
{
    if (arr == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в FullRandomArray\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (UpBound - DownBound + 1) + DownBound;
    }
}

void FillingArrayKeyboard(int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в FillingArrayKeyboard\n");
        return;
    }

    printf("\nВведите %zu целых чисел для заполнения массива:\n", size);
    for (size_t i = 0; i < size; i++)
    {
        printf("Элемент [%zu]: ", i);
        arr[i] = InputInt();
    }
}

void PrintArray(const int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в PrintArray\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int MinAbsNegativeElement(const int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в MinAbsNegativeElement\n");
        return -1;
    }

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
    if (arr == NULL || arr2 == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в ReplaceTask1\n");
        return;
    }

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

int EndsWithZero(int number)
{
    return (abs(number) % 10 == 0);
}

size_t CountElementsNotEndWithZero(const int* arr, const size_t size)
{
    if (arr == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в CountElementsNotEndWithZero\n");
        return 0;
    }

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
    if (arr == NULL || arr2 == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в RemoveElementsEndWithZero\n");
        return;
    }

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
    if (arr == NULL || arr2 == NULL) {
        fprintf(stderr, "Ошибка: передан NULL указатель в ChangeArray\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            arr2[i] = (int)i * arr[i];
        }
        else
        {
            arr2[i] = -arr[i];
        }
    }
}

int InputInt(void)
{
    int value = 0;
    if (scanf("%d", &value) != 1) {
        fprintf(stderr, "Ошибка ввода числа!\n");
        exit(EXIT_FAILURE);
    }
    return value;
}
