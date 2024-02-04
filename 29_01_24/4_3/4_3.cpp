#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& a,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i:a){
        minHeap.push(i);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    return minHeap.top();
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
        int n,k;inputFile>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){inputFile>>a[i];}
        clock_t start,end;
        start=clock();
        outputFile<< "The kth largest element is: "<< kthLargest(a,k) <<endl;
        end=clock();
        double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
        outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
    }
}