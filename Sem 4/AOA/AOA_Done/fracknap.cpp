#include<bits/stdc++.h>
using namespace std;


vector<double> knap(vector<vector<int>> a, int target)
{
    vector<double> taken(a.size(),0);
    double cost=0;
    for(int i=0;i<a.size();i++)
    {
        cout<<target<<"\n";
        if(target>=a[i][0])
        {
            target=target-a[i][0];
            cost+=a[i][1];
            taken[i]=1;
        }
        else if(target==0)
        {
            break;
        }
        else if (target<=a[i][0])
        {
            taken[i]=(double)target/(a[i][0]);
            cost+=a[i][1]*taken[i];
            target=0;
        }
    }

    cout<<"The cost is "<<cost<<"\n";
    return taken;

}

bool sort_by_weight(vector<int> a,vector<int> b)
{
    return a[0]<b[0];
}

bool sort_by_value(vector<int> a,vector<int> b)
{
    return a[1]>b[1];
}

bool sort_by_pw(vector<int> a,vector<int> b)
{
    return (double)a[1]/a[0]>(double)b[1]/b[0];
}

int main()
{
    vector<vector<int>> pw;


    cout<<"Enter the number of Items";
    int num;
    cin>>num;

    for(int i=0;i<num;i++)
    {
        int a;
        int b;
        cout<<"Enter the weight and value of the "<<(i+1)<<" item\n";
        cin>>a;
        cin>>b;
        pw.push_back({a,b});
    }

    int target;
    cout<<"Enter the target";
    cin>>target;

    sort(pw.begin(),pw.end(),sort_by_pw);
    cout<<"By P/W\n";
    for(int i=0;i<num;i++)
    {
        cout<<pw[i][0]<<" "<<pw[i][1]<<"\n";
    }

    vector<double> taken=knap(pw,target);

    for(int i=0;i<num;i++)
    {
        cout<<taken[i]<<" ";
    }

    // cout<<"By Value\n";
    //  sort(pw.begin(),pw.end(),sort_by_value);

    // for(int i=0;i<num;i++)
    // {
    //     cout<<pw[i][0]<<" "<<pw[i][1]<<"\n";
    // }
    
    // cout<<"By P/W\n";
    //  sort(pw.begin(),pw.end(),sort_by_pw);

    // for(int i=0;i<num;i++)
    // {
    //     cout<<pw[i][0]<<" "<<pw[i][1]<<"\n";
    // }
    return 0;
}