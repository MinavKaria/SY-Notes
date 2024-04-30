#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i=0;i<n1;i++)
    {
        left[i]=a[i+low];
    }

    for(int i=0;i<n2;i++)
    {
        right[i]=a[i+mid+1];
    }

    int l=0;
    int m=0;
    int n=low;

    while(l<n1 && m<n2)
    {
        if(left[l]<right[m])
        {
            a[n]=left[l];
            n++;
            l++;
        }
        else
        {
            a[n]=right[m];
            m++;
            n++;
        }
    }

    while(l<n1)
    {
        a[n]=left[l];
        n++;
        l++;
    }

    while(m<n2)
    {
        a[n]=right[m];
        n++;
        m++;
    }


}


void mergeSort(vector<int> &a,int low,int high)
{
    if(low<high)
    {  
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    vector<int> a={5,3,4,1,2};

    mergeSort(a,0,a.size()-1);

    for(int i:a)
    {
        cout<<i<<" ";
    }

    return 0;
}