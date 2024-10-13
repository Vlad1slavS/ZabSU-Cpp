// mean_calculator.h
#ifndef ARRAY_SIMPLEARRAY_H // Для упрощения и предотвращения повторного включения кода
#define ARRAY_SIMPLEARRAY_H
#include <fstream> // для работы с файлами

namespace SimpleArrayModule
{

    // Функция сохранения вектора в файл
    template <typename T>
    void saveVectorToFile(const std::string &filename, const std::vector<T> &a)
    {
        std::ofstream outfile(filename);
        if (outfile.is_open())
        {
            for (const T &value : a)
            {
                outfile << value << " ";
            }
            outfile.close();
        }
        else
        {
            std::cerr << "Ошибка: не удалось открыть файл для записи.\n";
        }
    }
    // Функция для ввода натурального числа
    int inputNaturalNumber();
    // Функция для загрузки массива в файл с именем filename и размера size
    double *loadArrayFromFile(const char *filename, int &size);
    // Функция для загрузки вектора из файл с именем filename и размера size

    template <typename T>
    std::vector<T> loadVectorFromFile(const std::string &filename)
    {
        std::vector<T> a;
        std::ifstream infile(filename);
        if (infile.is_open())
        {
            int size;
            infile >> size;
            a.resize(size);
            for (int i = 0; i < size; ++i)
            {
                infile >> a[i];
            }
            infile.close();
        }
        else
        {
            std::cerr << "Ошибка: не удалось открыть файл для чтения.\n";
        }
        return a;
    }
    // Функция для записи массива в файл
    void saveArrayToFile(const char *filename, const double *a, size_t size);
    // Функция для ввода массива действительных чисел
    // Функция для ввода вектора действительных чисел
    template <typename T>
    std::vector<T> inputRealNumbersToVector(size_t n)
    {
        std::vector<T> a(n);
        std::cout << "Введите " << n << " чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        return a;
    }
    // Функция для вычисления суммы элементов массива а, размера n
    double calculateSum(double *a, size_t n);
    // Функция для вычисления суммы элементов вектора а, размера n
    double calculateSum(const std::vector<double> &a);
    // Функция для вычисления результата
    double calculateResult(double sum);
    // Функция для вывода результата
    void displayResult(double result);
    // Функция для заполнения массива размера n случайными числами от min_value до max_value
    double *fillArrayRandomly(size_t n, double min_value, double max_value);
    // Функция для заполнения вектора случайными числами от min_value до max_value
    template <typename T>
    std::vector<T> fillVectorRandomly(size_t n, T min_value, T max_value)
    {
        std::vector<T> a(n);
        srand(static_cast<unsigned int>(time(nullptr))); // Инициализация генератора случайных чисел
        for (size_t i = 0; i < a.size(); ++i)
        {
            a[i] = min_value + static_cast<T>(rand()) / RAND_MAX * (max_value - min_value);
        }
        return a;
    }
    // Функция для ввода массива размера n действительных чисел
    template <typename T>
    T *inputRealNumbers(int n)
    {
        T *a = new T[n];
        std::cout << "Введите " << n << " действительных чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }
        return a;
    }

}

#endif // ARRAY_SIMPLEARRAY_H