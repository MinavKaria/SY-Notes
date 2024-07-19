#include <bits/stdc++.h>
using namespace std;

void minMax(vector<int> a, vector<int> &num, int low, int high)
{
    if (low == high)
    {
        num[1] = max(num[1], a[low]);
        num[0] = min(num[0], a[low]);
    }
    else if (high - low == 1)
    {
        
        num[1] = max(num[1], a[low]);
        num[0] = min(num[0], a[low]);
        num[1] = max(num[1], a[high]);
        num[0] = min(num[0], a[high]);
    }
    if (low < high)
    {

        int mid = (low + high) / 2;
        minMax(a, num, 0, mid);
        minMax(a, num, mid + 1, high);
    }

}

int main()
{
    vector<int> a = {1, 2, 3,10, 4, 5,254,7,-2};
    vector<int> num = {INT_MAX, INT_MIN};
    minMax(a,num, 0, a.size() - 1);

    cout << num[0] << " " << num[1] << endl;
    return 0;
}