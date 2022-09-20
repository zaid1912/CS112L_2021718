#include<iostream>
using namespace std;
#define ans(a, b) (a<<b)


int main(){
    int num1, num2;
    cout<<"Enter number 1 and number 2: \n";
    cin>>num1>>num2;
    cout<<"\nThe answer is: "<<ans(num1, num2)<<endl;
    return 0;
}