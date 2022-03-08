#include<iostream>
using namespace std;
class swapClass{

    private:
    int num1;
    int num2;
    int *num1ptr = &num1, *num2ptr = &num2;

    public:
    void setter(){
        cout<<"Enter the two values: \n";
        cin>>num1;
        cin>>num2;
    }
    void Swap(){
        num1ptr = &num2;
        num2ptr = &num1;
    }
    void display(){
        cout<<"A = "<<*num1ptr;
        cout<<" & B = "<<*num2ptr;
    }
};
int main(){
    swapClass s;
    s.setter();
    cout<<"\nBefore Swapping : ";
    s.display();
    cout<<"\nAfter Swapping : ";
    s.Swap();
    s.display();
    cout<<endl;

    return 0;
}