#include <iostream>
#include <fstream>
#include <map>
#include <string>
 
int main()
{
    setlocale(LC_ALL, "Russian");
    using namespace std;
 
    string s;
    ifstream in1("lorem.txt");
 
    map<string, int> D;
 
    while (in1 >> s)
        D[s]++;
    in1.close();
 
    map <string, int>::iterator it;
    ofstream res("result.txt");
    for (it = D.begin(); it != D.end(); it++)
        res << it->first << ": " << it->second << endl;
    return 0;
}