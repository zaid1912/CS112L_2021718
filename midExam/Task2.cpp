#include<iostream>
using namespace std;


class officer{
    private:
    int id;
    string name;
    string rank;
    static int count;
    bool status;
    public:

    int getID(){
        return id;
    }

    bool getstatus(){
        return status;
    }
    //SQUARED SUM OF THE ID HAS TO BE EVEN FORIT TO BE CORRECT
    bool correctId(int ID){
        int sum = 0;
        int newnum, remainder;
        //cin>>id;
        newnum = ID;
        while(newnum != 0){
            remainder = newnum%10;
            sum += remainder*remainder;
            newnum/=10;

        }
        if(sum%2 == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void AddUser(){
        
        cout<<"\n Enter officer name and ID: ";
        cin>>name>>id;
        cout<<"\nEnter the rank of student: ";
        cin>>rank;
        if(correctId(id)){
            count++;
            status = true;
            cout<<"\nThe officer is allowed to enter the area";
        }


    }

    static int getcount(){
        return count;
    }
};
int officer::count = 0;

int main(){
    int choice;
    int max = 0;
    int n = max;
    officer *off = new officer[n];
    cout<<"Welcome to security protocol\n";
    cout<<"Please select from the menu: \n1. Enter an officer record\n2. check number of officers\n3. check the status of the officer\n4. Exit\n-----> ";
    cin>>choice;
    while(choice>=1 && choice<=4){
        if(choice == 1){

            max++;
            officer *temp = new officer[max];
            for(int i = 0; i<n; i++){
                temp[i] = off[i];
            }
            delete[] off;
            off = temp;
            off[n].AddUser();
            n++;

            // officer of;
            // of.AddUser();

        }
        else if(choice == 2){
            cout<<officer::getcount();
        }
        else if(choice == 3){
            int checkID;
            cout<<"\nEnter the ID to check the status: ";
            cin>>checkID;
            int i;
            for(i = 0; i<officer::getcount(); i++){
                if(checkID == off[i].getID()){
                    //off[i].getstatus;
                    break;
                }
            }
            if(off[i].getstatus() == true){
                cout<<"\nThe officer's status is allowed\n";
            }
            else{
                cout<<"\nThe status is not allowed";
            }

        }

        cout<<"Please select from the menu: \n1. Enter an officer record\n2. check number of officers\n3. check the status of the officer\n4. Exit\n-----> ";
        cin>>choice;
    }
    return 0;

}