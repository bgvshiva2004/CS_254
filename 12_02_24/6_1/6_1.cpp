#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSorting(vector<vector<int>>& adj,int n){
    queue<int> q;
    vector<int> result;
    vector<int> indegree(n+1,0);

    for(int i=1;i<=n;i++){
        for(auto j: adj[i]){
            indegree[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        result.push_back(x);
        for(auto i: adj[x]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return result;
}   

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,e;
    cin>>n>>e;

    // cout<<n<<" "<<e;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < e; i++){
        int u1, u2;
        cin >> u1 >> u2;
        adj[u1].push_back(u2);
    }
    
    vector<int> result = topologicalSorting(adj,n);
    for(auto i:result){
        cout<<i<<" ";
    }

}