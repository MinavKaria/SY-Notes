#include<bits/stdc++.h>
using namespace std;


int partition(vector<int>&a,int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(i<a.size() && a[i]<=pivot)
        {
            i++;
        }

        while(j>=0 && a[j]>pivot)
        {
            j--;
        }


        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }

    swap(a[j],a[low]);
    return j;

}


void quickSort(vector<int> &a,int low, int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}



int main()
{
    vector<int> a={10,8,4,5,2};

    quickSort(a,0,a.size()-1);
    

    for(int i:a)
    {
        cout<<i<<" ";
    }
}