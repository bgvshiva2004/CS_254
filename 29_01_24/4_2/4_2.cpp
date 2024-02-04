#include<bits/stdc++.h>
using namespace std;

double Median(vector<int>& A,vector<int>& B){
    int n=A.size(),m=B.size();
    if(n>m){return Median(B,A);}

    int start = 0,end=n, orgMed = (n+m+1)/2;

    while(start<=end){
        int mid = start + (end-start)/2;
        int leftAsize = mid;
        int leftBsize = orgMed-mid;
        int leftA = (leftAsize >0)? A[leftAsize - 1]:INT_MIN;
        int leftB = (leftBsize >0)? B[leftBsize-1]:INT_MIN;
        int rightA = (leftAsize<n)? A[leftAsize]:INT_MAX;
        int rightB = (leftBsize<m)? B[leftBsize]:INT_MAX;

        if(leftA<=rightB && leftB<=rightA){
            if((m+n)%2 ==0){
                return (max(leftA,leftB)+min(rightA,rightB))/2.0;
            }
            return max(leftA,leftB);
        }
        else if(leftA>rightB){
            end = mid-1;
        }
        else start = mid+1;
    }
    return 0.0;
}

int main(){
     ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }
    int t;inputFile>>t;
    while(t--){
        int m,n;inputFile>>m>>n;
        vector<int> num1(m),num2(n);
        for(int i=0;i<m;i++){inputFile>>num1[i];}
        for(int i=0;i<n;i++){inputFile>>num2[i];}
        clock_t start,end;
        start=clock();
        outputFile<<"The median of the given arrays is: "<<Median(num1,num2)<<endl;
        double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
        outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
    }
    
}