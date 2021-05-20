#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
const int SIZE = 10;
int main()
{
    srand (time (0));  // рандомизируем 
    int *massive = new int[SIZE];  
    for (int i=0; i<SIZE; i++)
        massive[i] = rand()%100+1; // заполняем рандомными числами
    sort(massive, massive + 10); // встроенный алгоритм сортировки
    cout << "Massive:\n";
    for (int i=0; i<SIZE; i++) // вывод
        cout << massive[i] << " ";
}