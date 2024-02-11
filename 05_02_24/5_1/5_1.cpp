#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& matrix,int row,int col,int total_rows,int total_cols){
    // cout<<"dfs called"<<endl;
    if(row<0 || col<0 || row >= total_rows || col >= total_cols || matrix[row][col]==0){return 0;}
    matrix[row][col]=0;
    int size = 1;
    // cout<<"Size initiated"<<endl;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            size += dfs(matrix,row+i,col+j,total_rows,total_cols);
        }
    }
    return size;
}

int main(){
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    // Displaying the error while opening input or output files (if there is any)
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }

    // cout<<"Size: ";
    int n,m;
    inputFile>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    // cout<<"Input: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            inputFile>>matrix[i][j];
        }
    }

    int max_region = 0;

    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(matrix[row][col]==1){
                max_region = max(max_region,dfs(matrix,row,col,n,m));
            }
        }
    }
    outputFile<<"The largest possible region is: "<<max_region<<endl;
    return 0;
}