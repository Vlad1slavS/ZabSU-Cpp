// main.cpp
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;

// Пространство имен для функций работы с массивами (теперь векторами)
namespace SimpleArrayModule
{

    int inputNaturalNumber()
    {
        int n;
        do
        {
            cout << "Введите натуральное число: ";
            cin >> n;
            if (n <= 0)
            {
                cout << "Ошибка: число должно быть натуральным.\n";
            }
        } while (n <= 0);
        return n;
    }

    // Функция для ввода массива действительных чисел
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

    // Функция для ввода вектора действительных чисел
    vector<double> inputRealNumbers(int n)
    {
        vector<double> a(n);
        cout << "Введите " << n << " действительных чисел:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        return a;
    }

    // Функция для сохранения вектора в файл
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

    // Функция для загрузки массива из файла
    void loadArrayFromFile(const char *filename, double *array, int &size)
    {
        ifstream infile(filename);
        if (infile.is_open())
        {
            infile >> size;
            for (int i = 0; i < size; ++i)
            {
                infile >> array[i];
            }
            infile.close();
        }
        else
        {
            cerr << "Ошибка: не удалось открыть файл для чтения.\n";
        }
    }

    // Функция для вычисления суммы элементов вектора
    double calculateSum(const vector<double> &a)
    {
        double sum = 0.0;
        for (double value : a)
        {
            sum += value;
        }
        return sum;
    }

    // Функция для вычисления синуса модуля суммы элементов вектора
    double calculateResult(double sum)
    {
        return sin(abs(sum));
    }

    // Функция для заполнения вектора случайными числами
    void fillArrayRandomly(vector<double> &a, double min_value, double max_value)
    {
        srand(time(nullptr));
        for (int i = 0; i < a.size(); ++i)
        {
            a[i] = min_value + static_cast<double>(rand()) / RAND_MAX * (max_value - min_value);
        }
    }

    // Функция для вывода результата
    void displayResult(double result)
    {
        cout << "Результат: " << result << endl;
    }
}

// Главная функция программы
int main()
{
    vector<double> a;
    int n = 0;
    int choice;

    try
    {
        cout << "Выберите вариант ввода:\n";
        cout << "1 - Загрузить массив из файла\n";
        cout << "2 - Ввести массив вручную\n";
        cout << "3 - Заполнить массив случайными числами\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a = SimpleArrayModule::loadArrayFromFile("array.txt");
            break;

        case 2:
            n = SimpleArrayModule::inputNaturalNumber();
            a = SimpleArrayModule::inputRealNumbers(n);
            SimpleArrayModule::saveArrayToFile("array.txt", a);
            break;

        case 3:
        {
            n = SimpleArrayModule::inputNaturalNumber();
            a.resize(n);
            double min_value, max_value;
            cout << "Введите минимальное значение для случайных чисел: ";
            cin >> min_value;
            cout << "Введите максимальное значение для случайных чисел: ";
            cin >> max_value;
            SimpleArrayModule::fillArrayRandomly(a, min_value, max_value);
            SimpleArrayModule::saveArrayToFile("array.txt", a);
            break;
        }

        default:
            throw runtime_error("Некорректный выбор.");
        }

        // Вычисление суммы элементов вектора
        double sum = SimpleArrayModule::calculateSum(a);

        // Вычисление результата
        double result = SimpleArrayModule::calculateResult(sum);

        // Вывод результата
        SimpleArrayModule::displayResult(result);
    }
    catch (const runtime_error &e)
    {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }
    catch (const exception &e)
    {
        cerr << "Неизвестная ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
