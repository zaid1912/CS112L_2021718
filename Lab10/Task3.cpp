#include<iostream>
using namespace std;
int main()
{
    double l, w;
    cout<<"Enter the length of rectangle: ";
    cin>>l;
    cout<<"\nEnter the width of rectangle: ";
    cin>>w;
    cout<<"\nInt:\nThe area of the rectangle is: "<<static_cast<int>(l*w)<<endl;
    cout<<"Float:\nThe area of the rectangle is: "<<l*w<<endl;
}