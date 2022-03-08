#include<iostream>
#include<iomanip>
using namespace std;
//using std setw;

struct info{
    string name, regNo, program;
    int courses;
    float sgpa;    
};

float gradePoint(int marks){
    float gp = 0;
    if(marks>86)
        gp=4;
    else if(marks>82 && marks<=86)
        gp=3.67;
    else if(marks>78 && marks<=82)
        gp=3.33;
    else if(marks>74 && marks<=78)
        gp=3;
    else if(marks>70 && marks<=74)
        gp=2.67;
    else if(marks>66 && marks<=70)
        gp=2.33;
    else if(marks>50 && marks<=66)
        gp=2;
    else 
        gp=1.67;
    return gp;
}


void sortSGPA(string name[], string regno[], string program[], int sgpa[], const int size=3){
    for(int i = size; i>=0; i--){
        for(int j = 0; j<i;j++){
            if(sgpa[i]<sgpa[i+1]){
                swap(sgpa[j], sgpa[j+1]);
                swap(name[j], name[j+1]);
                swap(regno[j], regno[j+1]);
                swap(program[j], program[i+1]);
            }
    }
    }
    cout<<"\nSORTED OUTPUT: \n";
    cout<<"S.No"<<setw(10)<<"name"<<setw(10)<<"RegNo"<<setw(10)<<"Degree Program"<<setw(10)<<"SGPA\n";
    for(int k = 0; k<3; k++){
        cout<<k+1<<setw(10)<<name[k]<<setw(10)<<regno[k]<<setw(10)<<program[k]<<setw(10)<<sgpa[k]<<endl;
    }
    cout<<"\nThe best student is: ";
    cout<<setw(10)<<name[0]<<setw(10)<<regno[0]<<setw(10)<<program[0]<<setw(10)<<sgpa[0]<<endl;
}

int main(){
    info s[3];
    string name[3], regno[3], program[3];
    int sgpa[3];
    //float gp;

    for(int i = 0; i<3; i++){
        
        cout<<endl<<"Enter the name of student: ";
        cin>>s[i].name;
        name[i] = s[i].name;
        cout<<endl<<"Enter the regNo of student: ";
        cin>>s[i].regNo;
        regno[i] = s[i].regNo;
        cout<<endl<<"Enter the program of student: ";
        cin>>s[i].program;
        program[i] = s[i].program;
        cout<<endl<<"Enter the number of courses: ";
        cin>>s[i].courses;
        int marks;
        float numerator=0;
        for(int j = 0; j<s[i].courses; j++){
            cout<<endl<<"Enter the marks of course " <<j+1<<": ";
            cin>>marks;
            numerator += gradePoint(marks)*3;   
        }

        s[i].sgpa = numerator/(s[i].courses*3);
        sgpa[i] = s[i].sgpa;
        
    }
    cout<<"S.No"<<setw(10)<<"name"<<setw(10)<<"RegNo"<<setw(10)<<"Degree Program"<<setw(10)<<"SGPA\n";
    for(int k = 0; k<3; k++){
        cout<<k+1<<setw(10)<<s[k].name<<setw(10)<<s[k].regNo<<setw(10)<<s[k].program<<setw(10)<<s[k].sgpa<<endl;
    }

    //sorting function call: 
    sortSGPA(name, regno, program, sgpa, 3);


}