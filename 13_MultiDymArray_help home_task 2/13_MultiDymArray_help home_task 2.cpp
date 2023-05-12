#include <iostream>
using namespace std;

//Завдання 2. Створіть динамічний масив, що зберігає
//в першому рядку ім'я, а в другому — телефон. Організуйте пошук за ім'ям і номером телефону та можливість
//введення і зміни даних.
void print(char*** arr, const int& row, const int& col)
{
	for (size_t j = 0; j < col; j++)
	{
		for (size_t i = 0; i < row; i++)
		{
			cout << arr[i][j] << (strlen(arr[0][j]) < 8? "\t":"") << (i == 0 ? " :: " : "") << "\t";
		}
		cout << endl;
	}	
}
int findName(char*** arr, const int& col, const char* value) {

	for (size_t i = 0; i < col; i++)
	{
		if (strcmp(arr[0][i], value) == 0) { return i; }
	}
	return -1;
}

void replaceContact(char*** arr, const int& col, const char* name)
{
	int index = findName(arr, col, name);
	if (index == -1) {
		cout << "Contact not found" << endl;
		return;
	}
	cout << "Enter name :: ";
	cin >> arr[0][index];
	cout << "Enter number phone :: ";
	cin >> arr[1][index];
}

void addContact(char*** arr, int& col)
{
	char* name = new char [30];
	char*  phone = new char [30];
	cout << "Enter name :: ";
	cin >> name;
	cout << "Enter number phone :: ";
	cin >> phone;
	char** tmpName = new char* [col + 1];
	for (size_t i = 0; i < col; i++)
	{
		tmpName[i] = arr[0][i];
	}
	tmpName[col] = name;
	delete[] arr[0];
	arr[0] = tmpName;
	char** tmpPhone = new char* [col + 1];
	for (size_t i = 0; i < col; i++)
	{
		tmpPhone[i] = arr[1][i];
	}
	tmpPhone[col] = phone;
	delete[] arr[1];
	arr[1] = tmpPhone;
	col++;
}
int main()
{

	int row = 2;
	int col = 10;
	char name[][30]{
		"Pacorro",
		"Ron",
		"Konstantin",
		"Kessia",
		"Hadleigh",
		"Fiona",
		"Maren",
		"Reidar",
		"Burg",
		"Claiborn",
	};
	char phone[][30]{
		"259-297-9892",
		"296-250-6429",
		"140-723-3453",
		"792-706-2103",
		"963-270-4381",
		"966-142-3720",
		"848-781-2323",
		"108-771-9056",
		"654-322-6103",
		"729-467-4348"
	};
	char*** contact = new char** [row];
	for (size_t i = 0; i < row; i++)
	{
		contact[i] = new char* [col];
	}

	for (size_t j = 0; j < col; j++)
	{
		contact[0][j] = name[j];
		
	}
	for (size_t j = 0; j < col; j++)
	{
		contact[1][j] = phone[j];
	}
	print(contact, row, col);
	char name2[30];
	cout << "Enter name :: ";
	cin >> name2;
	cout << "Reidar :: " << findName(contact, col, name2) << endl;
	replaceContact(contact, col, name2);
	cout << "\n\n\n";
	print(contact, row, col);

	addContact(contact, col);
	cout << "\n\n\n";
	print(contact, row, col);
}

