#include<bits/stdc++.h>

using namespace std;

// template<typename T>
template<typename T>
class Graph
{
public:
	//map structure
	//source destination weight
	map<T,list<pair<T,int> >> g;
	
	void addedge(T u, T v,int dist,bool bidir=1)
	{
		g[u].push_back(make_pair(v,dist));

		if(bidir)
		{
			g[v].push_back(make_pair(u,dist));
		}
	}

	void print_graph()
	{
		
		for(auto a : g)
		{
			cout<<"Source: "<<a.first<<"\t";
			for(auto b : a.second)
			{
				cout<<"("<<b.first<<","<<b.second<<") ";
			}
			cout<<endl;
		}
	}

	bool iscyclic_helper(T u,map<T,bool> &visited,map<T,bool> &recStack)
	{
		if(visited[u] == 0)
		{
			visited[u] = 1;
			recStack[u] = 1;
		}

		for(auto a : g[u])
		{
			if(!visited[a.first] && iscyclic_helper(a.first,visited,recStack))
				return true;
			else if(recStack[a.first])
				return true;
		}

		recStack[u] = 0;
		return false;
	}

	bool iscyclic()
	{
		map<T,bool> visited;
		map<T,bool> recStack;

		for(auto it : g)
		{
			if(iscyclic_helper(it.first,visited,recStack))
				return true;
		}

		return false;
	}

};


int main()
{
	Graph<char> graph;

	graph.addedge('a','b',1,0);
	graph.addedge('a','d',1,0);
	graph.addedge('a','c',1,0);
	graph.addedge('b','d',1,0);
	graph.addedge('c','d',1,0);
	graph.addedge('b','e',1,0);
	graph.addedge('d','e',1,0);
// 	graph.print_graph();
    
    cout<<graph.iscyclic();
}