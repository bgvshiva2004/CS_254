#include<bits/stdc++.h>
using namespace std;

// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
// }

void dfs(int i,vector<vector<int>>& adj,int dp[],bool visit[]){
    visit[i]=true;
    for(auto j:adj[i]){
        if(!visit[j]){
            dfs(j,adj,dp,visit);
        }
        dp[i] = max(dp[i],1+dp[j]);
    }

}

int longestPath(vector<vector<int>>& adj,int n){
    int ans = INT_MIN;
    int dp[n+1];
    memset(dp,0,sizeof dp);

    bool visit[n+1];
    memset(visit,false,sizeof visit);

    for(int i=1;i<=n;i++){
        if(!visit[i]){
            dfs(i,adj,dp,visit);
        }
    }

    for(int i=1;i<=n;i++){
        ans = max(ans,dp[i]);
    }

    return ans;
    
}

int main(){

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    int n,e; cin>>n>>e; 
    vector<vector<int>> adj(n+1); 
    for(int i = 0; i < e; i++){
        int u,v; cin>>u>>v; 
        adj[u].push_back(v); 
    }

    // int n = 5;
    // vector<int> adj[n + 1];
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 3, 2);
    // addEdge(adj, 2, 4);
    // addEdge(adj, 3, 4);

    int l = longestPath(adj,n);
    cout<<l<<endl;
}