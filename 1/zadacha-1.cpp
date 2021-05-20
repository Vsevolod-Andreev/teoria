#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    setlocale(0, "");
 
    double M1;
    double M2;
 
    string operation = " ";
    string plus = "+";
    string minus= "-";
    string mul = "*";
    string div = "/";
 
    cin >> operation >> M1 >> M2;
 
    double f1 = M1 + M2;
    double f2 = M1 - M2;
    double f3 = M1 * M2;
    double f4 = M1 / M2;
 
    if (operation == "+")
        cout << "сложение: " << f1 << endl;
 
    else if (operation == "-")
        cout << "вычитание: " << f2 << endl;
 
    else if (operation == "*")
        cout << "умножение: " << f3 << endl;
 
    else if (operation == "/")
        cout << "деление: " << f4 << endl;
 
    else
        cout << "не могу" << endl;
 
    system("pause");
    return 0;
}