#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>

/**
 * @brief Выделяет память под массив целых чисел.
 * @param size Размер массива.
 * @return Указатель на выделенную память под массив.
 */
int* iArray(const size_t size);

/**
 * @brief Проверяет корректность ввода размера массива и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
int validateInput(const char* message);

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArrayRandom(int* arr, const size_t size);

/**
 * @brief Заполняет массив, считывая значения с клавиатуры.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void fillArrayKeyboard(int* arr, const size_t size);

/**
 * @brief Выводит массив на экран.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Проверяет корректность ввода целого числа и возвращает его.
 * @param message Сообщение для пользователя.
 * @return Введенное целое число.
 */
int validateNumber(const char* message);

/**
 * @brief Выполняет задание 1: суммирует четные элементы, превышающие пороговое значение.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 * @return Сумма четных элементов, превышающих пороговое значение.
 */
int sumEvenElements(const int* arr, const size_t size);

/**
 * @brief Выполняет задание 2: умножает четные положительные элементы на последний элемент массива.
 * @param arr Указатель на массив.
 * @param arr2 Указатель на массив, в который будут записаны результаты умножения.
 * @param size Размер массива.
 * @return Новый массив после выполнения задания 2.
 */
int* multiplyEvenPositiveElements(const int* arr, int* arr2, const size_t size);

/**
 * @brief Выполняет задание 3: находит индекс первой пары соседних элементов с разными знаками.
 * @param arr Указатель на массив.
 * @param size Размер массива.
 * @return Индекс первой пары соседних элементов с разными знаками или -1, если таких пар нет.
 */
int searchIndexPair(const int* arr, const size_t size);

/**
 * @brief Получает выбор пользователя для способа заполнения массива.
 * @return Выбор пользователя.
 */
int getFillChoice();

/**
 * @brief Перечисление для выбора способа заполнения массива.
 */
enum TASK {
    RANDOM,
    KEYBOARD
};

/**
* @brief Основная функция программы.
* @return Возвращает 0 в случае успешного выполнения программы.
*/
int main() {
    setlocale(LC_ALL, "Russian");
    size_t size = validateInput("Введите количество элементов в массиве: ");

    int* arr = iArray(size);

    printf("\nКаким способом вы хотите заполнить массив?\n"
        "Случайные числа - %d\n"
        "Ввод с клавиатуры - %d\n", RANDOM, KEYBOARD);

    int choice = getFillChoice();

    switch (choice) {
    case RANDOM:
        fillArrayRandom(arr, size);
        break;
    case KEYBOARD:
        fillArrayKeyboard(arr, size);
        break;
    default:
        fprintf(stderr, "Неправильный выбор способа заполнения массива!\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    printf("\nИсходный массив: ");
    printArray(arr, size);

    printf("\nСумма четных элементов, значения которых больше порогового значения: %d\n", sumEvenElements(arr, size));

    printf("\nМассив после умножения четных положительных элементов на последний элемент: ");
    int* arr2 = iArray(size);
    printArray(multiplyEvenPositiveElements(arr, arr2, size), size);

    free(arr2);
    arr2 = NULL;

    int pairIndex = searchIndexPair(arr, size);
    if (pairIndex == -1) {
        puts("Пары с разными элементами не найдены");
    }
    else {
        printf("\nИндекс первой пары соседних элементов с разными знаками: %d\n", pairIndex);
    }

    free(arr);
    arr = NULL;

    return 0;
}

int getFillChoice() {
    int input;

    printf("Введите ваш выбор: ");
    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Ошибка ввода выбора способа заполнения массива!\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

int validateNumber(const char* message) {
    int input;

    printf("%s", message);
    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Ошибка ввода числа!\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

int validateInput(const char* message) {
    int input;
    printf("%s", message);

    if (scanf("%d", &input) != 1 || input <= 0) {
        fprintf(stderr, "Размер массива должен быть больше нуля.\n");
        exit(EXIT_FAILURE);
    }

    return input;
}

int* iArray(const size_t size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Ошибка выделения памяти!\n");
        exit(EXIT_FAILURE);
    }

    return arr;
}

void fillArrayRandom(int* arr, const size_t size) {
    const int lowerBound = validateNumber("\nВведите нижнюю границу случайных чисел: ");
    const int upperBound = validateNumber("Введите верхнюю границу случайных чисел: ");

    if (lowerBound > upperBound) {
        fprintf(stderr, "Неправильно введена граница чисел! Нижняя граница не может быть больше верхней.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
}

void fillArrayKeyboard(int* arr, const size_t size) {
    printf("\nВведите %zu целых чисел для заполнения массива:\n", size);
    for (size_t i = 0; i < size; i++) {
        printf("Элемент [%zu]: ", i);
        arr[i] = validateNumber("");
    }
}

void printArray(const int* arr, const size_t size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int sumEvenElements(const int* arr, const size_t size) {
    int threshold = validateNumber("Введите пороговое значение: ");
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] > threshold) {
            sum += arr[i];
        }
    }

    return sum;
}

int* multiplyEvenPositiveElements(const int* arr, int* arr2, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && arr[i] > 0) {
            arr2[i] = arr[i] * arr[size - 1];
        }
        else {
            arr2[i] = arr[i];
        }
    }

    return arr2;
}

int searchIndexPair(const int* arr, const size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        if (arr[i] * arr[i + 1] < 0) {
            return i;
        }
    }

    return -1;
}