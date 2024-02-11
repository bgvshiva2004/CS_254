#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<bool>> &adj, vector<int> &color, bool & bipartite){
    for(int i = 0; i < adj.size(); i++){
        if(adj[v][i]){
            if(color[i] == 0){
                color[i] = -color[v]; 
                dfs(i,adj,color,bipartite); 
            }
            else if(color[i] == color[v]){
                bipartite = false; 
                return; 
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 

    int v; cin>>v; 
    vector<vector<bool>> adj(v,vector<bool>(v)); 
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            char ch; cin>>ch; 
            adj[i][j] = (ch == '0'); 
        }
    }
    for(int i = 0; i < v; i++){
        adj[i][i] = 0; 
    }
    bool bipartite = true; 
    vector<int> color(v,0);
    for(int i = 0; i < v; i++){
        if(color[i] == 0)
        {
            color[i] = 1; 
            dfs(i,adj,color,bipartite); 
        }
    }  
    if(bipartite){
        cout<<"YES !! It can be divided into two cliques\n"; 
    }
    else{
        cout<<"NO !! It cannot be divided into two cliques\n"; 
    }
}