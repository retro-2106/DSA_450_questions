#include<bits/stdc++.h>

using namespace std;


int find_min_vertex(int weights[],int visited[],int n)
{
    int min_vertex = -1;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (min_vertex == -1 || weights[i] < weights[min_vertex]))
        {
            min_vertex = i;
        }
    }
    return min_vertex;
}

void prims(int **edges, int n)
{
    int *parent = new int[n];
    int *visited = new int[n];
    int *weights = new int[n];

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
        weights[i] = INT_MAX;
    }

    parent[0] = -1;
    weights[0] = 0;

    for(int i=0;i<n;i++)
    {
        int min_index = find_min_vertex(weights, visited, n);

        visited[min_index] = 1;

        //now  we will traverse the neighbours of the min vertex
        for(int j=0;j<n;j++)
        {
            if(edges[min_index][j] != 0 && !visited[j])
            {
                if(edges[min_index][j] < weights[j])
                {
                    weights[j] = edges[min_index][j];
                    parent[j] = min_index;
                }
            }
        }
    }
}