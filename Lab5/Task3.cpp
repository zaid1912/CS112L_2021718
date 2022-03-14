#include<iostream>
using namespace std;

class stringType
{
    private:
    string first, second;
    public:

    stringType(string s1 = "", string s2 = ""){
        first = s1;
        second = s2;
    }
    void setValues(string s1, string s2){
        first = s1;
        second = s2;

    }

    void printValues(){
        cout<<"First = "<<first;
        cout<<"\nSecond = "<<second<<endl;
    }

    //function for checking the length of a string
    int CheckLen(string s){
        int i = 0;
        while(s[i] != '\0'){
            i++;
        }
        return i;
    }

    //finding the string that has a maximum length 
    int maxLength(){
        int LengthS1, LengthS2;
        LengthS1 = CheckLen(first);
        LengthS2 = CheckLen(second);
        if(LengthS1 > LengthS2){
            return LengthS1;
        }
        else{
            return LengthS2;
        }

    }

    int compare(string s1, string s2){
        
        return (s1 == s2);
    }

    void copy(string source, string destination){
        destination = "";
        destination = source;
    }

    int searchWord(string word){
        int wordLen = CheckLen(word);
        int startCompIndex = 0, flag = 0;
        string s3 = "";

        //FINDING THE WORD IN FIRST STRING
        for(int i = 0; i<=(CheckLen(first) - wordLen); i++){
            for(int j = startCompIndex; j<wordLen+i; j++){
                s3 += first[j];
            }
            if(s3 == word){
                return 1;
            }
            startCompIndex++;
            s3 = "";
        }



        s3 = "";
        startCompIndex = 0;
        //FINDING THE WORD IN SECOND STRING
        for(int i = 0; i<=(CheckLen(second) - wordLen); i++){
            for(int j = startCompIndex; j<wordLen+i; j++){
                s3 += second[j];
            }
            if(s3 == word){
                return 1;
            }
            startCompIndex++;
            s3 = "";
        }
        return 0;
    }

    int searchChar(char c){
        for(int i = 0; i<CheckLen(first); i++){
            if(c == first[i]){
                return 1;
            }
        }
        for(int i = 0; i<CheckLen(second); i++){
            if(c == second[i]){
                return 1;
            }
        }
        return 0;
    }

    string concatenate(string s1, string s2){
        s1 = s1 + s2;
        return s1;
    }
    ~ stringType(){
        cout<<"Destructor";
    }

};

int main()
{
    stringType s;
    //s.setValues("holacoolmac", "rajaeqoihd");
    // cout<<endl<<s.maxLength();
    // cout<<endl<<s.compare("ZaId", "Zaid");
    // s.copy("zaid", "raja");
    //cout<<endl<<s.concatenate("raja", "zaid");
    //cout<<endl<<s.searchWord("cool")<<endl;
    //cout<<endl<<s.searchChar('a');
    //s.printValues();

}
