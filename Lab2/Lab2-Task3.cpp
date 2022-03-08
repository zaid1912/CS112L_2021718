#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;

int BinaryToDecimal(int n){
    int decimal = 0, power = 1;
    if(n%10 == 1){
        decimal = 1;
        n = n/10;
        power = 2;
    }
    else{
        decimal = 0;
        power = 1;
    }
    while(n>0){
        if(n%10 == 1){
            decimal = decimal + power;
        }
        n = n/10;
        power = power * 2;
    }
    return decimal;
}

void addBase2(string n1, string n2){
    int num1 = stoi(n1);
    int num2 = stoi(n2);
    int decimal;
    //cout<<num1;  
    int num1InDec = BinaryToDecimal(num1);
    int num2InDec = BinaryToDecimal(num2);
    cout<<num1InDec<<endl<<num2InDec<<endl;
    int sum = num1InDec ^ num2InDec;
    int carry = num1InDec & num2InDec;
    carry = carry<<1;
    int ans = sum|carry;
    //cout << sum << " " << carry << " " << ans;
    cout<<endl<<n1<<" + "<<n2<<" = "<<bitset<8>(ans)<<endl;
}

int OctalToDecimal(int n){
    int remainder = 0, decimal = 0;
    int i = 0;
    while(n!=0){
        remainder = n%10;
        decimal = decimal + (remainder * pow(8, i));
        i++;
        n = n/10;
    }
    return decimal;
}

void addBase8(string n1, string n2){
    int num1 = stoi(n1);
    int num2 = stoi(n2);
    int num1InDec = OctalToDecimal(num1);
    int num2InDec = OctalToDecimal(num2);
    int sum = num1InDec + num2InDec;
    cout<<endl<<n1<<" + "<<n2<<" = "<<sum<<"(IN DECIMAL)\n";

}



int main(){
    int base;
    string n1, n2;
    cout<<"Enter the base: (2, 8, or 16): ";
    cin>>base;
    // while(base != 2 || base!=8 || base!=16){
    //<"\nPlease enter either 2, 8 or 16 as a base: ";
    //     >base;
    // }
    if(base == 2){
        cout<<"\nEnter number 1: ";
        cin>>n1;
        cout<<"\nEnter number 2: ";
        cin>>n2;
        addBase2(n1, n2);

    }
    else if(base == 8){
        cout<<"\nEnter number 1: ";
        cin>>n1;
        cout<<"\nEnter number 2: ";
        cin>>n2;
        addBase8(n1, n2);

    }
    if(base == 16){
        cout<<"\nEnter number 1: ";
        cin>>n1;
        cout<<"\nEnter number 2: ";
        cin>>n2;
        //addBase16(n1, n2);

    }

    // int base = 2;
    // string n1 = "101", n2 = "110";
    //add(n1, n2);
    
    


    return 0;
}