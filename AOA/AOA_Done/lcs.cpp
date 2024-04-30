#include<bits/stdc++.h>
using namespace std;

string lcsA(string s1, string s2, int n, int m)
{
    if(n==s1.size() || m==s2.size())
    {
        return "";
    }

    else if(s1[n]==s2[m])
    {   
        return s1[n]+lcsA(s1,s2,n+1,m+1);
    }
    
    else
    {
        string lcs1=lcsA(s1,s2,n+1,m);
        string lcs2  =lcsA(s1,s2,n,m+1);
        return lcs1.size()>lcs2.size() ? lcs1 : lcs2;
    }
    
}

int lcs(string s1, string s2, int n, int m)
{
    if(n==s1.size() || m==s2.size())
    {
        return 0;
    }

    else if(s1[n]==s2[m])
    {   

        return 1+lcs(s1,s2,n+1,m+1);
    }
    
    else
    {
        return max(lcs(s1,s2,n+1,m),lcs(s1,s2,n,m+1));
    }
    
   
}

int main()
{
    string s1 = "Minav1";
    string s2 = "Minav2";
    cout << "Length of LCS: " << lcs(s1, s2, 0,0) << endl;
    return 0;
}