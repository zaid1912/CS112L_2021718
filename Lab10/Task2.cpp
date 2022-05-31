#include<iostream>
using namespace std;
int main()
{
    //first and second variable
    int a = 21, b = 5;
    cout<<"Implicit type casting:\nResult: "<<a/b;
    cout<<"\nExlicit type casting:\nResult: "<<(float)a/b<<endl;
    
    return 0;
}