#include<bits/stdc++.h>
using namespace std;

int graphColoring(vector<vector<int>> graph, int m)
{
    int n = graph.size();
    vector<int> color(n, 0);

    for (int i = 0; i < n; i++)
    {
        set<int> availableColors;
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                if (color[j] != 0)
                {
                    availableColors.insert(color[j]);
                }
            }
        }

        int c = 1;
        for (auto it = availableColors.begin(); it != availableColors.end(); it++)
        {
            if (*it != c)
            {
                break;
            }
            c++;
        }

        color[i] = c;
    }

    int maxColor = 0;
    for (int i = 0; i < n; i++)
    {
        maxColor = max(maxColor, color[i]);
    }

    return maxColor;
}

int main()
{
    
    return 0;
}