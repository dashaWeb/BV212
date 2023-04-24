#include <iostream>
#include "funArrays.h"
using namespace std;

int main()
{
    const int SIZE = 5;
    int arrInt[SIZE];
    double arrDouble[SIZE];
    char arrChar[SIZE];
    string arrString[SIZE];

    fillArray(arrInt, SIZE, 1,9);
    fillArray(arrDouble, SIZE, 1,33);
    cout << "Char \n";
    fillArray(arrChar, SIZE);
    cout << "String \n";
    fillArray(arrString, SIZE);

    /// 
    cout << "\n======================================\n";
    printArray(arrInt, SIZE);
    cout << "\n======================================\n";
    printArray(arrDouble, SIZE);
    cout << "\n======================================\n";
    printArray(arrChar, SIZE);
    cout << "\n======================================\n";
    printArray(arrString, SIZE);
    cout << "\n======================================\n";

}

