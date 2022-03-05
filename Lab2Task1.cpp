#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
#define base 2

int main(){
    int inputnum;
    cout<<"Enter number: ";
    cin>>inputnum;
    cout<<bitset<16>(inputnum);
    // int i = 1;
    // while(i){
    //     if(pow(base, i) == inputnum){
    //         cout<<"number is a power of two";
    //         break;
        
    // }
    // i++;

    // }
    if((inputnum&(inputnum-1)) == 0)
        cout<<"\nnumber is power of 2\n";
    else
        cout<<"\nnumber is not a power of 2\n";
}