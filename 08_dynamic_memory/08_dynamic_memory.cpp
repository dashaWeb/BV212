#include <iostream>
using namespace std;

//Написати такі функції для роботи з динамічним масивом :
//
//■ Функція розподілу динамічної пам’яті;
 
int* create(size_t size)
{
	/*int* tmp = new int[size];
	return tmp;*/
	return  new int[size] {};
}
 
void create(int* &arr, size_t size)
{
	if (arr != nullptr) {
		cout << "Error, pointer is not nullptr!!!!!" << endl;
		return;
	}
	arr = new int[size] {};
}
 
//■ Функція ініціалізації динамічного масиву;
void fill(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		arr[i] = rand() % 21 - 10;
	}
}

//■ Функція друку динамічного масиву;
void print(int* arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "\t";
	}cout << endl;
}

// 
//■ Функція видалення динамічного масиву;
void deleteArr(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}
//■ Функція додавання елемента в кінець масиву;
void pushBack(int*& arr, int& size, int value)
{
	int* tmp = new int[size + 1]; // Створили новий масив нв один елемент більше
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i]; // Переписила значення в новий масив з старого
	}
	tmp[size] = value; // Додали нове значення в кінець масиву
	size++; // змінили розмір (тобто який розмір має новий масив)
	delete arr; // видалили старий масив
	arr = tmp; // зберегли новий масив

 }
//■ Функція додавання елемента на початок масиву;
void pushFront(int*& arr, int& size, int value)
{
	int* tmp = new int[size + 1]; // Створили новий масив нв один елемент більше
	for (size_t i = 0; i < size; i++)
	{
		tmp[i+1] = arr[i]; // Переписила значення в новий масив з старого
	}
	tmp[0] = value; // Додали нове значення в кінець масиву
	size++; // змінили розмір (тобто який розмір має новий масив)
	delete arr; // видалили старий масив
	arr = tmp; // зберегли новий масив

}
//■ Функція видалення елемента на початку масиву.
void popFront(int*& arr, int& size) {
	int* tmp = new int[--size];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = arr[i + 1];
	}
	delete [] arr;
	arr = tmp;
}
//■ Функція видалення елемента в кінеці масиву.

//■ Функція видалення елемента за вказаним індексом.

void remove(int*& arr, int& size,int index) {
	int* tmp = new int[--size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index) {
			tmp[i] = arr[i];
		}
		else {
			tmp[i] = arr[i + 1];
		}
	}
	delete[] arr;
	arr = tmp;
}
//■ Функція вставки елемента за вказаним індексом;

//void Swap(int* first, int* end)
//{
//	int tmp = *first;
//	*first = *end;
//	*end = tmp;
//
//}
//void Swap(int& first, int& end)
//{
//	int tmp = first;
//	first = end;
//	end = tmp;
//
//}
int main()
{
	// new, delete

	//
	//int* ptr = new int[100000];
	//int* ptr_a = new int;

	//delete ptr_a;
	//delete []ptr; // array
	//ptr = nullptr;

	//if(ptr == nullptr)
	//	ptr = new int[10];

	int size = 10;
	int* ptr = create(size);
	fill(ptr, size);
	print(ptr, size);
	pushBack(ptr, size, 333);
	print(ptr, size);


	//deleteArr(ptr);

	//size = 15;
	/*cout << "\n\t\t New Array " << endl;
	create(ptr, size);
	fill(ptr, size);
	print(ptr, size);*/

	

}
