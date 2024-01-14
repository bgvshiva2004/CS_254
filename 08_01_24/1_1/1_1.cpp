#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(ll i=a;i<b;i++)
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

    ll n;
    inputFile>>n;
    ll a[n],max=INT_MIN,index=0;
    fr(i,0,n){
        // taking the input
        inputFile>>a[i];
        // finding the max element in the array
        if(a[i]>max){max=a[i];index=i;}
    }
    // masking the max element so as to find the second max element
    a[index]=INT_MIN;
    ll sec_max = INT_MIN;
    fr(i,0,n){
        // finding second max element 
        if(a[i]>sec_max){sec_max=a[i];}
    }
    // printing and storing the output 
    outputFile<<"The maximum sum possible is: "<<max+sec_max<<endl;
}