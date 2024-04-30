#include<bits/stdc++.h>
using namespace std;


void dijsktra(vector<vector<int>> adj,int src)
{
    int n=adj.size();
    vector<bool> visited(n,false);
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    for(int i=0;i<n;i++)
    {
        int minDist=INT_MAX;
        int minIndex=-1;
           //Find the minimum among all from where to find the shortest path 
        for(int v=0;v<n;v++)
        {
            if(!visited[v] && minDist>=dist[v])
            {
                minDist=dist[v];
                minIndex=v;
            }
        }

        visited[minIndex]=true;
        //update it if possible 
        for(int v=0;v<n;v++)
        {
            if(!visited[v] && adj[minIndex][v] && dist[minIndex]!=INT_MAX && dist[minIndex]+adj[minIndex][v]<dist[v] )
            {
                dist[v]=dist[minIndex]+adj[minIndex][v];
            }
        }
        cout<<"Iteration no: "<<i<<"\n";
        for(int j:dist)
        {
            if(j!=INT_MAX)
            cout<<j<<"\n";
            else
            cout<<"INF"<<"\n";
        }

    }
}


int main()
{
    // cout<<"Enter the number of nodes";
    int n;
    // cin>>n;
    n = 6;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    adj[0][1] = 50;
    adj[0][2] = 45;
    adj[0][3] = 10;
    adj[1][2] = 10;
    adj[1][3] = 15;
    adj[2][4] = 30;
    adj[3][0] = 10;
    adj[3][4] = 15;
    adj[4][1] = 20;
    adj[4][2] = 35;
    adj[5][4] = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    int src = 0;
    dijsktra(adj, src);
    return 0;
}