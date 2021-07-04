#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void dfs(vector<vector<int>> &adj,int i,vector<bool> &visited)
    {
        if(visited[i])
            return;
        visited[i] = true;
        for(auto a : adj[i])
        {
            if(!visited[a])
                dfs(adj,a,visited);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(n > connections.size() + 1)
            return -1;
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        
        int count=0;
        
        for(auto conn:connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj,i,visited);
            }
        }
        
        return count-1;
    }
};
