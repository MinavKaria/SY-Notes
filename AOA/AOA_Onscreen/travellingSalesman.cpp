#include<bits/stdc++.h>
using namespace std;

int travellingSalesman(vector<vector<int>> graph)
{
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX));

    dp[0][1] = 0;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                for (int j = 0; j < n; j++)
                {
                    if (mask & (1 << j) && i != j)
                    {
                        dp[i][mask] = min(dp[i][mask], dp[j][mask ^ (1 << i)] + graph[j][i]);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        ans = min(ans, dp[i][(1 << n) - 1] + graph[i][0]);
    }

    return ans;
}

int main()
{


    int n;
    n = 4;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][0] = 0;
    graph[0][1] = 10;
    graph[0][2] = 15;
    graph[0][3] = 20;
    graph[1][0] = 5;
    graph[1][1] = 0;
    graph[1][2] = 9;
    graph[1][3] = 10;
    graph[2][0] = 6;
    graph[2][1] = 13;
    graph[2][2] = 0;
    graph[2][3] = 12;
    graph[3][0] = 8;
    graph[3][1] = 8;
    graph[3][2] = 9;
    graph[3][3] = 0;

    cout << "Minimum cost to visit all cities: " << travellingSalesman(graph) << endl;   

    return 0;
}
