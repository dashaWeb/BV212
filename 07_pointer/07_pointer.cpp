#include <iostream>
using namespace std;

template <typename T>
void BadSwap(T first, T second) // приймаємо копію значення
{
	T tmp = first;
	first = second;
	second = tmp;
}

template <typename T>
void Swap(T* first, T* second) // приймаємо адресу комірки з
{
	T tmp = *first;
	*first = *second;
	*second = tmp;
}

void fill(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		*(arr + i) = rand() % 21 - 10;
	}
}
void print(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
int main()
{


	const int size = 10;
	int arr[size];
	fill(arr, size);
	print(arr, size);



	//int a = 5, b = 10;
	//cout << "A = " << a << "\t B = " << b << endl; // a = 5, b = 10;
	//Swap(&a, &b);
	//cout << "A = " << a << "\t B = " << b << endl; // a = 10, b = 5;



	//int a = 5;
	//int* pointer_a = &a;

	//cout << "Pointer A :: [" << pointer_a << "] \t Value :: " << *pointer_a << endl;
	//int b = 11;
	//int* pointer_b = &b;
	//cout << "Pointer B :: [" << pointer_b << "] \t Value :: " << *pointer_b << endl;

	//a = b;
	//cout << "\n\n========================\n\n";

	//cout << "A = " << a << "\t B = " << b << endl; // A = 11, B = 11
	//b = 33;
	//cout << "A = " << a << "\t B = " << b << endl; // A = 11, B = 33

	//cout << "\n\n========================\n\n";
	//pointer_a = pointer_b;

	//cout << "Pointer A :: [" << pointer_a << "] \t Value :: " << *pointer_a << endl; // 33
	//cout << "Pointer B :: [" << pointer_b << "] \t Value :: " << *pointer_b << endl; // 33

	//*pointer_b = 111;
	//cout << "\n\n========================\n\n";

	//cout << "Pointer A :: [" << pointer_a << "] \t Value :: " << *pointer_a << endl; // 111
	//cout << "Pointer B :: [" << pointer_b << "] \t Value :: " << *pointer_b << endl; // 111

	/*int a, b;
	int* p_a = &a, *p_b = &b;
	cout << "Enter ";
	cin >> *p_a;*/


	/*const int size = 10;
	int arr[size]{ 1,20,30,40,50,60,70,80,90,10 }*/// 40 bytes => 10 elements  4bytes
	//int* pointer_arr = arr;
	//for (size_t i = 0; i < 0; i++)
	//{
	//	cout << "Address [" << pointer_arr + i << "] \t value :: " << *(pointer_arr + i) << endl; // 1
	//}
	//cout << "Address [] \t value :: " << *pointer_arr++ << endl; // 1

	//cout << "Address [] \t value :: " << *pointer_arr<< endl; // 20
	//cout << "Address [] \t value :: " << *(pointer_arr+=4)<< endl; // 60
	//cout << "Address [] \t value :: " << *(--pointer_arr)<< endl; // 70
	//
	//cout << "array :: " << arr << endl;
	//cout << "Size :: " << sizeof(arr) / sizeof(int) << endl;

	
}


