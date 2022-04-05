#include<iostream>
using namespace std;
//coordinator class is a friend person class
class coordinator;
//class person;

class person{
    private:
    string compUni;
    public:
    friend class coordinator;
    string getter(){
        return compUni;
    }
    //~person();

};
class coordinator{
    private:
    person p1;
    person p2;
    public:
    
    void setter_p1(string name){
        p1.compUni = name;
        

    } 
    void setter_p2(string name){
        p2.compUni = name;

    } 

    string str1(){
        return p1.getter();
        //cout<<p2.getter();
    }
    string str2(){
        return p2.getter();
        //cout<<p2.getter();
    }
    //~coordinator();

};

void compare (string s1, string s2){
    int i, k;
    string uni1 = "", uni2="";
    for(i = 0; i < s1.length(); i++){
        if(s1[i] == ' '){
            break;
        }
    }
    i++;
    for(int j = i; j<s1.length(); j++){
        uni1+=s1[j];
    }
    //cout<<uni1;

    for(k = 0; i < s2.length(); k++){
        if(s2[k] == ' '){
            break;
        }
    }
    k++;
    for(int j = k; j<s2.length(); j++){
        uni2+=s2[j];
    }
    //cout<<uni2;
    //cout<<endl<<i<<endl<<k<<endl;
    if(uni1 == uni2){
        if(i >= k){
            cout<<endl<<"person 1 and person 2 are roommates and room number is "<<i-1;
        }
        else{
            cout<<endl<<"person 1 and person 2 are roommates and room number is "<<k-1;
        }

    }
    else{
        cout<<endl<<"\nperson 1 and person 2 are not roommates";
    }
    

}
int main(){
    coordinator c1, c2, c;
    string p1, p2;
    cout<<"enter the competition name and uni name: ";
    getline(cin, p1);
    c1.setter_p1(p1);
    //cin.ignore();
    cout<<"enter the competition name and uni name: ";
    getline(cin, p2);
    c2.setter_p2(p2);
    string s1 = c1.str1();
    string s2 = c2.str2();
    compare(s1, s2);
    return 0;
}