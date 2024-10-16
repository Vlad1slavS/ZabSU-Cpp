// mean_calculator.h
#ifndef ARRAY_SIMPLEARRAY_H // Для упрощения и предотвращения повторного включения кода
#define ARRAY_SIMPLEARRAY_H
#include <fstream> // для работы с файлами
#include <string>  // Для string
#include <memory>  // Для std::unique_ptr

namespace SimpleArrayModule
{

    // Функция сохранения вектора в файл
    template <typename T>
    void saveVectorToFile(const std::string &filename, const std::vector<T> &a)
    {
        try
        {
            std::ofstream outfile(filename);
            if (!outfile.is_open())
            {
                throw std::ios_base::failure("Ошибка: не удалось открыть файл для записи.");
            }

            outfile << a.size() << std::endl;
            for (const T &value : a)
            {
                outfile << value << " ";
            }
            outfile.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    // Функция для ввода натурального числа
    int inputNaturalNumber();
    // Функция для загрузки массива в файл с именем filename и размера size
    // Функция для загрузки массива из файла
    template <typename T>
    T *loadArrayFromFile(const std::string &filename, int &size)
    {
        try
        {
            std::ifstream infile(filename);
            if (!infile.is_open())
            {
                throw std::ios_base::failure("Ошибка: не удалось открыть файл для чтения.");
            }

            infile >> size;
            if (size <= 0)
            {
                throw std::invalid_argument("Ошибка: некорректный размер массива.");
            }

            T *a = new T[size];
            for (int i = 0; i < size && infile >> a[i]; ++i)
            {
                // Учитывается успешная загрузка значений
            }

            if (!infile)
            {
                delete[] a;
                throw std::runtime_error("Ошибка: не удалось полностью загрузить данные из файла.");
            }

            infile.close();
            return a;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            size = 0;
            return nullptr;
        }
    }
    // Функция для загрузки вектора из файл с именем filename и размера size

    template <typename T>
    std::vector<T> loadVectorFromFile(const std::string &filename)
    {
        std::vector<T> a;
        try
        {
            std::ifstream infile(filename);
            if (!infile.is_open())
            {
                throw std::ios_base::failure("Ошибка: не удалось открыть файл для чтения.");
            }

            int size;
            infile >> size;
            if (size < 0)
            {
                throw std::invalid_argument("Ошибка: некорректный размер вектора.");
            }

            a.resize(size);
            for (int i = 0; i < size; ++i)
            {
                infile >> a[i];
            }

            if (!infile)
            {
                throw std::runtime_error("Ошибка: не удалось полностью загрузить данные из файла.");
            }

            infile.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            a.clear();
        }
        return a;
    }
    // Функция для записи массива в файл
    template <typename T>
    void saveArrayToFile(const std::string &filename, const T *a, size_t size)
    {
        try
        {
            std::ofstream outfile(filename);
            if (!outfile.is_open())
            {
                throw std::ios_base::failure("Ошибка: не удалось открыть файл для записи.");
            }

            outfile << size << std::endl;
            for (size_t i = 0; i < size; ++i)
            {
                outfile << a[i] << " ";
            }
            outfile.close();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
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
    template <typename T>
    T calculateSum(T *a, size_t n)
    {
        double sum = 0.0;
        for (size_t i = 0; i < n; i++)
        {
            sum += a[i];
        }
        return sum;
    }
    // Функция для вычисления суммы элементов вектора а, размера n
    template <typename T>
    T calculateSum(const std::vector<T> &a)
    {
        double sum = 0.0;
        for (double value : a)
        {
            sum += value;
        }
        return sum;
    }
    // Функция для вычисления результата
    template <typename T>
    T calculateResult(T sum)
    {
        return sin(abs(sum));
    }
    // Функция для вывода результата
    void displayResult(double result);
    // Функция для заполнения массива размера n случайными числами от min_value до max_value
    template <typename T>
    T *fillArrayRandomly(size_t n, T min_value, T max_value)
    {
        static_assert(std::is_arithmetic<T>::value, "Template type must be arithmetic");

        T *a = new T[n];
        srand(static_cast<unsigned>(time(nullptr)));

        for (size_t i = 0; i < n; ++i)
        {
            a[i] = min_value + static_cast<T>(rand()) / RAND_MAX * (max_value - min_value);
        }

        return a;
    }
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