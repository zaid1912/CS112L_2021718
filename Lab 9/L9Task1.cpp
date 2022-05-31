#include<iostream>
using namespace std;

class vehicle{

    protected:
    int noOfTires, noOfSeats;
    char size;

    public:
    virtual void setVal(){
        cout<<"Enter size: ";
        cin>>size;

        cout<<"\nEnter number of tires: ";
        cin>>noOfTires;

        cout<<"\nEnter number of seats: ";
        cin>>noOfSeats;
    }

    virtual void disp(){
        cout<<"\nPRINITING DETAILS\ntires: "<<noOfTires;
        cout<<"\nseats: "<<noOfSeats;
        cout<<"\nsize: "<<size;
    }

    int gettires(){
        return noOfTires;
    }

    int getseats(){
        return noOfSeats;
    }

    char getsize(){
        return size;
    }

};

class car: public vehicle{

    protected:    
    string color;

    public:
    void setVal(){
        cout<<"ENTER CAR DETAILS: ";
        //calling the setter of base class(vehicle) as first three attributes are same ie. size, seats, and tires
        vehicle::setVal();  //overriding a function
        //setting the color of car
        cout<<"\nEnter color: ";
        cin>>color;
    }
    string getcolor(){
        return color;
    }
    void disp(){
        //calling the display function of base class(vehicle) as first three attributes are same ie. size, seats, and tires
        vehicle::disp();   //overriding a function
        //displaying the color of car along
        cout<<"\ncolor: "<<color;
    }
};


class vitz: public car{

    protected:
    int model;
    string platenum;

    public:
    void setVal(){
        cout<<"\nSet the values for vitz: \n";
        ////calling the setter of base class(car) as first fout attributes are same ie. size, seats, tires, and color
        car::setVal(); //overriding
        //setting the model and plate number of vitz
        cout<<"\nEnter the model: ";
        cin>>model;

        cout<<"\nEnter the plate number: ";
        cin>>platenum;
    }
    string getplate(){
        return platenum;
    }
    int getmodel(){
        return model;
    }
    void disp(){
        cout<<"\nVITZ DETAILS\n";
        //calling the display function of base class(vehicle) as first three attributes are same ie. size, seats, tires, and color
        car::disp();  //overriding
        //displaying the model and plate number of vitz along with other details.
        cout<<"\nplate Number: "<<platenum;
        cout<<"\nmodel: "<<model;
    }

};
int main(){
    //pointer of base class(vehicle)
    vehicle *v;
    //car c;
    //v=&c;
    //object of class vitz
    vitz vitzcar;
    //base class pointer contains the address of object of vitz class
    v = &vitzcar;

    v->setVal();
    v->disp();
}