#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool iscyclic_helper(vector<int> adj[],int v,bool visited[],int parent)
    {
        visited[v] = 1;
        vector<int>::iterator it; 
        for(it= adj[v].begin();it != adj[v].end();it++)
        {
            // if(!visited[*it] && iscyclic_helper(adj,*it,visited,v))
            // return true;
            if (!visited[*it]) 
            { 
                if (iscyclic_helper(adj,*it, visited, v)) 
                    return true; 
            } 
            else if(*it != parent)
            return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	   // map<int,bool> visited;
	   bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
     
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        if(iscyclic_helper(adj,i,visited,-1))
        return true;
    }
    return false;
	}
};