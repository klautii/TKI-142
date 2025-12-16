#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * @brief Выделяет память под массив целых чисел.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 * @return Указатель на выделенную память под массив.
 */
int** initArray(const size_t line, const size_t columns);

/**
 * @brief Проверяет корректность ввода размера массива и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
int validateArraySize(const char* message);

/**
 * @brief Заполняет массив случайными или введенными с клавиатуры числами.
 * @param arr Указатель на массив.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 */
void fillArray(int** arr, const size_t line, const size_t columns);

/**
 * @brief Проверяет корректность ввода целого числа и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
int validateNumber(const char* message);

/**
 * @brief Выводит массив на экран.
 * @param arr Указатель на массив.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 */
void printArray(const int** arr, const size_t line, const size_t columns);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне.
 * @param arr Указатель на массив.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 */
void fillArrayRandom(int** arr, const size_t line, const size_t columns);

/**
 * @brief Заполняет массив, считывая значения с клавиатуры.
 * @param arr Указатель на массив.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 */
void fillArrayKeyboard(int** arr, const size_t line, const size_t columns);

/**
* @brief Заменяет отрицательные элементы двумерного массива на 0.
* @param arr Указатель на исходный массив.
* @param arr2 Указатель на массив, в который будет скопирован результат замены.
* @param line Количество строк в массиве.
* @param columns Количество столбцов в массиве.
* @return Указатель на новый массив после замены.
*/
void replaceNegative(const int** arr, int** arr2, const size_t line, const size_t columns);

/**
 * @brief Подсчитывает количество столбцов, которые не содержат элементов, делящихся на 5.
 * @param arr Указатель на исходный массив.
 * @param line Количество строк в массиве.
 * @param columns Количество столбцов в массиве.
 * @return Количество столбцов без элементов, делящихся на 5.
 */
size_t countColumnsWithoutDivByFive(const int** arr, const size_t line, const size_t columns);

/**
* @brief Создает новый массив, исключая столбцы с элементами, делящимися на 5.
*
* @param arr Указатель на исходный массив.
* @param arr2 Указатель на массив, в который будут скопированы результаты.
* @param line Количество строк в массиве.
* @param columns Количество столбцов в массиве.
* @return Указатель на новый массив.
*/
void createArrayWithoutDivByFive(const int** arr, int** arr2, const size_t line, const size_t columns);

/**
* @brief Освобождает память, выделенную под двумерный массив.
* @param arr Указатель на массив.
* @param line Количество строк в массиве.
*/
void freeArray(int*** arr, const size_t line);

/**
 * @brief Перечисление для выбора способа заполнения массива.
 */
enum TASK {
    RANDOM,
    KEYBOARD
};

int main() {
    size_t line = validateArraySize("Введите количество строк: ");
    size_t columns = validateArraySize("Введите количество столбцов: ");

    int** arr = initArray(line, columns);
    fillArray(arr, line, columns);

    printf("Исходный массив:\n");
    printArray(arr, line, columns);

    printf("Массив после замены отрицательных элементов на 0:\n");
    int** arr2 = initArray(line, columns);
    replaceNegative(arr, arr2, line, columns);
    printArray(arr2, line, columns);

    freeArray(&arr2, line);

    printf("Массив после удаления столбцов с элементами, делящимися на 5:\n");
    size_t countColumns = countColumnsWithoutDivByFive(arr, line, columns);
    int** arr3 = initArray(line, countColumns);
    createArrayWithoutDivByFive(arr, arr3, line, columns);
    printArray(arr3, line, countColumns);

    freeArray(&arr3, line);

    freeArray(&arr, line);

    return 0;
}

int** initArray(const size_t line, const size_t columns) {
    int** arr = (int**)malloc(sizeof(int*) * line);
    if (arr == NULL) {
        puts("Ошибка выделения памяти!");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < line; i++) {
        arr[i] = (int*)malloc(sizeof(int) * columns);
        if (arr[i] == NULL) {
            puts("Ошибка выделения памяти!");
            exit(EXIT_FAILURE);
        }
    }

    return arr;
}

void freeArray(int*** arr, const size_t line) {
    if (*arr != NULL) {
        for (size_t i = 0; i < line; i++) {
            free((*arr)[i]);
        }
        free(*arr);
        *arr = NULL;
    }
}

int validateArraySize(const char* message) {
    int input;
    printf("%s", message);

    if (scanf_s("%d", &input) != 1 || input <= 0) {
        puts("Размер массива должен быть больше нуля!\a");
        exit(EXIT_FAILURE);
    }

    return input;
}

void fillArray(int** arr, const size_t line, const size_t columns) {
    printf("Каким способом вы хотите заполнить массив?\n"
        "Случайные числа - %d\n"
        "Ввод с клавиатуры - %d\n", RANDOM, KEYBOARD);

    int a = validateNumber("");
    enum TASK choice = (enum TASK)a;

    switch (choice) {
    case RANDOM:
        fillArrayRandom(arr, line, columns);
        break;
    case KEYBOARD:
        fillArrayKeyboard(arr, line, columns);
        break;
    default:
        puts("Неправильный номер задания");
        abort();
    }
}

int validateNumber(const char* message) {
    int input;
    printf("%s", message);

    if (scanf_s("%d", &input) != 1) {
        puts("Ошибка ввода!");
        exit(EXIT_FAILURE);
    }

    return input;
}

void fillArrayRandom(int** arr, const size_t line, const size_t columns) {
    const int lowerBound = validateNumber("\nВведите нижнюю границу случайных чисел: ");
    const int upperBound = validateNumber("Введите верхнюю границу случайных чисел: ");

    if (lowerBound > upperBound) {
        puts("Неправильно введена граница чисел!\a");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (size_t i = 0; i < line; i++) {
        for (size_t j = 0; j < columns; j++) {
            arr[i][j] = rand() % (upperBound + 1 - lowerBound) + lowerBound;
        }
    }
}

void printArray(const int** arr, const size_t line, const size_t columns) {
    for (size_t i = 0; i < line; i++) {
        for (size_t j = 0; j < columns; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

void fillArrayKeyboard(int** arr, const size_t line, const size_t columns) {
    printf("Введите %zu элементов массива:\n", line * columns);
    for (size_t i = 0; i < line; i++) {
        for (size_t j = 0; j < columns; j++) {
            arr[i][j] = validateNumber("");
        }
    }
}

size_t countColumnsWithoutDivByFive(const int** arr, const size_t line, const size_t columns) {
    size_t countColumns = 0;
    for (size_t j = 0; j < columns; j++) {
        bool divByFive = false;
        for (size_t i = 0; i < line; i++) {
            if (arr[i][j] % 5 == 0) {
                divByFive = true;
                break;
            }
        }
        if (!divByFive) {
            countColumns++;
        }
    }

    return countColumns;
}

void replaceNegative(const int** arr, int** arr2, const size_t line, const size_t columns) {
    for (size_t i = 0; i < line; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (arr[i][j] < 0) {
                arr2[i][j] = 0;
            }
            else {
                arr2[i][j] = arr[i][j];
            }
        }
    }
}

void createArrayWithoutDivByFive(const int** arr, int** arr2, const size_t line, const size_t columns) {
    size_t newJ = 0;
    for (size_t j = 0; j < columns; j++) {
        bool divByFive = false;
        for (size_t i = 0; i < line; i++) {
            if (arr[i][j] % 5 == 0) {
                divByFive = true;
                break;
            }
        }
        if (!divByFive) {
            for (size_t i = 0; i < line; i++) {
                arr2[i][newJ] = arr[i][j];
            }
            newJ++;
        }
    }
}