#include <iostream>            // для ввода-вывода
#include "SimpleArrayModule.h" // для функций ввода и вычисления
#include <fstream>             // для работы с файлами

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

    // Функция для ввода массива действительных чисел
    vector<double> inputRealNumbers(size_t n)
    {
        vector<double> a(n);
        cout << "Введите " << n << " действительных чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
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

    // Функция для вычисления результата sin(abs(sum))    double calculateSum(const vector<double>& a) {
    double sum = 0.0;
    for (double value : a)
    {
        sum += value;
    }
    return sum;
}

// Функция для вывода результата
void displayResult(double result)
{
    cout << "Результат: sin|a1 + a2 + ... + an| (в рад.) = " << result << endl;
}

// Функция для записи массива в файл
void saveArrayToFile(const char *filename, const vector<double> &a)
{
    ofstream outfile(filename);
    if (outfile.is_open())
    {
        outfile << a.size() << endl;
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
vector<double> loadArrayFromFile(const char *filename)
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

// Функция для заполнения массива случайными числами
void fillArrayRandomly(vector<double> &a, double min_value, double max_value)
{
    srand(time(nullptr));
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] = min_value + static_cast<double>(rand()) / RAND_MAX * (max_value - min_value);
    }
}
}