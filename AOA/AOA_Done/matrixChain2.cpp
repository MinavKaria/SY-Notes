#include<bits/stdc++.h>
using namespace std;

int matrixChain(vector<int> a)
{
    int n=a.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
                dp[i][j]=min(dp[i][j],q);
            }
        
        }
    }
}

int main()
{
    
    vector<int> p = {5, 4, 6, 2, 7};
    int result = matrixChain(p);

    cout << "Minimum number of multiplications: " << result << endl;



    return 0;
}