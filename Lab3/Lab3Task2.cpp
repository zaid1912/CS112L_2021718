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
    int largest = arr[0];
    int smallest = arr[0];
    for(int i = 0; i<size; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }

        if(arr[i]<smallest){
            smallest = arr[i];
        }
        
    }
    int *Temparr = new int[size-2];
    for(int i = 0; i<size; i++){
        if(arr[i] != largest && arr[i] != smallest){
            Temparr[i] = arr[i];
        }
    }

    int Secondlargest = Temparr[0];
    int Secondsmallest = Temparr[0];
    for(int i = 0; i<size-2; i++){
        if(Temparr[i]>Secondlargest){
            Secondlargest = Temparr[i];
        }

        if(Temparr[i]<Secondsmallest && Temparr[i] != 0){
            Secondsmallest = Temparr[i];
        }
        
    }
    cout<<"\nSecond Smallest: "<<Secondsmallest<<endl;
    cout<<"\nSecond Largest: "<<Secondlargest<<endl;
    
    return 0;
}