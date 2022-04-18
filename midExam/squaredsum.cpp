#include<iostream>
using namespace std;

int main(){
    int id, sum = 0;
    int newnum, remainder;
    cin>>id;
    newnum = id;
    while(newnum != 0){
        remainder = newnum%10;
        sum += remainder*remainder;
        newnum/=10;

    }

    cout<<sum;
}