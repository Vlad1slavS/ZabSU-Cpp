#include <iostream>            // для ввода-вывода
#include "SimpleArrayModule.h" // для функций ввода и вычисления

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
}