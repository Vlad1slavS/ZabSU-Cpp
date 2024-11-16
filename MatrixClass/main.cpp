#include <iostream>
#include "MatrixClass.h"

using namespace std;

int main()
{
    try
    {
        Matrix A(3);
        A.fill(1);
        Matrix B(3);
        B.fill(3);
        Matrix C = A + B;
        C.printMatrix();
        Matrix D = A - B;
        D.printMatrix();
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
