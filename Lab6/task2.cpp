#include<iostream>
using namespace std;

class officer{
    private:
    int id;
    static int count;
    string name;
    string rank;
    public:
    officer(int ID = 0, string NAME = "", string RANK = ""){
        id = ID;
        name = NAME;
        rank = RANK;
        count++;
    }
    void setID(int ID){
        id = ID;
    }
    void setName(string NAME){
        name = NAME;
    }
    void setRank(string RANK){
        rank = RANK;
    }
    bool palindrome(int low, int high, int ID){
        string idString = to_string(ID);

        if(idString[low] != idString[high]){
            return false;
        }
        else{
            low++;high--;
            palindrome(low, high, stoi(idString));
        }
        return true;
    }

    int showcount(){
        return count;
    }

};

void menu(){
    static int size = 0;
    int option, ID;
    string name, rank;
    officer *users = new officer[size];
    cout<<"\nPlease enter a desired option:\n";
    cout<<"1. Enter ID of user\n2. Get total number of users\n3. Exit\n";
    while(1){
        cout<<"Please select the desired option --->";
        cin>>option;
        if(option == 1){
            cout<<"\nEnter the ID---> ";
            cin>>ID;
            //users[size].id = setID(ID);
            users[size].setID(ID);

            cout<<"\nEnter the name---> ";
            cin>>name;
            //users[size].name = setName(name);
            users[size].setName(name);

            cout<<"\nEnter the rank---> ";
            cin>>rank;
            users[size].setRank(rank);
            int high = to_string(ID).length()-1;

            if(users[size].palindrome(0, high, ID)){
                cout<<"\nThe officer is not allowed to enter the restrictes area ";
            }
            else{
                cout<<"\nThe user is allowed to enter the restricted area ";
            }
            size++;

        }
        else if(option == 2){
            cout<<"\n officers cout: "<<users[size].showcount();
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

int main(){
    menu();
}