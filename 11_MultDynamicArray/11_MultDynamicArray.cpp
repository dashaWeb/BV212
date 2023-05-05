#include <iostream>
using namespace std;
void insertRow(int**& arr, int& row, const int& col, const int& index);

void fill(int** arr, const int row, const int col, int min = 1, int max = 10)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}
void print(int** arr, const int row, const int col, string text = "")
{
	cout << "\n\t" << text << endl;
	for (size_t i = 0; i < row; i++)
	{
		cout << "\t\t";
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


//Завдання 1. Написати функцію, що додає рядок двовимірному масиву в кінець.
void pushRow(int**& arr, int& row, int col)
{
	insertRow(arr, row, col, row);
}
//Завдання 2. Написати функцію, що додає рядок двовимірному масиву в початок.
void pushFrontRow(int**& arr, int& row, int col)
{
	insertRow(arr, row, col, 0);
}
//Завдання 3. Написати функцію, що додає рядок двовимірному масиву в зазначену позицію.
void insertRow(int**& arr, int& row, const int& col, const int& index)
{
	if (index < 0 || index > row) return;
	int** tmp = new int* [row + 1];
	tmp[index] = new int[col] {};

	for (size_t i = 0; i < row; i++)
	{
		if (i < index) {
			tmp[i] = arr[i];
		}
		else {
			tmp[i + 1] = arr[i];
		}
	}
	row++;
	delete[] arr;
	arr = tmp;
}

//Завдання 1. Написати функцію, що видаляють рядок двовимірному масиву в кінець.
//Завдання 2. Написати функцію, що видаляють рядок двовимірному масиву в початок.
void popFrontRow(int**& arr, int& row)
{
	int** tmp = new int* [--row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr;
	arr = tmp;
}
//Завдання 3. Написати функцію, що видаляють рядок двовимірному масиву в зазначену позицію.
void removeRow(int**& arr, int& row, const int& index)
{
	if (index < 0 || index >= row) return;
	int** tmp = new int* [--row];
	for (size_t i = 0; i < row; i++)
	{
		if (i < index) {
			tmp[i] = arr[i];
		}
		else {
			tmp[i] = arr[i + 1];
		}
	}
	delete[] arr[index];
	delete[] arr;
	arr = tmp;
}

//Завдання 1. Написати функцію, що додає стовпець двовимірному масиву в кінець.
//Завдання 2. Написати функцію, що додає стовпець двовимірному масиву в початок.
//Завдання 3. Написати функцію, що додає стовпець двовимірному масиву в зазначену позицію.

void addCol(int** arr, const int& row, int& col, int index, int value = 0)
{
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col + 1];
		tmp[index] = value;
		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
			{
				tmp[j] = arr[i][j];
			}
			else {
				tmp[j+1] = arr[i][j];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
	col++;
}

//Завдання 1. Написати функцію, що видаляють стовпець двовимірному масиву в кінець.
//Завдання 2. Написати функцію, що видаляють стовпець двовимірному масиву в початок.
//Завдання 3. Написати функцію, що видаляють стовпець двовимірному масиву в зазначену позицію.
void removeCol(int** arr, const int& row, int& col, int index)
{
	col--;
	for (size_t i = 0; i < row; i++)
	{
		int* tmp = new int[col];

		for (size_t j = 0; j < col; j++)
		{
			if (j < index)
			{
				tmp[j] = arr[i][j];
			}
			else {
				tmp[j] = arr[i][j+1];
			}
		}
		delete[] arr[i];
		arr[i] = tmp;
	}
}



int main()
{

	int row = 4, col = 5;
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	fill(arr, row, col);
	print(arr, row, col, "Print Begin Array ");
	pushRow(arr, row, col);
	print(arr, row, col, "Print Push Row    ");
	popFrontRow(arr, row);
	print(arr, row, col, "Print Pop Front Row");
	addCol(arr, row, col, 2, 333);
	print(arr, row, col, "Print add Column");
	removeCol(arr, row, col, 3);
	print(arr, row, col, "Print remove Column");
	insertRow(arr, row, col, 3);
	print(arr, row, col, "Print insert Row");
	removeRow(arr, row, 3);
	print(arr, row, col, "Print rtemove Row");

	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

