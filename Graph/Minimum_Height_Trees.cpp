#include<bits/stdc++.h>
using namespace std;

class Solution {

    public :
    
};
void dfs(vector<vector<int>>&edges,int vertex){
    for(vector<int>&v : edges){
        
    }
}
int main(){
    int n;cin>>n;
    vector<vector<int>> edges(n-1,vector<int>(2));

    for(int i = 0; i< n -1;i++){
        for(int j= 0; j < 2;j++ ){
            cin>>edges[i][j];
        }
    }
    
    // for(int i = 0; i< n -1;i++){
    //     for(int j= 0; j < 2;j++ ){
    //         cout<<edges[i][j]<<" ";
    //     }cout<<endl;
    // }

    vector<unordered_set<int>> adj(n);
    vector<int>adjList[n];

    for(auto &v : edges){
        adj[v[0]].insert(v[1]);
        adj[v[1]].insert(v[0]);
    }
    int i  = 0;
   for(auto &s : adj){
       cout<< i<<" : ";i++;
       for(int x : s){
           cout<<x<<" ";
       }cout<<endl;
   }
    // for(auto &v : edges){
    //     adjList[v[0]].push_back(v[1]);
    //     adjList[v[1]].push_back(v[0]);
    // }
    //  for(int i = 0; i<n;i++){cout<< i<<" : ";
    //      for(int j = 0; j < adjList[i].size();j++){
    //          cout<<adjList[i][j]<<" ";
    //      }cout<<endl;
    //  }

    queue<int>Q;
    for(int i = 0; i<  adj.size();i++){
        if(adj[i].size() == 1)Q.push(i);
        
    }
    while(n > 2){
        int len = Q.size();
        n = n -len;
        for(int i = 0; i < len; i++){
            int node = Q.front();
            cout<<node<<" ";
            Q.pop();
            for(auto& a : adj[node]){
                adj[a] .erase(node);
                if(adj[a].size() == 1)Q.push(a);
            }
        }cout<<endl;
    }cout<<endl;
    vector<int>result;
    while(!Q.empty()){
        result.push_back(Q.front());
        Q.pop();
    }
    for(auto i : result)cout<<i<<" ";
    return 0;
}