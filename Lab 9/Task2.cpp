#include<iostream>
using namespace std;


class myFather{
    protected:
    string fname, fhaircolor, feyecolor;
    public:
    myFather(){}//default constructor
    virtual void display(){
        cout<<"\nFather name: "<<fname;
        cout<<"\nFather hair color: "<<fhaircolor;
        cout<<"\nFather eye color: "<<feyecolor;
    };
    void setfname(string n){
        fname = n;
    }
    void setfhaircolor(string hc){
        fhaircolor = hc;
    }
    void setfeyecolor(string ec){
        feyecolor = ec;
    }

    string getfname() const{
        return fname;
    }
    string getfhaircolor() const{
        return fhaircolor;
    }
    string getfeyecolor() const{
        return feyecolor;
    }
    ~myFather(){}

};

class myMother{
    protected:
    myMother(){}//default constructor
    string mname, mhaircolor, meyecolor;
    public:
    virtual void display(){
        cout<<"\nmother name: "<<mname;
        cout<<"\nmother hair color: "<<mhaircolor;
        cout<<"\nmother eye color: "<<meyecolor;
    };
    void setmname(string n){
        mname = n;
    }
    void setmhaircolor(string hc){
        mhaircolor = hc;
    }
    void setmeyecolor(string ec){
        meyecolor = ec;
    }

    string getmname() const{
        return mname;
    }
    string getmhaircolor() const{
        return mhaircolor;
    }
    string getmeyecolor() const{
        return meyecolor;
    }
    ~myMother(){}
    

};

class mySelf: public myFather{
    protected:
    string myname, myhaircolor, myeyecolor;
    string education;
    int age;
    public:
    mySelf(){}
    void display(){
        myFather::display();
        cout<<"\nmy name: "<<myname;
        cout<<"\nmy hair color: "<<myhaircolor;
        cout<<"\nmy eye color: "<<myeyecolor;
        cout<<"\nmy education: "<<education;
        cout<<"\nmy age: "<<age;
    };
    void setMyname(string n){
        myname = n;
    }
    void setMyhaircolor(string hc){
        myhaircolor = hc;
    }
    void setMyeyecolor(string ec){
        myeyecolor = ec;
    }

    string getMyname() const{
        return myname;
    }
    string getMyhaircolor() const{
        return myhaircolor;
    }
    string getMyeyecolor() const{
        return myeyecolor;
    }

    void setMyed(string ed){
        education = ed;
    }
    void setMyage(int a){
        age = a;

    }

    string getMyed() const{
        return education;
    }
    int getMyage() const{
        return age;
    }

    ~mySelf(){}

};

class mySister: public myFather, public myMother{
    protected:
    string education;
    int age;
    string sisname, sishaircolor, siseyecolor;
    
    public:
    mySister(){}
    void display(){
        //myFather::display();
        myMother::display();
        cout<<"\nsister's name: "<<sisname;
        cout<<"\nsister's hair color: "<<sishaircolor;
        cout<<"\nsister's eye color: "<<siseyecolor;
        cout<<"\nsister's education: "<<education;
        cout<<"\nsister's age: "<<age;
    };
    void setsisname(string n){
        sisname = n;
    }
    void setsishaircolor(string hc){
        sishaircolor = hc;
    }
    void setsiseyecolor(string ec){
        siseyecolor = ec;
    }
    void setsised(string ed){
        education = ed;
    }
    void setsisage(int a){
        age = a;

    }

    string geted() const{
        return education;
    }
    int getage() const{
        return age;
    }

    string getname() const{
        return sisname;
    }
    string gethaircolor() const{
        return sishaircolor;
    }
    string geteyecolor() const{
        return siseyecolor;
    }
    ~mySister(){}
};

int main(){
    myFather *f;
    mySelf s;
    s.setMyname("Zaid");
    s.setMyhaircolor("Black");
    s.setMyeyecolor("brown");
    s.setMyed("BSc.");
    s.setMyage(20);
    
    f = &s;
    f->setfname("Muzammil");
    f->setfhaircolor("Black");
    f->setfeyecolor("Black");
    f->display();//this will call the display function of myself but inside myself diplay function, I have called the display function of myFather. Therefore, it will display the values of Father and myself.
    myMother *m;
    mySister ms;
    m = &ms;
    m->setmname("mama");
    m->setmhaircolor("brown");
    m->setmeyecolor("golden");
    ms.setsisname("Maryam");
    ms.setsisage(0);
    ms.setsised("olevel");
    ms.setsiseyecolor("black");
    ms.setsishaircolor("brown");
    m->display();

}