#include<iostream>
#include<iomanip>
using namespace std;
class twoDArray{
    private:
    const static int size = 2;
    int A[size][size];
    int B[size][size];
    int tempMatrix[size][size];
    public:
    void initialize(){
        cout<<"Enter the values in array 1:\n";
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cin>>A[i][j];
            }
        }
        cout<<"Enter the values in array 2:\n";
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cin>>B[i][j];
            }
        }
    }
    void print(){
        cout<<"\nprinting the values of matrix 1:\n";
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cout<<setw(8)<<A[i][j];
            }
            cout<<endl;
        }
        cout<<"\nprinting the values of matrix 2:\n";
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cout<<setw(8)<<B[i][j];
            }
            cout<<endl;
        }
    }
    void transpose(){  //for matrix A
        
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                tempMatrix[i][j] = A[j][i];
            }
        }
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cout<<setw(8)<<tempMatrix[i][j];
            }
            cout<<endl;
        }
        
    }
    bool isSymmetry(){
        bool symmetric = true;
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                tempMatrix[i][j] = A[j][i];
                if(tempMatrix[i][j] != A[i][j]){    //comparing each element of transpose with each element of matrix A
                    symmetric = false;
                    cout<<"\nThe matrix is not symmetric\n";
                    return false;
                }
            }
        }
        return symmetric;
        
    }
    void multiply(){
        int C[size][size] = {0};
        for(int i = 0;i<size; i++){
            for(int j = 0; j<size; j++){
                for(int k = 0; k<size; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        for(int i = 0; i<size;i++){
            for(int j = 0; j<size; j++){
                cout<<setw(8)<<C[i][j];
            }
            cout<<endl;
        }
    }





};

void menu(){
    int option;
    twoDArray z;
    cout<<"Options: \n1.initialize\n2.print\n3.transpose\n4.symmetry check\n5.multiply\n";
    while(1){
        cout<<"Enter an option(between 1 and 5. Enter any other number to exit): \n";
        cin>>option;
        if(option<1 or option>5){
            cout<<"Invalid option......exiting";
            break;
        }
        else if(option == 1){
            z.initialize();
        }
        else if(option == 2){
            z.print();
        }
        else if(option == 3){
            z.transpose();
        }
        else if(option == 4){
            bool symmetry;
            symmetry = z.isSymmetry();
            if(symmetry){
                cout<<"The matrix is symmetric\n";
            }
        }
        else if(option == 5){
            z.multiply();
        }
        
        
    }
}

int main(){
    menu();
    // twoDArray z;
    // z.initialize();
    // z.print();
}