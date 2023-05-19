#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// ofstream ---> write file; out file (cout)
	// ifstream ---> read file; in file   (cin)
	//string fname = "../../test/myfile.txt";
	/*string fname = "myfile.txt";
	ofstream file;
	file.open(fname, ios_base::app);
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		string value;
		for (size_t i = 0; i < 3; i++)
		{
			cout << "Enter programming language :: ";
			getline(cin, value);
			file << value << endl;
		}

	}
	file.close();*/
	/*int arr[]{ 1,2,5,8,-6,39,2 };
	string fname = "number.dat";
	ofstream file(fname, ios_base::app);
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			file << arr[i] << " ";
		}
	}
	file.close();*/
	//int numb[50];
	//int size = 0;
	//ifstream file("number.dat");
	//if (!file.is_open()) {
	//    cout << "Error" << endl;
	//}
	//else {
	//    /*int value;
	//    while (file >> value) {
	//        cout << value << endl;
	//    }*/
	//    while (file>>numb[size])
	//    {
	//        size++;
	//    }
	//}
	//file.close();

	//for (size_t i = 0; i < size; i++)
	//{
	//    cout << numb[i] << " ";
	//}
	//cout << endl;
	ifstream file("myfile.txt");
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	else {
		// way 1
		//string value;
		//while (file >> value) // записує до пропуску або ентера
		//{
		//	cout << value << endl;
		//}
		// way 2
		//string value;
		//while (getline(file,value)) // записує до  ентера
		//{
		//	cout << " ---- " << value << endl;
		//}
		// way 3
		//char value;
		//while (file.get(value)) // записує один символ
		//{
		//	cout << " ---- " << value << endl;
		//}
		// way 4
		file.seekg(-50, ios_base::beg);// ios_base::beg - відносно початку; ios_base::end - відносно кінця
		char value[200];
		while (file.getline(value, 200)) // записує один символ
		{
			cout << " ---- " << value << endl;
		}
	}
}

