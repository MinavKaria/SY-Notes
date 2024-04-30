#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Give in two strings to find lcs of\n";
    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    vector<vector<int>> v(m + 1, vector<int>(n+1));

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i-1] == b[j-1])
            {
                v[i][j] = v[i-1][j-1]+1;
            }
            else
            {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }

    int i = m, j = n;

    string lcs = "";

    while(i >= 0 && j >= 0)
    {
        if(a[i] == b[j])
        {
            lcs = a[i] + lcs;
            i--;
            j--;
        }
        else if(v[i-1][j] < v[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "Length of LCS is: " << v[m][n] << "\n";
    cout << "LCS is " << lcs << "\n";
}
