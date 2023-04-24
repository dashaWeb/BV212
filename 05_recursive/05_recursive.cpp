#include <iostream>
using namespace std;




// 5! = 5 * 4!;
// 4! = 4 * 3!;
// 3! = 3 * 2!;
// 2! = 2 * 1!;
// 1! = 1;
// 0! = 1;


int factor(int number)
{
    if (number == 0 or number == 1) return 1;
    return number * factor(number - 1);
}
//Завдання 1. Написати рекурсивну функцію знаходження стeпення числа.
// 2 ^ 4 => 2 * 2^3
// 2 ^ 3 => 2 * 2^2
// 2 ^ 2 => 2 * 2^1
// 2 ^ 1 => 2 
// 2 ^ 0 => 1
double Pow(double number, int power)
{
    if (power == 1) return number;
    if (power == 0) return 1;
    return number * Pow(number, power - 1);

 }

//Завдання 2. Написати рекурсивну функцію, яка виводить N зірок у ряд, число N задає користувач.Проілюструйте роботу функції прикладом.
void stars(int number)
{
    if (number == 0) return;
    cout << "*";
    stars(number - 1);
    //cout << "-";
}
// ****----
//Завдання 3. Написати рекурсивну функцію, яка обчислює суму всіх чисел діапазоні від a до b.Користувач вводить a та b.Проілюструйте роботу функції прикладом.

//sum 1 - 5 => 1 + sum 2 - 5
//sum 2 - 5 => 2 + sum 3 - 5
// Написати рекурсивну функцію для пошуку максимальної цифри.

// 2578
int maxDigit(int number)
{
    if (number < 10) return number;
    return number % 10 > maxDigit(number / 10) ? number % 10 : maxDigit(number / 10);

}
// 8 > maxDigit(257)
// 7 > maxDigit(25)
// 5 > maxDigit(2)
int sum(int a, int b, int m2)
{
    
    if (a == b)return a;
    return a + sum(a + 1, b, m2+1);
}

// 2578
// Написати рекурсивну функцію, яка виводить передане їй число задом наперед. Наприклад: число 1234 вивести як 4321.
void reverseNumber(int number)
{
    if (number == 0)return;
    cout << number % 10;
    reverseNumber(number / 10);
}
int sumNumber(int number)
{
    if (number == 0) return 0;

    return number % 10 + sumNumber(number / 10);
}
int main()
{
  
    stars(5);
    cout << endl;
    int m=1;
    cout << "Result Factorial :: " << factor(5) << endl;
    cout << "Result Pow       :: " << Pow(2,4) << endl;
    cout << "Result Sum       :: " << sum(1,5,m) / 2.0 << endl;
    cout << "Result Sum       :: " << maxDigit(2548) << endl;
    cout << "Result Reverse       :: ";
    reverseNumber(2678); // 8762
    cout << endl;
    cout << "\nResult Sum       :: " << sumNumber(12345) << endl;
}


