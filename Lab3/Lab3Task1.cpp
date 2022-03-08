#include<iostream>
using namespace std;

int main(){
    int size;
    cout<<"enter the size of the array to be created: ";
    cin>>size;
    int *arr = new int[size];
    cout<<"\nEnter array: \n";

    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    int *Temparr = new int[size-1];
    for(int i = 0; i<size; i++){
        Temparr[i] = arr[i+1]-arr[i];
    }
    cout<<"\nResultant array: [";
    for(int i = 0; i<size-1; i++){
        cout<<" "<<Temparr[i];
    }
    cout<<" ]\n";

    return 0;
}