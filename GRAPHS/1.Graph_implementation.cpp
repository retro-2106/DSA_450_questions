#include<bits/stdc++.h>

using namespace std;

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
	graph.print_graph();
}