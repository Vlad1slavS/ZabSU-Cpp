#include <iostream>            // для ввода-вывода
#include "SimpleArrayModule.h" // для функций ввода и вычисления
#include <fstream>             // для работы с файлами
#include <vector>              // для std::vector

using namespace std; // для использования пространства имен std

// Функция для ввода натурального числа
namespace SimpleArrayModule
{
    // Функция для ввода натурального числа
    int inputNaturalNumber()
    {
        int n;
        cout << "Введите натуральное число n: ";
        cin >> n;

        // Проверка на положительность
        while (n <= 0)
        {
            cout << "Ошибка: n должно быть натуральным числом. Повторите ввод: ";
            cin >> n;
        }

        return n;
    }

    // Функция для ввода массива действительных чисел вручную до n элементов
    double *inputRealNumbers(int n)
    {
        double *a = new double[n];
        cout << "Введите " << n << " действительных чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        return a;
    }

    // Функция для ввода массива действительных чисел вручную до n элементов
    std::vector<double> inputRealNumbersToVector(size_t n)
    {
        vector<double> a(n);
        cout << "Введите " << n << " действительных чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        return a;
    }

    // Функция для ввода элементов массива а, размера n
    double *inputRealNumbersToArray(size_t n)
    {
        // Выделяем память для массива
        double *a = new double[n];

        cout << "Введите " << n << " действительных чисел:\n";

        for (size_t i = 0; i < n; ++i)
        {
            double number;
            cout << "Число " << (i + 1) << ": ";
            cin >> number;
            a[i] = number;
        }

        return a;
    }

    // Функция для вычисления суммы элементов массива а, размера n
    double calculateSum(double *a, size_t n)
    {
        double sum = 0.0;
        for (size_t i = 0; i < n; i++) // исправлено i <= n на i < n
        {
            sum += a[i];
        }
        return sum;
    }

    // Функция для вычисления суммы элементов вектора а, размера n
    double calculateSum(const std::vector<double> &a)
    {
        double sum = 0.0;
        for (double value : a)
        {
            sum += value;
        }
        return sum;
    }

    // Функция для вычисления синуса модуля суммы элементов
    double calculateResult(double sum)
    {
        return sin(abs(sum));
    }

    // Функция для вывода результата
    void displayResult(double result)
    {
        cout << "Результат: sin|a1 + a2 + ... + an| (в рад.) = " << result << endl;
    }

    // Функция для записи массива в файл filename с размером size
    void saveArrayToFile(const char *filename, const double *a, size_t size)
    {
        ofstream outfile(filename);
        if (outfile.is_open())
        {
            for (size_t i = 0; i < size; ++i)
            {
                outfile << a[i] << " ";
            }
            outfile.close();
        }
        else
        {
            cerr << "Ошибка: не удалось открыть файл для записи.\n";
        }
    }
    // Функция для сохранения вектора в файл filename
    void saveVectorToFile(const char *filename, const vector<double> &a)
    {
        ofstream outfile(filename);
        if (outfile.is_open())
        {
            for (double value : a)
            {
                outfile << value << " ";
            }
            outfile.close();
        }
        else
        {
            cerr << "Ошибка: не удалось открыть файл для записи.\n";
        }
    }

    // Функция для загрузки массива из файла с именем filename, размера size
    std::vector<double> loadVectorFromFile(const char *filename)
    {
        vector<double> a;
        ifstream infile(filename);
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
            cerr << "Ошибка: не удалось открыть файл для чтения.\n";
        }
        return a;
    }

    // Функция для загрузки массива из файла с именем filename, размера size
    double *loadArrayFromFile(const char *filename, int &size)
    {
        double *a = new double[size];
        ifstream infile(filename);
        if (infile.is_open())
        {
            infile >> size;
            for (int i = 0; i < size; ++i)
            {
                infile >> a[i];
            }
            infile.close();
        }
        else
        {
            cerr << "Ошибка: не удалось открыть файл для чтения.\n";
        }
        return a;
    }

    // Функция для заполнения массива случайными числами
    double *fillArrayRandomly(size_t n, double min_value, double max_value)
    {
        double *a = new double[n];
        srand(time(nullptr));
        for (int i = 0; i < n; ++i)
        {
            a[i] = min_value + static_cast<double>(rand()) / RAND_MAX * (max_value - min_value);
        }
        return a;
    }

    // Функция для заполнения вектора случайными числами
    std::vector<double> fillVectorRandomly(size_t n, double min_value, double max_value)
    {
        std::vector<double> a(n);
        srand(time(nullptr));
        for (int i = 0; i < a.size(); ++i)
        {
            a[i] = min_value + static_cast<double>(rand()) / RAND_MAX * (max_value - min_value);
        }
        return a;
    }
}
