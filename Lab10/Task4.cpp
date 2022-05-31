#include<iostream>
using namespace std;

void print(int * num){
    cout<<"\nThe value of ptr cast: "<<*num*10<<endl;
}

int main()
{
    int number: 50;
    int* n = &number;
    cout<<"Number = "<<number;
    print(const_cast<int*>(n));
    return 0;

}
