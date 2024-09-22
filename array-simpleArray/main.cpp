// main.cpp
#include <iostream>                    // для std::cin и std::cout
#include "modules/SimpleArrayModule.h" // для функций ввода и вычисления

using namespace std;               // для использования пространства имен std
using namespace SimpleArrayModule; // для использования пространства имен SimpleArrayModule

// Главная функция программы вычисления синуса модуля суммы элементов массива "а"
int main()
{
    double *a = nullptr; // Указатель на массив
    int n = 0;           // Количество элементов в массиве
    int choice;          // Выбор пользователя

    try {
        cout << "Выберите вариант ввода:\n";
        cout << "1 - Загрузить массив из файла\n";
        cout << "2 - Ввести массив вручную\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Загрузка массива из файла
            n = 0;                                 // Сброс количества элементов
            a = loadArrayFromFile("array.txt", n); // Загружаем массив
            if (a == nullptr)
            {
                throw runtime_error("Ошибка при загрузке массива из файла.");
            }
            break;

        case 2:
            // Ввод натурального числа n
            n = inputNaturalNumber();

            // Ввод массива действительных чисел
            a = inputRealNumbers(n);

            // Сохранение массива в файл
            saveArrayToFile("array.txt", a, n);

            break;

        default:
            throw runtime_error("Некорректный выбор.");
        }

        // Вычисление суммы элементов массива
        double sum = calculateSum(a, n);

        // Вычисление результата
        double result = calculateResult(sum);

        // Вывод результата
        displayResult(result);
    }
    catch (const runtime_error& e) {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1; // Завершение программы в случае ошибки
    }
    catch (const exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << "\n";
        return 1; // Завершение программы в случае неизвестной ошибки
    }

    // Освобождение памяти, выделенной под динамический массив
    delete[] a; // Освобождение памяти

    return 0; // Завершение программы
}