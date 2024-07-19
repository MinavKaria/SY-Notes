#include<bits/stdc++.h>
using namespace std;

int knapSack(vector<int> val,vector<int> w,int target, int cost, int num, vector<int> &ind) 
{
    if(target == 0 || num == val.size())
    {
        for(int i:ind)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
        return cost;
    }
    
    if(w[num] > target)
    {
        return knapSack(val, w, target, cost, num+1, ind);
    }
    

    ind[num]=1;
    int a=knapSack(val, w, target-w[num], cost+val[num], num+1, ind);
    ind[num]=0;
    int b=knapSack(val, w, target, cost, num+1, ind);

    return max(a,b);

}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> w = {10, 20, 30};
    int W = 50;
    vector<int> ind(val.size(),0);
   
    int result = knapSack(val,w,W,0,0,ind);
    cout << "Maximum value: " << result << endl;

    return 0;
}