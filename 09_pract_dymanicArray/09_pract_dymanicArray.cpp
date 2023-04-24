#include <iostream>
using namespace std;



/*
* Завдання 1. Дани два масиви: А[M] і B[N] (M і N вводяться з клавіатури). Необхідно створити третій масив мінімально можливого розміру, у якому потрібно зібрати елементи масиву A, які не включаються до масиву B, без повторень.
    1) Створити два мисиви з розміром, який вкаже користувач
    2) Заповинити масиви
    3) Знайти розмір нового масиву
    4) Записати значення в новий масив
*/
void fill(int* arr, const int& length, int min = 1, int max = 10)
{
    for (size_t i = 0; i < length; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
void print(int* arr, const int& length, string text = "")
{
    cout << text;
    for (size_t i = 0; i < length; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
//3) Знайти розмір нового масиву
int counterNorepeatElement(int* A, int* B, const int& size_a, const int& size_b)
{
    int counter = 0;
    bool flag;
    for (size_t i = 0; i < size_a; i++)
    {
        flag = true;
        for (size_t j = 0; j < size_b; j++)
        {
            if (A[i] == B[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (size_t q = 0; q < i; q++)
            {
                if (A[q] == A[i]) {
                    flag = false;
                }
            }
            if (flag) {
                counter++;
            }
        }
    }

    return counter;

}

int* newArrayNoRepeatElement(int* A, int* B, const int& size_a, const int& size_b, int& new_size)
{
    new_size = counterNorepeatElement(A, B, size_a, size_b);
    int* C = new int[new_size];
    int counter = 0;
    bool flag;
    for (size_t i = 0; i < size_a; i++)
    {
        flag = true;
        for (size_t j = 0; j < size_b; j++)
        {
            if (A[i] == B[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (size_t q = 0; q < i; q++)
            {
                if (A[q] == A[i]) {
                    flag = false;
                }
            }
            if (flag) {
                C[counter] = A[i];
                counter++;
            }
        }
    }

    return C;
}
int* newArrayNoRepeatElementAll(int* A, int* B, const int& size_a, const int& size_b, int& new_size)
{
    int size_1;
    int size_2;

    int* C = newArrayNoRepeatElement(A, B, size_a, size_b, size_1);
    int* D = newArrayNoRepeatElement(B, A, size_b, size_a, size_2);
    new_size = size_1 + size_2;
    int* Res = new int[new_size];

    for (size_t i = 0; i < size_1; i++)
    {
        Res[i] = C[i];
    }
    for (size_t i = 0; i < size_2; i++)
    {
        Res[i + size_1] = D[i];
    }
    return Res;
}
int numberRepeat(int* A, int* B, const int& size_a, const int& size_b)
{
    int counter = 0;
    bool flag = false;
    for (size_t i = 0; i < size_a; i++)
    {
        flag = false;
        for (size_t j = 0; j < size_b; j++)
        {
            if (A[i] == B[j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (size_t j = 0; j < i; j++)
            {
                if (A[i] == A[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                counter++;
            }
        }
    }

    return counter;
}
int* newArrayRepeatElement(int* A, int* B, const int& size_a, const int& size_b, int& new_size)
{
    new_size = numberRepeat(A, B, size_a, size_b);
    int* tmp = new int[new_size];
    int counter = 0;
    bool flag = false;
    for (size_t i = 0; i < size_a; i++)
    {
        flag = false;
        for (size_t j = 0; j < size_b; j++)
        {
            if (A[i] == B[j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (size_t j = 0; j < i; j++)
            {
                if (A[i] == A[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                tmp[counter] = A[i];
                counter++;
            }
        }
    }
    return tmp;
}
int numberOddOrEven(int* A, const int& size_a, bool flag = true)
{
    int counter = 0;

    if (flag) // видаляємо парні елементи
    {
        for (size_t i = 0; i < size_a; i++)
        {
            if (A[i] % 2 == 0) {
                counter++;
            }
        }
    }
    else {
        for (size_t i = 0; i < size_a; i++)
        {
            if (A[i] % 2 != 0) {
                counter++;
            }
        }
    }
    return size_a - counter;
}
int* deleteEvenOrOdd(int* A, const int& size_a, int& new_size, bool flag = true)
{
    new_size = numberOddOrEven(A, size_a, flag);
    int* tmp = new int[new_size];
    int counter = 0;
    if (flag) // видаляємо парні елементи
    {
        for (size_t i = 0; i < size_a; i++)
        {
            if (A[i] % 2 != 0) {
                tmp[counter] = A[i];
                counter++;
            }
        }
    }
    else {
        for (size_t i = 0; i < size_a; i++)
        {
            if (A[i] % 2 == 0) {
                tmp[counter] = A[i];
                counter++;
            }
        }
    }
    return tmp;
}
int main()
{
    //1) Створити два мисиви з розміром, який вкаже користувач
    int* A, * B;
    int size_a, size_b;
    cout << "Enter size array A :: ";
    cin >> size_a;
    cout << "Enter size array B :: ";
    cin >> size_b;
    A = new int[size_a];
    B = new int[size_b];

    //2) Заповинити масиви
    fill(A, size_a);
    fill(B, size_b);

    print(A, size_a, "Print Array A :: ");
    print(B, size_b, "Print Array B :: ");
    cout << "Size new array C = " << counterNorepeatElement(A, B, size_a, size_b) << endl;
    int size_c;
    int* C = newArrayNoRepeatElement(A, B, size_a, size_b, size_c);
    print(C, size_c, "Print Array C :: ");
    delete[] C;
    C = newArrayNoRepeatElementAll(A, B, size_a, size_b, size_c);
    print(C, size_c, "Print Array C :: ");
    cout << "\n\n=======================\n\n";
    print(A, size_a, "Print Array A :: ");
    print(B, size_b, "Print Array B :: ");
    cout << "Number repeat element :: " << numberRepeat(A, B, size_a, size_b) << endl;
    delete[] C;
    C = newArrayRepeatElement(A, B, size_a, size_b, size_c);
    print(C, size_c, "Print Array C :: ");

    cout << "\n\n=======================\n\n";
    print(A, size_a, "Print Array A :: ");
    cout << "Number delete even element :: " << numberOddOrEven(A,  size_a, true) << endl;
    cout << "Number delete odd element :: " << numberOddOrEven(A,  size_a, false) << endl;
    delete[] C;
    C = deleteEvenOrOdd(A, size_a, size_c, true);
    print(C, size_c, "Print Array C :: ");
    delete[] C;
    C = deleteEvenOrOdd(A, size_a, size_c, false);
    print(C, size_c, "Print Array C :: ");

    // Hype text markup language
    // r
    // rkup language
}

