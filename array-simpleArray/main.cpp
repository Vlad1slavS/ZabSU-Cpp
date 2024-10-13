#include <iostream>                    // для std::cin и std::cout
#include "modules/SimpleArrayModule.h" // для функций ввода и вычисления
#include <vector>                      // для std::vector
#include <fstream>                     // для работы с файлами
#include <cassert>                     // для использования assert
#include <cmath>                       // для математических операций

using namespace std;               // для использования пространства имен std
using namespace SimpleArrayModule; // для использования пространства имен SimpleArrayModule

// Главная функция программы вычисления синуса модуля суммы элементов массива "а"
int main()
{

    int type_of_data_choice;

    double result = calculateResult(1.0);
    assert(fabs(result - sin(1.0)) < 1e-6);

    result = calculateResult(-1.0);
    assert(fabs(result - sin(1.0)) < 1e-6);

    result = calculateResult(1e-10);
    assert(fabs(result - sin(1e-10)) < 1e-6);

    result = calculateResult(1e100);
    assert(fabs(result - sin(1e100)) < 1e-6);

    cout << "Выберите тип данных для работы:\n";
    cout << "1 - vector\n";
    cout << "2 - array\n";
    cin >> type_of_data_choice;

    switch (type_of_data_choice)
    {
    case 1:
    {
        std::vector<double> a; // Вектор действительных чисел
        int n = 0;             // Количество элементов вектора
        int inputChoice;       // Вариант ввода для вектора

        cout << "Выберите вариант ввода:\n";
        cout << "1 - Загрузить вектор из файла\n";
        cout << "2 - Ввести вектор вручную\n";
        cout << "3 - Заполнение вектора случайными числами\n";
        cin >> inputChoice;

        try
        {
            switch (inputChoice)
            {
            case 1:
                // Загрузка вектора из файла
                a = loadVectorFromFile<double>("numbers.txt");

                break;

            case 2:
                // Ввод натурального числа n
                n = inputNaturalNumber();

                // Ввод вектора действительных чисел (до n элементов)
                a = inputRealNumbersToVector<double>(n);

                // Сохранение вектора a в файл array.txt
                saveVectorToFile("array.txt", a);
                break;

            case 3:
                // Ввод натурального числа n
                n = inputNaturalNumber();

                // Заполнение вектора случайными числами (до n элементов)
                a = fillVectorRandomly<double>(10, 1.0, 10.0);

                saveVectorToFile("array.txt", a);

                break;

            default:
                cout << "Неверный выбор варианта ввода.\n";
                break;
            }

            double sum = calculateSum(a); // Вычисление суммы элементов вектора

            double result = calculateResult(sum); // Вычисление результата

            displayResult(result);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
            return 1;
        }
    }
    break;
    case 2:
    {
        double sum = 0;      // Инициализированная переменная суммы
        double result = 0;   // Инициализированная переменная результата
        double *a = nullptr; // Массив действительных чисел
        int n = 0;           // Количество элементов вектора
        int inputChoice;     // Вариант ввода для вектора

        cout << "Выберите массив ввода:\n";
        cout << "1 - Загрузить вектор из файла\n";
        cout << "2 - Ввести массив вручную\n";
        cout << "3 - Заполнение массива случайными числами\n";
        cin >> inputChoice;

        try
        {
            switch (inputChoice)
            {
            case 1:
                a = loadArrayFromFile("array.txt", n); // Загружаем массив из файла с именем array.txt и размером n
                if (a == nullptr)
                {
                    throw runtime_error("Ошибка при загрузке массива из файла.");
                }
                break;

            case 2:

                // Ввод натурального числа n
                n = inputNaturalNumber();

                // Ввод массива действительных чисел (до n элементов)
                a = inputRealNumbers<double>(n);
                break;

            case 3:
                // Ввод натурального числа n
                n = inputNaturalNumber();

                // Заполнение вектора случайными числами (до n элементов)
                a = fillArrayRandomly(n, 1.0, 10.0);

                // Сохранение вектора a в файл array.txt
                saveArrayToFile("array.txt", a, n);

                break;

            default:
                cout << "Неверный выбор варианта ввода.\n";
                break;
            }

            double sum = calculateSum(a, n); // Вычисление суммы элементов вектора

            double result = calculateResult(sum); // Вычисление результата

            displayResult(result);

            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
            return 1;
        }
        catch (const runtime_error &e)
        {
            cerr << "Ошибка: " << e.what() << "\n";
            return 1; // Завершение программы в случае ошибки
        }
    }
    }
}
