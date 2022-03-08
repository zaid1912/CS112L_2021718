#include<iostream>
using namespace std;

int main(){
    int size, totalNeg = 0, totalPos = 0;
    cout<<"enter the size of the array to be created: ";
    cin>>size;
    int *arr = new int[size];
    cout<<"\nEnter array: \n";

    for(int i = 0; i<size; i++){
        cin>>arr[i];
        if(arr[i]<0)
            totalNeg=totalNeg+1;
        else
            totalPos=totalPos+1;
    }
    int *Negarr = new int[totalNeg];
    int *Posarr = new int[totalPos];

    int posIndex = 0, negIndex = 0;
    for(int i = 0; i<size;i++){

        if(arr[i]>0){
            Posarr[posIndex] = arr[i];
            posIndex++;
        }
        else{
            Negarr[negIndex] = arr[i];
            negIndex++;
        }
    }
    cout<<endl<<"Your Array: \n";
    for(int i = 0; i<posIndex;i++){
        cout<<" "<<Posarr[i];
    }
    for(int i = 0; i<negIndex;i++){
        cout<<" "<<Negarr[i];
    }
    cout<<endl;
    return 0;
}