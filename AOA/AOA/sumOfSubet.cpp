#include <iostream>
#include <vector>

using namespace std;

bool flag = false;

void printSubsetSum(int i, int n, int set[], int targetSum, vector<int> &subset)
{
    if (targetSum == 0)
    {
        flag = true;
        cout << "[ ";
        for (int j = 0; j < subset.size(); j++)
        {
            cout << subset[j] << " ";
        }
        cout << "]";
        return;
    }

    if (i == n)
    {
        return;
    }

    printSubsetSum(i + 1, n, set, targetSum, subset);

    if (set[i] <= targetSum)
    {
        subset.push_back(set[i]);
        printSubsetSum(i + 1, n, set, targetSum - set[i], subset);
        subset.pop_back();
    }
}

int main()
{
    int set1[] = {1, 2, 1};
    int sum1 = 3;
    int n1 = sizeof(set1) / sizeof(set1[0]);
    vector<int> subset1;
    cout << "Output 1:" << endl;
    printSubsetSum(0, n1, set1, sum1, subset1);
    cout << endl;
    flag = false;

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    vector<int> subset2;
    cout << "Output 2:" << endl;
    printSubsetSum(0, n2, set2, sum2, subset2);
    if (!flag)
    {
        cout << "There is no such subset" << endl;
    }

    return 0;
}
