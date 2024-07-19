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

    int i=0;
    int j=0;
    int k=low;

    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}   

void mergeSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    vector<int> arr={10,2,5,1,8};

    mergeSort(arr,0,arr.size()-1);

    for(int i:arr)
    {
        cout<<i<<" ";
    }

}