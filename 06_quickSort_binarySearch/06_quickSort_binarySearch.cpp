#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>
using namespace std;


enum keys
{
	UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77
};
template <int size>
void print(int arr[][size], size_t length)
{
	
	cout << "\n\n\n";

	cout << "\t\t\t\t\t";
	for (size_t i = 0; i < length; i++)
	{
		if (i == 0) cout << char(201);
		for (size_t j = 0; j < length; j++)
		{
			cout << char(205);
		}
		if (i != length - 1) cout << char(203);
		if (i == length - 1) cout << char(187);
	}
	cout << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << "\t\t\t\t\t";

		cout << char(186);
		for (size_t j = 0; j < length; j++)
		{
			if (arr[i][j] != 0)
				cout << " " << (arr[i][j] < 10 ? "0" : "") << arr[i][j] << " ";
			else
				cout << "    ";
			cout << char(186);
		}
		cout << endl;

		if (i == length - 1) break;
		cout << "\t\t\t\t\t";
		for (size_t i = 0; i < length; i++)
		{

			if (i == 0) cout << char(204);
			for (size_t j = 0; j < length; j++)
			{
				cout << char(205);
			}
			if (i != length - 1) cout << char(206);
			if (i == length - 1) cout << char(185);
		}
		cout << endl;
	}
	cout << "\t\t\t\t\t";

	for (size_t i = 0; i < length; i++)
	{

		if (i == 0) cout << char(200);
		for (size_t j = 0; j < length; j++)
		{
			cout << char(205);
		}
		if (i != length - 1) cout << char(202);
		if (i == length - 1) cout << char(188);
	}
	cout << endl;
	cout << "\n\n\n";
}

template <int size>
void fillRand(int arr[][size], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; )
		{

			bool flag = true;
			if (i == length - 1 and j == length - 1) break;
			int tmp = rand() % 15 + 1;
			for (size_t q = 0; q <= i; q++)
			{
				for (size_t w = 0; w < length; w++)
				{
					if (q == i and w == j) break;
					if (arr[q][w] == tmp) {
						flag = false;
						break;
					}
				}
				if (flag == false) break;
			}
			if (flag) {
				arr[i][j] = tmp;
				j++;
			}

		}
	}
	arr[length - 1][length - 1] = 0;
}
template <int size>
bool checkWin(int arr[][size], size_t length)
{
	int q = 1;
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length; j++)
		{
			if (i == size - 1 and j == size - 1) break;
			if (arr[i][j] != q) { return false; }
			q++;
		}
	}
	return true;
}
void start()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);
	cout << "\n\n\t\t\t   ================ START GAME ================" << endl << endl;

}
int main() {

	const int size = 4;
	int arr[size][size]/*{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,0}
	}*/;
	fillRand(arr, size);
	start();
	print(arr, size);
	int r = size - 1, c = size - 1;
	int s = 1;
	bool flag = false;
	//int t = time(0);
	do
	{
		s = _getch();
		switch (s)
		{
		case UP: {
			if (r != 0) {
				arr[r][c] = arr[r - 1][c];
				r--;
				arr[r][c] = 0;
			}

			break;
		}
		case DOWN: {
			if (r != size - 1) {
				arr[r][c] = arr[r + 1][c];
				r++;
				arr[r][c] = 0;
			}
			break;
		}
		case LEFT: {
			if (c != 0) {
				arr[r][c] = arr[r][c - 1];
				c--;
				arr[r][c] = 0;
			}
			break;
		}
		case RIGHT: {
			if (c != size - 1) {
				arr[r][c] = arr[r][c + 1];
				c++;
				arr[r][c] = 0;
			}
			break;
		}
		}
		system("cls");
		print(arr, size);
		if (arr[size - 1][size - 1] == 0 and s != 0xE0 and s != 0) {
			flag = checkWin(arr, size);
		}

		if (flag) { break; }

	} while (s != 27);



	
}