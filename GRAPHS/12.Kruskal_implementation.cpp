#include<iostream>

using namespace std;

int find_min_vertex(int *distance, int *visited, int n)
{
    int min_vertex = -1;

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (min_vertex == -1 || distance[i] < distance[min_vertex]))
        {
            min_vertex = i;
        }
    }

    return min_vertex;
}


void dijkstra(int **edges, int n)
{
    int *visited = new int[n];
    int *distance = new int[n];

    for(int i=0;i< n;i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    for(int i=0;i<n;i++)
    {
        int min_vertex = find_min_vertex(distance, visited, n);
        
        visited[min_vertex] = 1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && edges[min_vertex][j] != 0)
            {
                int dist = distance[min_vertex] + edges[min_vertex][j];

                if(dist < distance[j])
                {
                    distance[j] = dist;
                }
            }   
        }
    }
}