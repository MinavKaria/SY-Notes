#include<bits/stdc++.h>
using namespace std;

bool sumOfSubset(vector<int> a,int target, int index)
{   

    cout<<target<<"\n";

    if(target==0)
    {
        return true;
    }

    if(target<0 ||index>a.size()-1 )
    {
        return false;
    }

    else
    {
        return sumOfSubset(a,target-a[index],index+1) || sumOfSubset(a,target,index+1);
    }
}

int main()
{
    vector<int> a={1,3,5,8,9};
    int target;

    cin>>target;
    
    if(sumOfSubset(a,target,0))
    {
        cout<<"Possible";
    }
    else
    {
        cout<<"Not Possible";
    }
    return 0;
}