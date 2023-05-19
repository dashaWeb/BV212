#include <iostream>
#include <string>
using namespace std;

//Завдання 3. Розробити структуру, яка описує тварину(назва, клас, кличка).Створити функції для роботи з цією структурою :
//■ Заповнення об'єкта;
//■ Вивід на екран даних про об'єкт;
//■ Функція «Подати голос».
struct Animal
{
    string name;
    string cllass;
    string login;
    string voice;
};

void fill(Animal& obj)
{
    cout << "Enter name  :: "; getline(cin, obj.name);
    cout << "Enter Class :: "; getline(cin, obj.cllass);
    cout << "Enter Login :: "; getline(cin, obj.login);
    //cout << "Enter voice :: "; getline(cin, obj.voice);
}
void print(Animal obj)
{
    cout << "name  :: " << obj.name << endl;    
    cout << "Class :: " << obj.cllass << endl; 
    cout << "Login :: " << obj.login << endl; 
    //cout << "voice :: " << obj.voice << endl; 
}
void getVoice(Animal obj)
{
    cout << obj.voice << endl;
}
int main()
{
    
}
