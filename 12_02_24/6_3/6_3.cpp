#include <bits/stdc++.h>
using namespace std;
 

void dfs(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, stack<int> &stk, vector<bool> &stackMember){
    static int timer = 0; 
    disc[u] = low[u] = ++timer;
    stk.push(u); 
    stackMember[u] = true; 
    for(int v : adj[u]){
        if(disc[v] == 0) 
        {
            dfs(v,adj,disc,low,stk,stackMember); 
            low[u] = min(low[u],low[v]);  
        }
        else if(stackMember[v]) 
        {
            low[u] = min(low[u],disc[v]); 
        }
    }
    if(low[u] == disc[u]){
        while(stk.top() != u){
            cout<<stk.top()<<" "; 
            stackMember[stk.top()] = false; 
            stk.pop(); 
        }
        cout<<stk.top()<<" "; 
        stackMember[stk.top()] = false; 
        stk.pop(); 
        cout<<"\n"; 
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 

    int v,e; cin>>v>>e;
    vector<vector<int>> adj(v+1); 
    vector<int> disc(v+1), low(v+1); 
    vector<bool> stackMember(v+1); 
    stack<int> stk; 
    for(int i = 0; i < e; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v); 
    }
    for(int i = 1; i <= v; i++){
        if(disc[i] == 0){
            dfs(i,adj,disc,low,stk,stackMember); 
        }
    }
}