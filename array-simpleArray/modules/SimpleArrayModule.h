// mean_calculator.h
#ifndef ARRAY_SIMPLEARRAY_H // Для упрощения и предотвращения повторного включения кода
#define ARRAY_SIMPLEARRAY_H

namespace SimpleArrayModule
{

    // Функция сохранения вектора в файл
    void saveVectorToFile(const char *filename, const std::vector<double> &a);
    // Функция для ввода натурального числа
    int inputNaturalNumber();
    // Функция для загрузки массива в файл с именем filename и размера size
    double *loadArrayFromFile(const char *filename, int &size);
    // Функция для загрузки вектора из файл с именем filename и размера size
    std::vector<double> loadVectorFromFile(const char *filename);
    // Функция для записи массива в файл
    void saveArrayToFile(const char *filename, const double *a, size_t size);
    // Функция для ввода массива действительных чисел
    double *inputRealNumbersToArray(size_t n);
    // Функция для ввода вектора действительных чисел
    std::vector<double> inputRealNumbersToVector(size_t n);
    // Функция для вычисления суммы элементов массива а, размера n
    double calculateSum(double *a, size_t n);
    // Функция для вычисления суммы элементов вектора а, размера n
    double calculateSum(const std::vector<double> &a);
    // Функция для вычисления результата
    double calculateResult(double sum);
    // Функция для вывода результата
    void displayResult(double result);
    // Функция для заполнения массива случайными числами
    double *fillArrayRandomly(size_t n, double min_value, double max_value);
    // Функция для заполнения вектора случайными числами
    std::vector<double> fillVectorRandomly(size_t n, double min_value, double max_value);
    // Функция для ввода массива размера n действительных чисел
    double *inputRealNumbers(int n);

}

#endif // ARRAY_SIMPLEARRAY_H