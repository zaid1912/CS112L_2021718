#include<iostream>
#define pi 3.142
using namespace std;

class shapes{
    protected:
    int len, width;

    public:
    virtual double area()=0;   //pure virtual function as the area for each shape would be calculated using a different formula

    void setl(int l){
        len = l;
    }
    void setw(int w){
        width = w;
    }
    int getl(){
        return len;
    }
    int getw(){
        return width;
    }
};

class twodshapes: public shapes{
    public:
    virtual double area() = 0;   //pure virtual function for area as every 2 dimentional shape has a different formula for calculating area
    
};

class threedshapes: public shapes{
    public:
    virtual double volume() = 0; //pure virtual function for volume as the volume varies upon the shape(3D)
    virtual double area() = 0;//pure virtual function for area of 3D shapes
};

class circle:public twodshapes{
    protected:
    int radius;
    string color;
    public:
    circle(){}
    double area(){
        return(pi*radius*radius); 
    }

    string getcolor() const{
        return color;
    }
    int getradius() const{
        return radius;
    }
    void setcolor(string c){
        color = c;
    }
    void setradius(int r){
        radius = r;
    }
    ~circle(){}
};

class square: public twodshapes{
    protected:
    int side;
    string color;
    public:
    square(){}
    double area(){
        return(side*side);
    }
    void setside(int s){
        side = s;
        // len = s;
        // width = s;
    }
    int getside(){
        return side;
    }

    void setcolor(string c){
        color = c;
    }

    string getcolor() const{
        return color;
    }
    ~square(){}
};

class cube: public threedshapes{
    protected:
    int height;
    public:
    cube(){}
    void seth(int h){
        height = h;
    }
    
    double area(){
        return(6*len*width);
    }
    double volume(){
        return(len*width*height);
    }

    int geth(){
        return height;
    }

    int getw(){
        return width;
    }
    int getl(){
        return len;
    }
    ~cube(){}
};

class pyramid: public threedshapes{
    protected:
    int height, base;
    public:
    pyramid(){}
    void seth(int h){
        height = h;
    }
    void setb(int b){
        base = b;
    }
    
    double area(){
        return(base*base);
    }
    double volume(){
        return(base*base*height);
    }

    int geth(){
        return height;
    }

    int getb(){
        return base;
    }
    ~pyramid(){}
    
};


int main(){

    shapes *sh;
    twodshapes *sh2d;

    //cicle object
    circle c1;
    sh2d = &c1;
    c1.setcolor("blue");
    c1.setradius(3);
    cout<<"Circle Radius = "<<c1.getradius();
    cout<<"\nCircle Area = "<<sh2d->area();
    cout<<endl<<"Circle Color = "<<c1.getcolor();

    //square object
    square s1;
    sh2d = &s1;
    s1.setcolor("red");
    s1.setside(3);
    cout<<"\nSquare Side = "<<s1.getside();
    cout<<"\nSquare Area = "<<sh2d->area();
    cout<<endl<<"Square Color = "<<s1.getcolor();

    //cube object
    threedshapes *tds;
    cube c2;
    tds = &c2;
    tds->setl(4);
    tds->setw(4);
    c2.seth(4);
    cout<<"\nCube Area = "<<tds->area();
    cout<<"\nCube Volume = "<<tds->volume();

    //pyramid object
    pyramid p1;
    tds = &p1;
    p1.seth(8);
    p1.setb(3);
    cout<<"\nPyramid Area = "<<tds->area();
    cout<<"\nPyramid Volume = "<<tds->volume();    
}