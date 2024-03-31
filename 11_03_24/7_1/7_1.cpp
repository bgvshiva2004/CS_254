#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<double,double>& a,const pair<double,double>& b){
    if(a.first==b.first){
        return a.second< b.second;
    }
    return a.first>b.first;
}

int knapsack(int max_weight, vector<int> &weights, vector<int> &values){
    int n = weights.size();
    vector<int> dp(max_weight+1);
    for(int i=0; i<n; i++)
        for(int j=max_weight; j>=weights[i]; j--)
            dp[j] = max(dp[j], dp[j-weights[i]]+values[i]);
    return dp[max_weight];
}

void greedy(int n,int W,vector<double> weights,vector<double> values){
    cout<<"The following is the solution given using greedy approach: \n";
    double w = 0,v=0;
    vector<pair<double,double>> v_w(n);
    for(int i=0;i<n;i++){
        v_w[i].first = (values[i]/weights[i]);
        v_w[i].second = weights[i];
    }
    sort(v_w.begin(),v_w.end(),compare);
    cout<<"The weights of the items that are included are: ";
    for(int i=0;i<n;i++){
        w += v_w[i].second;
        if(w>=W){break;}
        cout<<v_w[i].second<<" ";
        v += v_w[i].first * v_w[i].second;
    }
    cout<<endl;
    cout<<"The maximum cost using greedy approach is: "<<v<<endl;
}

int main(){

    freopen("input.txt","r",stdin);

    // freopen("output_1.txt","w",stdout);
    freopen("output_2.txt","w",stdout);
    
    int t; cin >> t;
    while(t--){
        int n, max_weight; cin >> n >> max_weight;
        // vector<double> weights(n), values(n);
        vector<int> weights(n), values(n);
        for(int i=0; i<n; i++) cin >> weights[i];
        for(int i=0; i<n; i++) cin >> values[i];
        // greedy(n,max_weight,weights,values);
        int ans = knapsack(max_weight, weights, values);
        cout << ans << endl;
    }
}