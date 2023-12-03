// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <iomanip>

//1 5 7 8 9 12 7 8 14 15 16 21 23 2 4 3 37 24 32 40 -1

using namespace std;


int print(vector<vector<int>> & set_cache,int cache_lines,int num, int set_lines,int m)
{
    int n=cache_lines/2;
    cout<<"\nSet Cache"<<endl;
    bool inserted=false;
    int cnter=0;
    if(set_cache[set_lines][0]==-1)
    {
        inserted=true;
        set_cache[set_lines][0]=num;
    }
    else if(set_cache[set_lines][1]==-1 && inserted==false)
    {
        set_cache[set_lines][1]=num;
        cnter=1;
    }
    else
    {
        if(set_cache[set_lines][1]!=-1 && set_cache[set_lines][0]!=-1 && m==1)
        {
            set_cache[set_lines][0]=num;
            cnter=0;
        }
        else
        {
            set_cache[set_lines][1]=num;
           cnter=1;
        }
    }
    
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(set_cache[i][j]==-1)
            {
                cout<<"- ";
            }
            else
            {
                cout<<set_cache[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    
    return cnter;
}


void onlyprint(vector<vector<int>> & set_cache,int cache_lines)
{
     int n=cache_lines/2;
    cout<<"\nSet Cache Hit"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(set_cache[i][j]==-1)
            {
                cout<<"- ";
            }
            else
            {
                cout<<set_cache[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}


int main() 
{
    // Write C++ code here
    int page_size;
    int cache_size;
    int main_memory_size;

    cout << "Enter the Page Size: ";
    cin >> page_size;

    cout << "Enter the cache memory size: ";
    cin >> cache_size;

    cout << "Enter the Main memory size: ";
    cin >> main_memory_size;
    cout << endl;

    int cache_lines = cache_size / page_size;
    int main_pages = main_memory_size / page_size;
    
    vector<int> main_memory;
    
    
    int temp;
    int page_count=0;
    
    cout<<"Enter the number to be Entered";
    while (page_count < main_pages) 
    {
        cin >> temp;
        if (temp == -1) 
        {
            break;
        }

        if (temp >= main_pages) 
        {
            cout << "Exceeded the memory. Try Again." << endl;
        } 
        else 
        {
            main_memory.push_back(temp);
        }
    }
    
    cout<<"Page References in Main Memory\n";
    
    for(int i=0;i<main_memory.size();i++)
    {
        cout<<main_memory[i]<<" ";
    }
    cout<<endl;
    
    vector<vector<int>> set_cache(cache_lines/2, vector<int> (2,-1));
    
    int set_line;
    int m=0;
    
    for(int i=0;i<main_memory.size();i++)
    {
        int set_line = main_memory[i] % (cache_lines / 2);

        if (set_line == 0)
        {
            set_line = 7;
        }
        else
        {
            set_line = set_line - 1;
        }

        
            bool found = false;
            for (auto it = set_cache[set_line].begin(); it != set_cache[set_line].end(); ++it) 
            {
                if (*it == main_memory[i]) 
                {
                    found = true;
                    break;
                }
            }               

            
            if (found) 
            {
                onlyprint(set_cache,cache_lines);
                continue;
            } 
            else 
            {
                m=print(set_cache,cache_lines,main_memory[i],set_line,m);
            }

        

    }

    return 0;
}