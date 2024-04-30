#include<bits/stdc++.h>
using namespace std;

bool findIt(vector<int> a, int num)
{
    int low=0;
    int high=a.size();

    while(low<=high)
    {
      
        int mid=(low+high)/2;
        //   cout<<mid;

        if(a[mid]<num)
        {
          low=mid+1;
        }
        else if(a[mid]>num)
        {
            high=mid-1;
        }
        else if(a[mid]==num)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> a={1,4,5,6,8};

    int num;
    cin>>num;

    if(findIt(a,num))
    {
        cout<<"Found ";
    }
    else
    {
        cout<<"Not Found";
    }
}