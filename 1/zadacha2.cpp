#include<iostream>
using namespace std;
int main()
{
    int glas=0,sogl=0;
    string g="aeiouy";
    string s="bcdfghjklmnpqrstvwxz";
    string h;
    cout<<"Vvedite stroku"<<endl;
    cin>>h;
    for(int i=0; i<h.size(); ++i)
    {
            for(int j=0; j<g.size(); ++j)
            {
                    if(h[i]==g[j])glas++;
            }
            for(int j=0; j<s.size(); ++j)
            {
                    if(h[i]==s[j])sogl++;
            }
    }
    cout<<"Sogl: "<<sogl<<endl<<"Gl: "<<glas<<endl;
    system("pause");
}