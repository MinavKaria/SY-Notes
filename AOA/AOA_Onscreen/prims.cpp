#include<bits/stdc++.h>
using namespace std;

int prims(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minKey = INT_MAX, minIndex = -1;
        for (int j = 0; j < n; j++)
        {
            if (!mstSet[j] && key[j] < minKey)
            {
                minKey = key[j];
                minIndex = j;
            }
        }

        mstSet[minIndex] = true;

        for (int j = 0; j < n; j++)
        {
            if (graph[minIndex][j] && !mstSet[j] && graph[minIndex][j] < key[j])
            {
                parent[j] = minIndex;
                key[j] = graph[minIndex][j];
            }
        }
    }

    int cost = 0;
    for (int i = 1; i < n; i++)
    {
        cost += graph[i][parent[i]];
    }

    return cost;
}

int main()
{
    
    return 0;
}