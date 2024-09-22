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
    double *inputRealNumbers(int n)
    {
        double *a = new double[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Введите действительное число a" << i + 1 << ": ";
            cin >> a[i];
        }

        return a;
    }

    // Функция для вычисления суммы элементов массива
    double calculateSum(double *a, int n)
    {
        double sum = 0.0;
        for (int i = 0; i < n; i++) // исправлено i <= n на i < n
        {
            sum += a[i];
        }
        return sum;
    }

    // Функция для вычисления результата sin(abs(sum))
    double calculateResult(double sum)
    {
        return sin(abs(sum));
    }

    // Функция для вывода результата
    void displayResult(double result)
    {
        cout << "Результат: sin|a1 + a2 + ... + an| (в рад.) = " << result << endl;
    }

    // Функция для записи массива в файл
    void saveArrayToFile(const char *filename, double *array, int size)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "Не удается открыть файл для записи: " << filename << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            outFile << array[i] << endl; // Записываем каждое число в отдельной строке
        }
        outFile.close();
    }

    // Функция для загрузки массива из файла
    double *loadArrayFromFile(const char *filename, int &size)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "Не удается открыть файл для чтения: " << filename << endl;
            size = 0;
            return nullptr;
        }

        // Подсчет количества чисел в файле
        size = 0;
        double temp;
        while (inFile >> temp)
        {
            size++;
        }

        // Возврат указателя к началу файла
        inFile.clear();  // Сброс состояния потока
        inFile.seekg(0); // Перемещение указателя на начало файла

        double *array = new double[size];
        for (int i = 0; i < size; i++)
        {
            inFile >> array[i]; // Чтение чисел в массив
        }

        inFile.close();
        return array;
    }
}