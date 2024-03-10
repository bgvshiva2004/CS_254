#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int> adj[],bool visited[],int disc[],int low[],int& disc_time,int parent,bool isAP[],vector<pair<int,int>>& bridges){
    visited[i] = true;
    disc[i] = low[i] = disc_time;
    disc_time++;
    int children = 0;
    for(auto j: adj[i]){
        if(!visited[j]){
            children++;
            dfs(j,adj,visited,disc,low,disc_time,i,isAP,bridges);
            low[i] = min(low[i],low[j]);
            if(parent != -1 && low[j]>=disc[i]){
                isAP[i] = true;
            }
            if(low[j] > disc[i]){
                bridges.push_back(make_pair(i,j));
            }

        }else if(j != parent){
            low[i] = min(low[i],disc[j]);
        }
    }
    if(parent == -1 && children > 1){
        isAP[i] = true;
    }
}

void AP_and_Bridge(vector<int> adj[],int n){
    int disc[n]={0},low[n];
    bool visited[n] = {false};
    bool isAP[n] = {false};
    vector<pair<int,int>> bridges;

    int disc_time = 0, parent = -1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,disc,low,disc_time,parent,isAP,bridges);
        }
    }

    cout<<"Articulation points: ";
    for(int i=0;i<n;i++){
        if(isAP[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    cout<<"Bridges: "<<endl;
    for(auto i:bridges){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){

    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n,e;
    cin>>n>>e; 

    // int n = 5;
    vector<int> adj[n+1];
    for(int i = 0; i < e; i++){
        int u,v; cin>>u>>v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    // addEdge(adj, 1, 0);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 2, 1);
    // addEdge(adj, 0, 3);
    // addEdge(adj, 3, 4);
    AP_and_Bridge(adj, n);
}