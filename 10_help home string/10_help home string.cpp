#include <iostream>
using namespace std;

//char* mystrstr(char* str1, char* str2); — функція здійснює пошук підрядка str2 у рядку str1.Функція повертає покажчик на перше входження підрядка str2 в рядок str1, в іншому випадку — 0.
char* mystrstr(char* str1, const char* str2) {

    bool flag = true;
    char* tmp = str1;
    for (size_t i = 0; i < strlen(str1); i++)
    {
        flag = true;
        for (size_t j = 0; j < strlen(str2); j++)
        {
            if (str1[i + j] != str2[j])
            {
                flag = false;
                break;
            }
        }
        if (flag) {
            return tmp;
        }
        else {
            tmp++;
        }
    }
    return 0;
}
//■ Порахуйте кількість входжень слова, заданого користувачем;
int numberOfWord(char* str1, const char* word)
{
    int counter = 0;
    char* tmp = mystrstr(str1, word);
    while (tmp != 0)
    {
        counter++;
        tmp+= strlen(word);
        tmp = mystrstr(tmp, word);
    }

    return counter;
}
//■ Порахуйте кількість речень у тексті;
//■ Кількість точок і ком;
//■ Переверніть весь текст цілком;
//■ Переверніть кожне речення в тексті.
char* reverseLine(char* str)
{
    char* tmp = new char[strlen(str) + 1];
    tmp[strlen(str)] = '\0';
    int counter = 0;
    char symbol[] = ".!?";
    bool flag = false;
    for (size_t i = 0; i < strlen(str); i++)
    {
        flag = false;
        for (size_t j = 0; j < strlen(symbol); j++)
        {
            if (str[i] == symbol[j]) {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            counter++;
        }
        if (flag)
        {
            for (size_t q = 0; q <= counter; q++)
            {
                tmp[i - counter + q] = str[i - q];
            }
            counter = 0;
        }
    }
    return tmp;
}
int main()
{
    cout << "\n\n======================== Task 1 ===========================" << endl;
    char str[] = "red blue blue green yellow blue brown blue green purple blue";
    char word[30] = "blue";
    cout << str << endl;
    cout << "Enter find word :: ";
    //cin >> word;
    cout << "number of find word ::" << numberOfWord(str, word) << endl;
    cout << "\n\n======================== Task 5 ===========================" << endl;
    char line[] = "Lorem ipsum. dolor sit amet, consectetur adipiscing elit. Sed non fringilla augue. Proin dapibus non purus at efficitur.";
    cout << line << endl;
    cout << endl << endl;
    cout << reverseLine(line) << endl;

}

