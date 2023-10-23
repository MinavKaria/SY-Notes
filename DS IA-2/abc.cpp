 // 8 
// 128
// 2048
// 1 5 7 8 9 12 7 8 14 15 16 21 23 2 4 3 37 24 32 40

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int page_size;
    int cache;
    int mainm;
    
    cout<<"Enter the Page Size \n";
    cin>>page_size;
    
    cout<<"Enter the cache memory size \n";
    cin>>cache;
    
    cout<<"Enter the Main memory size \n";
    cin>>mainm;
    cout<<endl;
    
    
    int cache_pages=cache/page_size;
    int main_pages=mainm/page_size;
    
    vector<int>  main_memory;
    int temp;
    
    
    cout<<"Enter the pages wanted for "<<main_pages<< " enter -1 to stop";
    
    while(temp!=-1)
    {
        cin>>temp;
        if(temp==-1)
        {
            break;
        }
        
        if(temp>main_pages)
        {
             cout<<"Exceed the memory Try Again";
        }
        else
        {
            main_memory.push_back(temp);
        }
        
    }
    
    cout<<"The input"<<endl;
    for(int i=0;i<main_memory.size();i++)
    {
        cout<<main_memory[i]<<" ";
    }
    cout<<"\n";
    
    int n=cache_pages;
    vector<int> cache_memory(cache_pages,-1);
    int temp2;
    
    
    for(int i=0;i<main_memory.size();i++)
    {
        cache_memory[(i)%cache_pages]=main_memory[i];
        for(int j=0;j<n;j++)
        {
            if (cache_memory[j] != -1)
            {
                cout << setw(2) << cache_memory[j] << " ";
            }
            else
            {
                cout << "- ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
