// mean_calculator.h
#ifndef ARRAY_SIMPLEARRAY_H // Для упрощения и предотвращения повторного включения кода
#define ARRAY_SIMPLEARRAY_H

namespace SimpleArrayModule
{

    // Функция для ввода натурального числа
    int inputNaturalNumber();
    // Функция для сохранения массива в файл
    double *loadArrayFromFile(const char *filename, int &size);
    // Функция для записи массива в файл
    void saveArrayToFile(const char *filename, double *array, int size);
    // Функция для ввода массива действительных чисел
    double *inputRealNumbers(int n);
    // Функция для вычисления суммы элементов массива
    double calculateSum(double *a, int n);
    // Функция для вычисления результата
    double calculateResult(double sum);
    // Функция для вывода результата
    void displayResult(double result);

}

#endif // ARRAY_SIMPLEARRAY_H