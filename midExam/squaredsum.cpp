#include<iostream>
using namespace std;
//finding the squared sum of the user's ID
//222=12
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