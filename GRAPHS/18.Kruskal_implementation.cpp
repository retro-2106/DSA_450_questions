#include<bits/stdc++.h>

using namespace std;


class Edges{
    public:
    int src;
    int dest;
    int weight;
};

bool compare(Edges a, Edges b)
{
    return a.weight < b.weight;
}

int find_parent(int v, int parent[])
{
    if(parent[v] == v)
    return v;

    return find_parent(parent[v], parent);
}

void kruskals(Edges *input, int n,int E)
{
    sort(input, input + E, compare);
    
    Edges *output = new Edges[n-1];

    int count = 0;
    int i= 0;

    int *parent = new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    while(count != n-1)
    {
        Edges current_edge = input[0];

        int src_parent = find_parent(current_edge.src, parent);
        int des_parent = find_parent(current_edge.dest, parent);

        if(src_parent != des_parent)
        {
            output[count++] = current_edge;
            parent[src_parent] = des_parent;
        }
        i++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }
    
}