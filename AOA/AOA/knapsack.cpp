#include <bits/stdc++.h>

using namespace std;

bool compareItems(const vector<int> &item1, const vector<int> &item2)
{
    double valuePerWeight1 = (double)item1[1] / (double)item1[0];
    double valuePerWeight2 = (double)item2[1] / (double)item2[0];
    return valuePerWeight1 > valuePerWeight2;
}

double fractionalKnapsack(int capacity, vector<vector<int>> &items,vector<double>& knap)
{
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    for (auto &item : items)
    {
        int weight = item[0];
        int value = item[1];
        double index=item[2];

        if (capacity >= weight)
        {
            totalValue += value;
            capacity -= weight;
            knap[index]=1;
        }
        else
        {
            totalValue += (double)capacity / (double)weight * value;
            knap[index]=(double)capacity / (double)weight;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int numItems;
    numItems=7;
    cout<<"The number of items are: "<<numItems<<endl;

    int profit[] = {5, 10, 15, 7, 8, 9, 4};
    int weight[] = {1, 3, 5, 4, 1, 3, 2};

    cout<<"The profits and weights of the items are: \n";
    for(int i=0;i<numItems;i++)
    {
        cout<<profit[i]<<" "<<weight[i]<<endl;
    }

    vector<vector<int>> items;
    for (int i = 0; i < numItems; ++i) 
    {
        items.push_back({weight[i],profit[i],i});
    }
    
    

    vector<double> knap(numItems,0.0);
    double maxValue = fractionalKnapsack(capacity, items,knap);
    cout << "The maximum value that can be obtained is: " << maxValue << endl;
    cout<<"The items selected are: ";
    for(int i=0;i<numItems;i++)
    {
        cout<<knap[i]<<" ";
    }


    return 0;
}
