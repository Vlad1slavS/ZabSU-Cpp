// mean_calculator.h
#ifndef ARRAY_SIMPLEARRAY_H // Для упрощения и предотвращения повторного включения кода
#define ARRAY_SIMPLEARRAY_H

namespace SimpleArrayModule
{

    // Функция для ввода натурального числа
    int inputNaturalNumber();
    // Функция для сохранения массива в файл с именем filename и размера size
    double *loadArrayFromFile(const char *filename, int &size);
    // Функция для записи массива в файл
    void saveArrayToFile(const char *filename, double *array, size_t size);
    // Функция для ввода массива действительных чисел
    double *inputRealNumbers(size_t n);
    // Функция для вычисления суммы элементов массива а, размера n
    double calculateSum(double *a, size_t n);
    // Функция для вычисления результата
    double calculateResult(double sum);
    // Функция для вывода результата
    void displayResult(double result);
    // Функция для заполнения массива случайными числами
    double *fillArrayRandomly(double *array, size_t size, double min_value, double max_value);

}

#endif // ARRAY_SIMPLEARRAY_H