#include<iostream>
#include<math.h>
//defineing a macro
#define toggle(x, y)(x^(1<<y))
using namespace std;


struct yVal{
    int n1;
    int y;

};

struct xVal{
    int x;
    struct yVal n;
};

void distance(xVal citiesArr[], int size){
    int distanceArr[5][5];
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            //applying distance formula given in exam
            distanceArr[i][j] = abs(citiesArr[i].x - citiesArr[j].x) + abs(citiesArr[i].n.y - citiesArr[j].n.y);

        }
    }
    cout<<endl<<"The pairwise distance matrix is: "<<endl;
    //printing the 2D array of manhattan distance from each city to another
    for(int a = 0; a<5; a++){
        for(int b = 0; b<5; b++){
            cout<<distanceArr[a][b]<<"   ";
        }
        cout<<endl;
    }
}

int main(){
    //array to store each city's x and n
    xVal cities[5];
    cout<<"Enter 5 numbers: \n";
    for(int i = 0; i<5; i++){
        cout<<"\nEnter any 32 bit value: ";
        //storing the x value for each city
        cin>>cities[i].x;
        cout<<"\nEnter any value to toggle(0-31): ";
        //storing the n value(to toggle) for each city
        cin>>cities[i].n.n1;
        //calculating the y value of each city using x and n through macro defined above
        cities[i].n.y = toggle(cities[i].x, cities[i].n.n1);
    }
    cout<<"Values before toggling:                   Values after toggling:\n";
    for(int j = 0; j<5; j++){
        cout<<cities[j].x<<"                                                "<<cities[j].n.y<<endl;
        
    }
    //caling distance function that will calculate the manhattan distance from each city to another
    distance(cities, 5);
}