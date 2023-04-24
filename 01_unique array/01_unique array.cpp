#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));

	/*const int SIZE = 10;
	int arr[SIZE]{1,-5,3,0,4,0,8,0,0,1};
	bool flag;
	for (size_t i = 0; i < SIZE;)
	{
		flag = true;
		int tmp = rand() % 10 + 1;
		for (size_t j = 0; j < i; j++)
		{
			if(arr[j] == tmp){
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[i] = tmp;
			i++;
		}
	}
	cout << "Print Array :: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (size_t j = 0; j < SIZE - 1; j++)
	{
		for (size_t i = 0; i < SIZE - 1 - j; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
	

	cout << "Sort Array  :: ";
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;*/
	const int SIZE = 10;
	int arr[SIZE]{};
	cout << "Array :: ";
	for (int i = 0; i < SIZE; i++) { arr[i] = rand() % 10;
	cout << arr[i] << "\t"; }
	for (int i = 0; i < SIZE; i++) { if (arr[i] == 0) { for (int j = i; j < SIZE - 1; j++) { arr[j] = arr[j + 1];
	arr[i + 1] = -1; } } }
	cout << endl;
	cout << "New array :: ";
	for(int i = 0; i < SIZE; i++) { cout << arr[i] << "\t"; }
	
}

