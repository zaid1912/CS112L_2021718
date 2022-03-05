#include<iostream>
using namespace std;
struct DOB{
    int day, year;
    string month;
};
struct user{
    string name;
    int age;
    string city;
    DOB dateofbirth;
};

int main(){
    user s[3];
    int day, year;
    string month;
    for(int i = 0; i<3; i++){
        cout<<"Enter the record of user "<<i+1<<": \n\n";
        cout<<"Enter the name: ";
        cin>>s[i].name;
        cout<<"\nEnter the age: ";
        cin>>s[i].age;
        cout<<"\nEnter the city: ";
        cin>>s[i].city;
        cout<<"\nEnter the DOB: \n";
        cout<<"Enter Day: ";
        cin>>s[i].dateofbirth.day;
        cout<<"\nEnter the month: ";
        cin>>s[i].dateofbirth.month;
        cout<<"\nEnter the year: ";
        cin>>s[i].dateofbirth.year;
    }
    cout<<endl<<endl<<"ENTER THE DATA TO WISH BIRTHDAY: \nEnter the DOB to check:\nEnter day: ";
    cin>>day;
    cout<<"\nEnter month: ";
    cin>>month;
    cout<<"\nEnter year: ";
    cin>>year;

    for(int i = 0; i<3; i++){
        if(month==s[i].dateofbirth.month && day==s[i].dateofbirth.day && year == s[i].dateofbirth.year){
            cout<<"\nIt is "<<s[i].name<<"'s Birthday. Happy Birthday, "<<s[i].name<<endl;
            break;
        }
    }
}