#include <iostream>
#include <string>
using namespace std;

struct Book
{
	string name;
	string author;
	string publisher;
	string genre;
};

void printBook(Book obj)
{
	cout << "\n\t ================= " << obj.name << " ==================\n";
	cout << "\t\t Author    :: " << obj.author << endl;
	cout << "\t\t Publisher :: " << obj.publisher << endl;
	cout << "\t\t Genre     :: " << obj.genre << endl;
	cout << "--------------------------------------------------------------\n\n";
}
void printLibrary(Book* arr, const int& length)
{
	for (size_t i = 0; i < length; i++)
	{
		printBook(arr[i]);
	}
}

int findByAthor(Book* arr, const int& length, string value, int index = 0)
{
	for (size_t i = index; i < length; i++)
	{
		if (arr[i].author == value)
		{
			return i;
		}
	}
	return -1;
}
string toLowerCase(string text)
{
	string lower = text;
	for (size_t i = 0; i < lower.size(); i++)
	{
		lower[i] = tolower(lower[i]);
	}
	return lower;
}
void sortByPublishe(Book* arr, const int& length)
{
	for (size_t i = 0; i < length - 1; i++)
	{
		for (size_t j = 0; j < length - 1 - i; j++)
		{
			if (toLowerCase(arr[j].publisher) > toLowerCase(arr[j + 1].publisher)) {
				Book tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			}
		}
	}
}
void remove(Book* & arr, int& size, int index) {
	Book* tmp = new Book[--size];
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
int main()
{
	int size = 10;
	Book* library = new Book[size]
	{
	   {
		"Allantoin, Benzethonium Chloride",
		"Garwin Walthew",
		"Aspiera Wound Care and Antiseptic",
		"Comedy"
}, {
  "mucor racemosus and aspergillus niger var. niger",
   "Teodorico Suthren",
   "Pleo Sancom",
   "Comedy"
}, {
  "propranolol hydrochloride",
   "Garwin Walthew",
   "Propranolol Hydrochloride",
   "Comedy"
}, {
  "Docusate Sodium",
   "Modesty Sherlaw",
   "Docusate Sodium",
   "Drama"
}, {
  "ACTIVATED CHARCOAL, CITRULLUS COLOCYNTHIS FRUIT, COPPER",
   "Grace Snoddon",
   "Cocyntal",
   "Comedy"
}, {
  "Apis 30c, Anacardium 30c"
   "Jaquelyn Eastabrook",
   "Kicking and Screaming",
   "Comedy"
}, {
  "Sisal",
   "Corney Reaper",
   "Sisal",
   "Drama"
}, {
  "benzonatate",
   "Garwin Walthew",
   "benzonatate",
   "Drama"
}, {
  "Acetaminophen",
   "Hasheem Browning",
   "Childrens Pain Relief Bubblegum",
   "Fantasy"
}, {
  "Glycerin",
   "Iver Santello",
   "Fleet",
   "Comedy"
}
	};
	printLibrary(library, size);

	int index = findByAthor(library, size, "Garwin Walthew");
	while (index != -1)
	{
		cout << "\t Find book :: " << index << endl;
		printBook(library[index]);
		index = findByAthor(library, size, "Garwin Walthew",index+1);
	}
	cout << "\n========= S o r t ===========\n";

	sortByPublishe(library, size);
	printLibrary(library, size);
	cout << "\n====================\n";
	string value;
	cout << "Enter name author :: ";
	getline(cin,value);
	cout << value << endl;
	index = findByAthor(library, size, value);
	if (index != -1) {
		remove(library, size, index);
		printLibrary(library, size);
	}
	else {
		cout << "Book not found" << endl;
	}


}

