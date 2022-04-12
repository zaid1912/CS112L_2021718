#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
 
 class matrixType{
     private:
     int rows, cols;
     int **matrix;
     public:
    matrixType(int r = 0, int c = 0){
        rows = r;
        cols = c;
        matrix = new int*[r];
        for(int i = 0; i<rows; i++){
            matrix[i] = new int[cols];   
        }
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                matrix[i][j] = rand()%10;
            }
        }
    }

    matrixType operator+(matrixType &b){
        matrixType temp(b.rows, b.cols);
        for(int i = 0; i<b.rows; i++){
            for(int j = 0; j<b.cols; j++){
                temp.matrix[i][j] = this->matrix[i][j] + b.matrix[i][j];
            }
        }
        return temp;
    }

    matrixType operator-(matrixType &b){
        matrixType temp(b.rows,b.cols);
        for(int i = 0; i<b.rows; i++){
            for(int j = 0; j<b.cols; j++){
                temp.matrix[i][j] = this->matrix[i][j] - b.matrix[i][j];
            }
        }
        return temp;
    }

    matrixType operator*(matrixType &b){
        matrixType temp(this->rows,b.cols);
        for(int i = 0; i<this->rows; i++){
            for(int j = 0; j<b.cols; j++){
                temp.matrix[i][j] = 0;
            }
        }
        for(int i = 0; i<this->rows; i++){
            for(int j = 0; j<b.cols; j++){
                for(int k = 0; k<this->cols; k++){
                    temp.matrix[i][j] += this->matrix[i][k] * b.matrix[k][j];
                }
                
            }
        }
        return temp;
    }

    friend ostream& operator<<(ostream & out, matrixType &result){
        cout<<endl<<endl;
        for(int i = 0; i<result.rows; i++){
            for(int j = 0; j<result.cols; j++){
                out<<setw(5)<<result.matrix[i][j];
            }
            out<<endl;
        }
        return out;
    }

 };

 int main(){
    srand(time(0));
    matrixType A(2, 2);
    matrixType B(2, 2);
    cout<<A;
    cout<<B;
    matrixType sum;
    matrixType sub;
    matrixType mult;
    sum = A+B;
    sub = A-B;
    mult = A*B;
    cout<<sum;
    cout<<sub;
    cout<<mult;
 }