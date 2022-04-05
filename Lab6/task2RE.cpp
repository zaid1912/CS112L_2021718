#include<iostream>
using namespace std;

class officer{
    private: 
    int ID;
    string name;
    string rank;
    static int count;
    public:

    bool palindrome(int low, int high, string id){

        if(id[low] != id[high]){
            return false;
        }
        else{
            low++;high--;
            palindrome(low, high, id);
        }
        return true;
    }

    void AddUser(int id, string username, string userrank){
        ID =id;
        name = username;
        rank = userrank;
        string strID = to_string(id);
        int high = strID.length() - 1;
        int low = 0;
        if(!palindrome(low, high, strID)){
            count++;
            cout<<"\nUser is allowed to enter the restricted area";
        }
        else{
            cout<<"\nUser is not allowed to enter the restricted area";
        }

    }

    static int showcount(){
        return count;
    }
};

int officer::count;

int main(){
    officer o1;
    string name, rank;
    int id, option;

    cout<<"\nPlease enter a desired option:\n";
    cout<<"1. Enter ID of user\n2. Get total number of users\n3. Exit\n";
    while(1){
        cout<<"\nPlease select the desired option --->";
        cin>>option;
        if(option == 1){
            cout<<"\nEnter the id of the user: --->";
            cin>>id;
            cout<<"\nEnter the name of the user: --->";
            cin>>name;
            cout<<"\nEnter the rank of the user: --->";
            cin>>rank;
            o1.AddUser(id, name, rank);

        }
        else if(option == 2){
            cout<<"\n officers cout: "<<officer::showcount();
        }
        else if(option == 3){
            cout<<"----EXITING----\n";
            break;
        }
        else{
            cout<<"Invalid option. enter again";
        }
    }
}