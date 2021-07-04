#include<bits/stdc++.h>

using namespace std;

class Graph{
    public:
    list<int> *graph;
    int V;
    Graph(int v)
    {
        V = v;
        graph = new list<int>[V];
        
    }
    
    void add_edge(int u, int v)
    {
        graph[u].push_back(v);
    }
    
    void topological_helper(int i, bool *visited, stack<int> &stk)
    {
        visited[i] = true;
        for(auto it = graph[i].begin(); it != graph[i].end();it++)
        {
            if(!visited[*it])
            {
                topological_helper(*it, visited, stk);
            }
        }
        
        stk.push(i);
    }

    string topological(Graph g)
    {
        bool *visited = new bool[V];
        for(int i=0;i  < V;i++)
        {
            visited[i] = false;
        }
        
        stack<int> stk;
        
        for(int i=0;i< V;i++)
        {
            if(visited[i] == false)
            {
                topological_helper(i, visited, stk);
            }
        }
        string ans = "";
        while(!stk.empty())
        {
            ans += 'a' + stk.top();
            stk.pop();
        }
        return ans;
    }
};

class Solution{
    public:
    string findOrder(string dict[], int N, int K)
    {
        Graph g(K);
        for(int i=0;i<N-1;i++)
        {
            string word1 = dict[i];
            string word2 = dict[i+1];
            
            for(int j=0;j < min(word1.length(), word2.length()); j++)
            {
                if(word1[j] != word2[j])
                {
                    g.add_edge(word1[j] - 'a', word2[j] - 'a');
                    break;
                }
            }
        }
        
        return g.topological(K);
    }
};