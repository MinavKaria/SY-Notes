#include<bits/stdc++.h> 
using namespace std;

int matrixChainMulti(vector<int> p)
{
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int i = 1; i < n - 1; i++)
    {
        dp[i][i + 1] = p[i - 1] * p[i] * p[i + 1];
    }



    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for (int l = 1; l < n - 1; l++)
    {
        for (int i = 1; i < n - l; i++)
        {
            int j = i + l;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
                if(dp[i][j] == dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j])
                {
                    s[i][j] = k;
                }
            }
        }
    }



    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }


    

    //give the parenthesis of the matrix chai
    return dp[1][n - 1];
}

int main()
{
    vector<int> p = {2,1,3,4,5};
    
    cout << "Matrix dimensions: ";
    for (int i = 0; i < p.size() - 1; i++)
    {
        cout << p[i] << "x" << p[i + 1] << " ";
    }
    cout<<endl;
    cout << "Minimum number of multiplications: " << matrixChainMulti(p) << endl;

    return 0;
}