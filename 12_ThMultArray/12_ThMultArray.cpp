#include <iostream>
using namespace std;


int main()
{
    int block = 3, row = 4, col = 5;
    int*** arr = new int** [block];

	for (size_t i = 0; i < block; i++)
	{
		arr[i] = new int* [row];
	}
	for (size_t i = 0; i < block; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			arr[i][j] = new int[col];
		}
	}

	for (size_t i = 0; i < block; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			for (size_t q = 0; q < col; q++)
			{
				arr[i][j][q] = rand() % 20;
			}
		}
	}
	for (size_t i = 0; i < block; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			for (size_t q = 0; q < col; q++)
			{
				cout << arr[i][j][q] << "\t";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

