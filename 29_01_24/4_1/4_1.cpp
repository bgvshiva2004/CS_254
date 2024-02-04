#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<int>& arr,vector<int>& temp,int l,int mid,int r){
    ll inversions = 0;
    int i=l,j=mid,k=l;
    while((i<=mid - 1)&&(j<= r)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inversions += (mid-i);
        }
    }
    while(i<=mid-1){temp[k++]=arr[i++];}
    while(j<=r){temp[k++]=arr[j++];}
    for(i=l;i<=r;i++){
        arr[i]=temp[i];
    }
    return inversions;
}

ll mergesort(vector<int>& arr,vector<int>& temp,int l,int r){
    ll inversions = 0;
    if(r>l){
        int mid = l+(r-l)/2;
        inversions += mergesort(arr,temp,l,mid);
        inversions += mergesort(arr,temp,mid+1,r);
        inversions+= merge(arr,temp,l,mid+1,r);
    }
    return inversions;
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
        int n;inputFile>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){inputFile>>a[i];}
        vector<int> temp(n);
        clock_t start,end;
        start=clock();
        ll ans = mergesort(a,temp,0,n-1);
        outputFile<<"The no.of of inversions are: "<<ans<<endl;
        double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
        outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
    }
    
}