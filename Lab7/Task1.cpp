#include<iostream>
using namespace std;

class person;
class date;

class date{
    private:
    int year, month, day;
    public:
    //constructor
    date(int year = 0,int month = 0,int day = 0){}

    //operator overloading for input of date
    friend istream& operator>>(istream& in, date &d){
        in>>d.year>>d.month>>d.day;
        return in;
    }
    //operator overloading for comparision of dates of joining
    bool operator<(date b){
        if(year==b.year){
            if(month == b.month){
                if(day < b.day){
                    return true;
                    
                }
                else if(month < b.month){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(month<b.month){
                return true;
            }
            else{
                return false;
            }
           
        }
         else if(year<b.year){
            return true;
        }
        else{
            return false;
        }
    }
    //operator overloading for output date
    friend ostream& operator<<(ostream& out, date &d){
        out<<d.year<<" "<<d.month<<" "<<d.day;
        return out;
    }
    //person class can access the members of this class
    friend class person;
    //destructor
    ~date(){}

};

class person{
    private:
    string username;
    int Id;
    static int count;
    date d1;
    public:
    //constructor
    person(string username = "", int Id = 0){
        count++;
    }

    void setDate(){
        cout<<"\nEnter joining date (yyyy mm dd): ";
        cin>>d1;
    }

    //called only when the joining date of person p is required
    date getDate(person& p){
        return p.d1;
    }
    static int getCount(){
        return count;
    }

    //operator overloading for input
    friend istream& operator>>(istream& in, person &p){
        in>>p.username >> p.Id;
        p.setDate();
        return in;
    }
    //operator overloading for output
    friend ostream& operator<<(ostream& out, person &p){
        out<<p.username;
        return out;
    }

    void senior(person &p){
        cout<<" is senior because "<<p.d1<<" is earlier";
    }
    //destructor
    ~person(){}

};
int person::count=0;

int main(){
    person p1;
    cout<<"\nEnter the username and ID of user "<<person::getCount()<<": ";
    cin>>p1;

    person p2;
    cout<<"\nEnter the username and ID of user "<<person::getCount()<<": ";
    cin>>p2;
    if(p1.getDate(p1)<p2.getDate(p2)){
        cout<<p1;
        p1.senior(p1);
    }
    else{
        cout<<p2;
        p2.senior(p2);
    }
}