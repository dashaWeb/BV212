#include <iostream>
using namespace std;


int STRLEN(char* str)
{
    int counter = 0;
    while (str[counter] != '\0')
    {
        counter++;
    }
    return counter;
}

char TOUPPER(char s) {
    if (s >= 'a' && s <= 'z') return s - 32;
    return s;
}

void uppercase(char* str)
{
    for (size_t i = 0; i < STRLEN(str); i++)
    {
        str[i] = TOUPPER(str[i]);
    }
}
// Task 2
// char* mystrcpy(char* str1, const char* str2); — функція
//копіює рядок str2 у буфер, що адресується через str1.
//Функція повертає покажчик на перший рядок str1.
char* mystrcpy(char* str1, const char* str2)
{
    if (strlen(str2) > strlen(str1)) { 
        return str1;
    }
    for (size_t i = 0; i < strlen(str2); i++)
    {
        str1[i] = str2[i];
    }
    str1[strlen(str2)] = '\0';
    return str1;
}
//Task 3
//■ char* mystrcat(char* str1, const char* str2); — функція
//приєднує рядок str2 до рядка str1.Функція повертає
//покажчик на перший рядок str1.
char* mystrcat(char* str1, const char* str2)
{
    int counter = strlen(str1);
    for (size_t i = 0; i < strlen(str2); i++)
    {
        str1[i + counter] = str2[i];
    }
    return str1;
}
int main()
{
    //char str[]{'H','e','l','l','o','\0'};
    /*char str[] = "hyper text markup language";
    cout << str << endl;
    cout << "Length str :: " << STRLEN(str) << endl;*/
    //uppercase(str);
    //cout << "Upper case line :: " << str << endl;
   // char str1[50] = "Plum Fruit";
   // char str2[] = "Apple";
   //// cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
   // //mystrcpy(str1, str2);
   // cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
   // mystrcat(str1, str2);
   // cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;

    char str1[50] = "Apple";
    char str2[] = "Plum";
    cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
    strncpy_s(str1, "Apple ", 3);
    cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
    strcpy_s(str1, "Red");
    cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
    strcat_s(str1, " Apple");
    cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;
    strncat_s(str1, str2, 2);
    cout << "Str 1 :: " << str1 << "\t Str2 :: " << str2 << endl;

    char line1[] = "Abs";
    char line2[] = "Abc";
    // 0 --> "Abc" == "Abc";
    // 1 --> "Abs" > "Abc";
    // -1 --> "Abs" < "abc";
    cout << "Str 1 :: " << line1 << "\t Str2 :: " << line2 << " :: " << strcmp(line1, line2) << endl;
    cout << "Str 1 :: " << line1 << "\t Str2 :: " << line2 << " :: " << strncmp(line1, line2,2) << endl;
    char line[][50] = { "red","green","pink","Yellow","blue","puple"};
    for (size_t i = 0; i < 6; i++)
    {
        cout << line[i] << endl;
    }cout << "\n\n";
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 5 - i; j++)
        {
            if (strcmp(line[j], line[j + 1]) > 0) {
                char tmp[50];
                strcpy_s(tmp, line[j]);
                strcpy_s(line[j], line[j+1]);
                strcpy_s(line[j+1], tmp);

            }
        }
    }
    for (size_t i = 0; i < 6; i++)
    {
        cout << line[i] << endl;
    }cout << "\n\n";

    char symbol[] = "45, . j fj DTY_";
    cout << "========= isalpha() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" <<symbol[i] << " : " << isalpha(symbol[i]) << endl;
    }
    cout << "========= isdigit() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << isdigit(symbol[i]) << endl;
    }
    cout << "========= isalnum() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << isalnum(symbol[i]) << endl;
    }
    cout << "========= isspace() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << isspace(symbol[i]) << endl;
    }
    cout << "========= islower() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << islower(symbol[i]) << endl;
    }
    cout << "========= isupper() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << isupper(symbol[i]) << endl;
    }

    cout << "========= tolower() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << (char)tolower(symbol[i]) << endl;
    }
    cout << "========= toupper() =================\n";
    for (size_t i = 0; i < strlen(symbol); i++)
    {
        cout << "\t" << symbol[i] << " : " << (char)toupper(symbol[i]) << endl;
    }
}


