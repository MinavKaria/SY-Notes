#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int begin, int mid, int end)
{
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = a[begin + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = begin;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &array, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    vector<int> a = {4, 5, 3, 1, 2};
    mergeSort(a, 0, a.size() - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}