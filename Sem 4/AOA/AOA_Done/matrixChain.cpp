#include<bits/stdc++.h>
using namespace std;

int matrixChain(vector<int> p)
{
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                m[i][j] = min(m[i][j], q); 
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    
    vector<int> p = {5, 4, 6, 2, 7};
    int result = matrixChain(p);

    cout << "Minimum number of multiplications: " << result << endl;



    return 0;
}