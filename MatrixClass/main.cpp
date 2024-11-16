#include <iostream>
#include "MatrixClass.h"

using namespace std;

int main()
{
    try
    {
        Matrix square(5);
        cout << "Матрица создана!" << endl;
        square.fillRand();
        square.printMatrix();
        double element = square(1, 2); // Работа с матрицей, где индексация начинается с 1
        cout << "Элемент на позиции (1, 2): " << element << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
