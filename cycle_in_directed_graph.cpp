#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&stack){
    visited[node]=true;
    stack[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour])
        {
            if(dfs(neighbour,adj,visited,stack))
            return true;
        }
        else if(stack[neighbour])
        return true;
    }
    stack[node]=false;
    return false;
}
bool cycle_detect(int v,vector<int>adj[]){
    vector<int>visited(v,0);
    vector<int>stack(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,stack))
            return true;
        }
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        int V,e;
        cin>>V>>e;
        vector<int>adj[V];
        for(int i=0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        cout<<cycle_detect(V,adj)<<" ";
    }
    return 0;
}
