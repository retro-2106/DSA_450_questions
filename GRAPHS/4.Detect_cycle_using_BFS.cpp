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

	bool iscyclic()
	{
		//firstly we will increase in degree
		map<T,int> in_degree;
		for(auto a : g)
		{
		    in_degree[a.first] = 0;
		}
        //vector<pair<T,int>> in_degree(g.size(),0);
		for(auto a : g)
		{
			for(auto v : a.second)
			{
			    //cout<<v.first<<" ";
				in_degree[v.first]++;
				//cout<<v.first<<" "<<in_degree[v.first]<<endl;
			}
		}

		queue<T> q;
		for(auto it=in_degree.begin();it != in_degree.end();it++)
		{
			if(it->second == 0)
			{
				q.push(it->first);
			}
		}

		int count=0;

		while(!q.empty())
		{
			T u = q.front();
			q.pop();

			for(auto a: g[u])
			{
				if(--in_degree[a.first] == 0)
				{
					q.push(a.first);
				}
			}
			count++;
		}
//cout<<count<<endl;
		if(count != g.size())
			return true;
		else
			return false;
	}

};


int main()
{
	Graph<char> graph;

	graph.addedge('a','b',1,0);
	graph.addedge('b','c',1,0);
	graph.addedge('d','c',1,0);
	graph.addedge('a','d',1,0);
//	graph.addedge('4','5',1,0);
//	graph.addedge('b','e',1,0);
//	graph.addedge('d','e',1,0);
// 	graph.print_graph();
    
    cout<<graph.iscyclic();
}