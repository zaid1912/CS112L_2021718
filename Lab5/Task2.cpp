#include<iostream>
using namespace std;

class parity
{
    private:
    int size = 0;
    int *list = new int[size];  //dynamic array for storing elements
    int number, puttings = 0;
    public:
    //constructor
    parity(int num = 0):number(num){}

    void put(int num){
        puttings++;
        int n = size;
        size=size+1;
        int *temp =  new int[size];
        for(int i = 0; i < n; i++){
            temp[i] = list[i];
        }
        delete [] list;
        list = temp;
        list[n] = num;
        cout<<"\nItem added successfully";
        
    }

    void Delete(int num){
        //int n = size;
        size = size-1;
        int *temp = new int[size];
        for(int i = 0; i<size; i++){
            temp[i] = list[i];
        }
        delete [] list;
        list = temp;
        cout<<"\nLast item deleted successfully";

    }

    void print(){
        cout<<"\nPrinting the values: ";
        for(int i = 0; i< size; i++){
            cout<<list[i]<<"  ";
        }
    }

    int test(){
        if(puttings%2 == 0)
            return 1;
        else if(puttings%2 != 0)
            return 0;
        
    }

    ~parity(){
        delete [] list;
    }

};

int main()
{
    int num, option;
    parity obj;
    cout<<"\nEnter an option:\n1. Put value\n2. Delete the last value\n3. Print all values\n4. test.\n Enter any other value to terminate\n---->";
    cin>>option;
    while(option>0 and option<5){
        switch(option){
            case 1:
                cout<<"enter num: ";
                cin>>num;
                obj.put(num);
                break;
            case 2:
                obj.Delete(1);
                break;
            case 3:
                obj.print();
                break;
            case 4:
                cout<<obj.test();
                break;


        }
        cout<<"\nEnter an option:\n1. Put value\n2. Delete the last value\n3. Print all values\n4. test.\n Enter any other value to terminate\n---->";
        cin>>option;
    }
    cout<<"\n......EXITING......\n";
}