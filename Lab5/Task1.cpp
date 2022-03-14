#include<iostream>
using namespace std;

class heater
{
    private:
    int temperature;
    public:
    heater(){
        temperature = 15;
    }
    void warmer(){
        temperature+=5;
    }
    void cooler(){
        temperature-=5;
    }
    int accessor(){
        return temperature;
    }

    ~heater(){
        cout<<"\nHave a good day!\n";
    }
};

int main()
{
    int option;
    heater t;
    cout<<"\nEnter a number to call:\n1. Warmer\n2.Cooler\nEnter any other key to exit";
    cout<<"\nTemperature = "<<t.accessor();
    cout<<endl<<"---->";
    while(1){
        cin>>option;
        if(option == 1){
            t.warmer();
            cout<<"\nTemperature = "<<t.accessor();
            cout<<endl<<"---->";
        }
        else if(option == 2){
            t.cooler();
            cout<<"\nTemperature = "<<t.accessor();
            cout<<endl<<"---->";
        }
        else{
            cout<<"\n......EXITING.....\n";
            break;
        }

    }
}