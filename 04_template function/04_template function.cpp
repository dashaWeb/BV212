#include <iostream>
using namespace std;

template <typename T>
void fillArray(T arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter :: ";
		cin >> arr[i];
	}
}

template <typename T>
void printArray(T arr[], size_t length, string text = "")
{
	cout << text;
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>
int findValue(T arr[], size_t length, T value)
{
	for (size_t i = 0; i < length; i++)
	{
		if (arr[i] == value) return i;
	}
	return -1;
}

//перемішування елементів масиву випадковим чином(декілька разів поміняти місцями елементи з  випадковими індексами)
template <typename T>
void mix(T arr[], size_t length, int number = 4)
{
	int first, second;
	T tmp;
	for (size_t i = 0; i < number;)
	{
		first = rand() % length;
		second = rand() % length;
		if (first != second)
		{
			tmp = arr[first];
			arr[first] = arr[second];
			arr[second] = tmp;
			i++;
		}
	}
}
int main()
{
	const int SIZE = 5; 
	int arrInt[SIZE]{5,2,6,8,4};
	double arrDouble[SIZE]{2.3,1.3,5.6,9.8,4.8};
	char arrChar[SIZE]{'q','w','e','r','t'};
	string arrString[SIZE]{"pink","green","cyan","brown","gold"};

	/*cout << "Fill Int " << endl;
	fillArray(arrInt, SIZE);
	cout << "Fill Double " << endl;
	fillArray(arrDouble, SIZE);
	cout << "Fill Char " << endl;
	fillArray(arrChar, SIZE);
	cout << "Fill String " << endl;
	fillArray(arrString, SIZE);*/

	cout << "\n=============== Print ===================\n";
	printArray(arrInt, SIZE, "Print Array Int \t :: \t");
	printArray(arrDouble, SIZE, "Print Array Double \t :: \t");
	printArray(arrChar, SIZE, "Print Array Char \t :: \t");
	printArray(arrString, SIZE, "Print Array String \t :: \t");
	cout << "\n=============== Find ===================\n";

	mix(arrInt, SIZE);
	mix(arrDouble, SIZE);
	mix(arrChar, SIZE);
	mix(arrString, SIZE);


	cout << "\n=============== Print ===================\n";
	printArray(arrInt, SIZE, "Print Array Int \t :: \t");
	printArray(arrDouble, SIZE, "Print Array Double \t :: \t");
	printArray(arrChar, SIZE, "Print Array Char \t :: \t");
	printArray(arrString, SIZE, "Print Array String \t :: \t");
	cout << "\n=============== Find ===================\n";


	int valueI;
	double valueD;
	char valueC;
	string valueS;

	//cout << "Enter value Int :: "; cin >> valueI;

	//int index = findValue(arrInt, SIZE, valueI);
	//if (index != -1) {
	//	cout << "Enter new value :: ";
	//	cin >> valueI;
	//	//arrInt[index] = 55;
	//	arrInt[index] = valueI;
	//}
	//else {
	//	cout << "Find value no found" << endl;
	//}
	//printArray(arrInt, SIZE, "Print Array Int \t :: \t");


	//cout << "Enter value Double :: "; cin >> valueD;
	//cout << "Position element :: " << findValue(arrDouble, SIZE, valueD) << endl;
	//cout << "Enter value Char :: "; cin >> valueC;
	//cout << "Position element :: " << findValue(arrChar, SIZE, valueC) << endl;
	//cout << "Enter value String :: "; cin >> valueS;
	//cout << "Position element :: " << findValue(arrString, SIZE, valueS) << endl;
	



}

