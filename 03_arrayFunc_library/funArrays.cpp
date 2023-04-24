#include "funArrays.h"

void fillArray(int arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter value :: ";
		cin >> arr[i];
	}
}

void fillArray(double arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter value :: ";
		cin >> arr[i];
	}
}

void fillArray(char arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter value :: ";
		cin >> arr[i];
	}
}

void fillArray(string arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "Enter value :: ";
		cin >> arr[i];
	}
}

void printArray(int arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void printArray(double arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void printArray(char arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void printArray(string arr[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
