
#include <iostream>
#include <string>
#include "Matrix_class.h"
#include "Matrix_class.cpp"


int main()
{
    int size;
    std::cout << "Enter the size of a matrix\n";
    std::cin >> size;

    Matrix_class<double> ob1(size, size);

    try {
        ob1.getRow();
        ob1.setRow(size);
    }
    catch (const std::invalid_argument ia)
    {
        std::cerr << ia.what() << std::endl;
    }

    try {
        ob1.getColumn();
        ob1.setColumn(size);
    }
    catch (const std::invalid_argument ia)
    {
        std::cerr << ia.what() << std::endl;
    }

    
    std::cout << "Before Swap\n";
    ob1.initializeMatrix();
    ob1.printMatrix();
    std::cout << "Swapping colums\n";
    ob1.changeColumns(0, 2);
    ob1.printMatrix();
    std::cout << "Swapping m_rows\n";
    ob1.changeRows(0, 2);
    ob1.printMatrix();

    Matrix_class<double> ob_cp(ob1);
    ob_cp.printMatrix();

    Matrix_class<std::string> m_ob(4, 5);
    m_ob = std::move(Matrix_class<std::string>(2, 3));

    Matrix_class<int> m_ob1 = std::move(Matrix_class<int>(6, 7));

    return 0;
}