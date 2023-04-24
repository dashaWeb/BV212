#include <iostream>
#include <string>
using namespace std;



int main()
{
	string line1 = "Hello", line2 = "World";
	auto test = 3;
	cout << "Int :: " << sum(3,7) << endl;
	cout << "Int :: " << sum(3,7.3) << endl;
	cout << "Double :: " << sum(2.5, 6.3) << endl;
	cout << "Char :: " << sum('A', 'B') << endl;
	cout << "String :: " << sum(line1, line2) << endl;
	cout << "\n====================\n";
	cout << "Test A :: \t" << toLower('A') << endl;
	cout << "Test W :: \t" << toLower('W') << endl;
	cout << "Test . :: \t" << toLower('.') << endl;
	cout << "Test b :: \t" << toLower('b') << endl;
	cout << "Test # :: \t" << toLower('#') << endl;
}







int sum(int a, int b)
{
	return a + b;
}
double sum(int a, double b)
{
	cout << a << " + " << b << " = " << a + b << endl;
	return a + b;
}
double sum(double a, double b)
{
	return a + b;
}
char sum(char a, char b)
{
	return a + b;
}
string sum(string a, string b)
{
	return a + b;
}
char toLower(char s)
{
	/*if (s >= 'A' && s <= 'Z') return s + 32;
	return s;*/
	return (s >= 'A' && s <= 'Z') ? s + 32 : s;
}