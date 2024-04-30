#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] != INT_MAX)
                cout << dist[i][j] << " ";
            else
                cout << "INF ";
        }
        cout<<endl;
    }
}

int main()
{

    int n;
    n = 3;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][0] = 0;
    graph[0][1] = 4;
    graph[0][2] = 11;
    graph[1][0] = 6;
    graph[1][1] = 0;
    graph[1][2] = 2;
    graph[2][0] = 3;
    graph[2][1] = INT_MAX;
    graph[2][2] = 0;

    floydWarshall(graph);

    return 0;
}