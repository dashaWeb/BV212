#include <iostream>
#include <string>
using namespace std;


struct WashingMachine
{
    int id;
    string firma;
    string color;
    double height;
    double width;
    double length;
    int speed;
    double temperature;
    int getId()
    {
        return id;
    }
    void showResizr(int rwidth)
    {
        width = rwidth;
        cout << "Resize width" << endl;
    }
};

void printWashingMachine(WashingMachine obj)
{
    //static int number = 0;
    cout << "\n\n ================ Washing Machine # " << obj.id << " ================ \n\n" << endl;
    cout << "\t Firma       :: \t " << obj.firma << endl;
    cout << "\t Color       :: \t " << obj.color << endl;
    cout << "\t Height      :: \t " << obj.height << endl;
    cout << "\t Width       :: \t " << obj.width << endl;
    cout << "\t Length      :: \t " << obj.length << endl;
    cout << "\t Speed       :: \t " << obj.speed << endl;
    cout << "\t Temperature :: \t " << obj.temperature << endl;
}
void printWashingMachine(WashingMachine obj,int id)
{
    //static int number = 0;
    cout << "\n\n ================ Washing Machine # " << id << " ================ \n\n" << endl;
    cout << "\t Firma       :: \t " << obj.firma << endl;
    cout << "\t Color       :: \t " << obj.color << endl;
    cout << "\t Height      :: \t " << obj.height << endl;
    cout << "\t Width       :: \t " << obj.width << endl;
    cout << "\t Length      :: \t " << obj.length << endl;
    cout << "\t Speed       :: \t " << obj.speed << endl;
    cout << "\t Temperature :: \t " << obj.temperature << endl;
}
void editWashingMachine(WashingMachine& obj)
{
    
    //static int number = 0;
    cout << "\n\n ================ Washing Machine # " << obj.id<< " ================ \n\n" << endl;
    cout << "\t Enter value Firma       :: \t "; getline(cin, obj.firma); //cin >> obj.firma; запише одне слово, а не цілий рядок

    cout << "\t Enter value Color       :: \t "; getline(cin, obj.color); //cin >> obj.color;
    cout << "\t Enter value Height      :: \t "; cin >> obj.height;
    cout << "\t Enter value Width       :: \t "; cin >> obj.width;
    cout << "\t Enter value Length      :: \t "; cin >> obj.length;
    cout << "\t Enter value Speed       :: \t "; cin >> obj.speed;
    cout << "\t Enter value Temperature :: \t "; cin >> obj.temperature;
    cin.ignore();

}
int main()
{
   /* WashingMachine machine1{ "SAMSUNG","white",90,65,50,1200,95 };
    WashingMachine machine2{ "BOSCH","white",87,64.5,63.5,1400,95 };

    WashingMachine allMachine[]{
        machine1,
        machine2
    };*/
    WashingMachine allMachine[]{
        {1, "SAMSUNG","white",90,65,50,1200,95 },
        {2, "BOSCH","white",87,64.5,63.5,1400,95 }
    };
    /*cout << sizeof(allMachine) << endl;
    cout << sizeof(allMachine[0]) << endl;*/
    for (size_t i = 0; i < sizeof(allMachine) / sizeof(allMachine[0]);  i++)
    {
        printWashingMachine(allMachine[i],i+1);
    }

    cout << allMachine[0].getId() << endl;
    cout << allMachine[1].getId() << endl;

   /* for (size_t i = 0; i < sizeof(allMachine) / sizeof(allMachine[0]); i++)
    {
        editWashingMachine(allMachine[i]);
    }
    */
    allMachine[0].showResizr(200);
    for (size_t i = 0; i < sizeof(allMachine) / sizeof(allMachine[0]); i++)
    {
        printWashingMachine(allMachine[i],i+1);
    }

}
