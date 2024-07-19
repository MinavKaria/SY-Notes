#include<bits/stdc++.h>
using namespace std;

int kruskal(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back({graph[i][j], {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        while (parent[u] != u)
        {
            u = parent[u];
        }

        while (parent[v] != v)
        {
            v = parent[v];
        }

        if (u != v)
        {
            cost += w;
            parent[u] = v;
        }
    }

    return cost;
}





int main()
{
    
    return 0;
}