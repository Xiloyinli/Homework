#include <iostream>
#include <vector>
using std::vector;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> matrix;
public:
    Matrix(int r,int c):rows(r),cols(c){
        matrix.resize(r,vector<int>(c,0));
    }
    friend istream & operator >> (istream & putin,Matrix & inmatrix){
        for (int i=0;i<inmatrix.rows;i++){
            for (int j=0;j<inmatrix.cols;j++){
                putin >> inmatrix.matrix[i][j];
            }
        }
        return putin; 
    }
    friend ostream & operator << (ostream & putout,const Matrix & outmatrix){
        for (int i=0;i<outmatrix.rows;i++){
            for (int j=0;j<outmatrix.cols;j++){
                putout << outmatrix.matrix[i][j] << " ";
            }
            putout << "\n";
        }
        return putout;
    }
    Matrix operator * (const Matrix & other){
        Matrix final(rows,other.cols);
        for (int i=0;i<rows;i++){
            for (int j=0;j<other.cols;j++){
                int sum=0;
                for (int k=0;k<cols;k++){
                    sum+=matrix[i][k]*other.matrix[k][j];
                }
                final.matrix[i][j]=sum;
            }
        }
        return final;
    }
};