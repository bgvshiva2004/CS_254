#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MatrixAdd(const vector<vector<int>> &A, const vector<vector<int>> &B){
    int n = A.size(); 
    vector<vector<int>> C(n,vector<int>(n)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j]; 
        }
    }
    return C; 
}

vector<vector<int>> MatrixMult(vector<vector<int>>& A,vector<vector<int>>& B){
    int n = A.size();
    if (n == 1){
        return {{A[0][0] * B[0][0]}};
    }
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half));
    vector<vector<int>> A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half));
    vector<vector<int>> A22(half, vector<int>(half));
    vector<vector<int>> B11(half, vector<int>(half));
    vector<vector<int>> B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half));
    vector<vector<int>> B22(half, vector<int>(half));
    for (int i = 0; i < half; ++i){
        for (int j = 0; j < half; ++j){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    vector<vector<int>> C11 = MatrixAdd(MatrixMult(A11, B11),MatrixMult(A12, B21));
    vector<vector<int>> C12 = MatrixAdd(MatrixMult(A11, B12),MatrixMult(A12, B22));
    vector<vector<int>> C21 = MatrixAdd(MatrixMult(A21, B11),MatrixMult(A22, B21));
    vector<vector<int>> C22 = MatrixAdd(MatrixMult(A21, B12),MatrixMult(A22, B22));
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < half; ++i){
        for (int j = 0; j < half; ++j){
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }
    return result;
}

// int __bit_ceil(int n) {
//     int result = 1;
//     while (result < n) {
//         result <<= 1; 
//     }
//     return result;
// }

int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    int n; inputFile>>n; 
    int size = __bit_ceil(n); 
    vector<vector<int>> A(size,vector<int>(size));
    vector<vector<int>> B(size,vector<int>(size));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            inputFile>>A[i][j]; 
        }
    } 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            inputFile>>B[i][j]; 
        }
    }
    inputFile.close();

    vector<vector<int>> C = MatrixMult(A,B); 
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            outputFile<<C[i][j]<<" "; 
        }
        outputFile<<endl;
    }
    
    return 0;
}