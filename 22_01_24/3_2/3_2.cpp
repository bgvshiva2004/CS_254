#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct array_terms{
    ll max_subarray_sum,max_prefix,max_suffix,sum;
};

array_terms get_max_subarray(vector<int> &arr,int l,int r){
    if(r-l ==1){
        return {arr[l],arr[l],arr[l],arr[l]};
    }
    int mid = l+ (r-l)/2;
    array_terms left_data = get_max_subarray(arr,l,mid);
    array_terms right_data = get_max_subarray(arr,mid,r);
    array_terms result;
    result.max_subarray_sum = max({left_data.max_subarray_sum,right_data.max_subarray_sum,left_data.max_suffix + right_data.max_prefix});
    result.max_prefix = max({left_data.max_prefix,left_data.sum+right_data.max_prefix});
    result.max_suffix = max({right_data.max_suffix,right_data.sum + left_data.max_suffix});
    result.sum = left_data.sum + right_data.sum;
    return result;
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

    int n;inputFile>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){inputFile>>a[i];}
    inputFile.close();
    clock_t start,end;
    start=clock();
             array_terms result = get_max_subarray(a,0,n);
    end=clock();
    outputFile<<"The maximum sum of the subarray that could be possible is: "<<result.max_subarray_sum<<endl;
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
    
}