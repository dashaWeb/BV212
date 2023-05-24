#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int LENGTH = 50;

struct Book
{
	char name[LENGTH];
	char author[LENGTH];
	char publisher[LENGTH];
	char genre[LENGTH];
};

void printBook(const Book& book, int number = 0) {
	cout << "\n\t ================= " << (number == 0 ? " " : "#" + to_string(number)) + " " << book.name << " ==================\n";
	cout << "\t\t Author    :: " << book.author << endl;
	cout << "\t\t Publisher :: " << book.publisher << endl;
	cout << "\t\t Genre     :: " << book.genre << endl;
	cout << "\t --------------------------------------------------------------\n\n";
}

void printAllBook(Book* lib, const int& size, const bool& flag = false)
{
	for (size_t i = 0; i < size; i++)
	{
		if (flag) {
			printBook(lib[i], i + 1);
			continue;
		}
		printBook(lib[i]);
	}
}
void editBook(Book& book) {
	if (strlen(book.name) == 0) {
		cout << "\n\t ================= " << "New book" << " ==================\n";
	}
	else {
		cout << "\n\t ================= " << book.name << " ==================\n";
	}
	cout << "\t\t Name      :: "; cin.getline(book.name, LENGTH);
	cout << "\t\t Author    :: "; cin.getline(book.author, LENGTH);
	cout << "\t\t Publisher :: "; cin.getline(book.publisher, LENGTH);
	cout << "\t\t Genre     :: "; cin.getline(book.genre, LENGTH);
	cout << "\t --------------------------------------------------------------\n\n";
}
int findByName(Book* arr, const int& length,string value, int index = 0)
{
	for (size_t i = index; i < length; i++)
	{
		//if(strcmp(arr[i].name,value.c_str()) == 0) // 0(==) or > 0 (str1 > str2) or < 0 (str1 < str2)
		if (arr[i].name == value)
		{
			return i;
		}
	}
	return -1;
}
Book* getBooks(string fname, int& size)
{
	fstream file(fname, ios_base::in);// відкрили файловий потік на читання
	if (!file.is_open()) // перевірка чи вдалося відкрити файл, якщо ні (немає файлу немає книг) повертаємо nullptr
		return nullptr;
	file.seekg(0, ios_base::end); // перемістили файловий курсор в кінець, щоб знайти розмір
	size = file.tellg() / sizeof(Book); // поточний байт(кількість байтів) розділили на розмір однієї книги
	if (size < 1) // перевірка, якщо порожній файл. немає книг nullptr
		return nullptr;
	Book* library = new Book[size]; // створили масив для книг
	file.seekg(0, ios_base::beg); // перемістили файловий курсор на початок
	for (size_t i = 0; i < size; i++)
	{
		file.read((char*)&library[i], sizeof(Book)); // записали книги у масив
	} 
	return library; // повернули масив з книгами
}
void setBooks(Book* lib, const int& size, string fname)
{
	fstream file(fname, ios_base::out);
	if (!file.is_open()) {
		cout << "Error!!! File not found" << endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		file.write((char*)&lib[i], sizeof(Book));
	}
}
int main()
{
	
	int size = 0;
	string fname = "library.txt";
	Book* library = getBooks(fname, size);
	int choice, index;
	string value;

	while (true)
	{
		cout << "\n\t 1 - Fill db; \n\t 2 - Edit book; \n\t 3 - print books; \n\t Enter choice :: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			break;
		}
		case 2: {
			cout << "Enter name :: ";
			cin.ignore();
			getline(cin, value);
			index = findByName(library, size, value);
			editBook(library[index]);
			setBooks(library, size, fname);
			break;
		}
		case 3: {

			if (library == nullptr)
			{
				cout << "File not found or Library is Empty" << endl;
				break;
			}
			printAllBook(library, size, true);
			break;
		}
		default:
			break;
		}
	}



	/*Book book1{ "Harry Potter and the Goblet of Fire", "J.K. Rowling","Pottermore Publishing","Fiction" };
	Book book2{ "It", "Stephen King","Simon & Schuster Audio","Horror" };
	Book book3{ "Zombies", "Neil Gaiman","Audible Studios","Fantasy" };

	int size = 3;
	Book* library = new Book[size]{
		book1,
		book2,
		book3
	};*/


	/*fstream file("library.txt", ios_base::in | ios_base::out | ios_base::app);
	if (!file.is_open())
	{
		cout << "Error!!! File not found!!!" << endl;
		return 0;
	}*/
	// write (* char, size);
	// read (*char, size);
	//file.write((char*)&book1, sizeof(book1)); // Запис у файл екземпляр структури (записати можна масив char, тому явно перетворили обєкт у масив символів і вказали його розмір)
	/*for (size_t i = 1; i < size; i++)
	{
		file.write((char*)&library[i], sizeof(Book));
	}*/
	//Book res;
	//file.read((char*)&res, sizeof(Book)); // Читає з файлу екземпляр структури (читає символи і явно перетворило в структуру і вказали розмір цієї структури);
	//file.seekg(0, ios_base::end); // перемістили курсов файлу в 0 байт з кінця
	////cout << file.tellg() / sizeof(Book) << endl; // значення поточного байту
	//int size = file.tellg() / sizeof(Book); // знайшли кількість книг у файлі
	////file.clear();
	//file.seekg(0, ios_base::beg); // перемістили курсов файлу в 0 байт відносно початку файла
	//cout << file.tellg() << endl;
	//
	//Book* res = new Book[size];
	//for (size_t i = 0; i < size; i++)
	//{
	//	file.read((char*)&res[i], sizeof(Book));
	//}
	//for (size_t i = 0; i < size; i++)
	//{
	//	printBook(res[i]);
	//}
	////printBook(res);
	//file.close();
}
