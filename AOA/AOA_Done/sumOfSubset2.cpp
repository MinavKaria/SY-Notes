#include <iostream>
#include <vector>
using namespace std;

void subset_sum(vector<int>& arr, int target, int index, int current_sum, vector<int>& subset, vector<int>& ind) {
    if (current_sum == target) {
        cout << "Subset: ";
        for (int i = 0; i < subset.size(); ++i) {
            if (subset[i] != 0) {
                cout << subset[i] << " ";
            }
        }
        cout << endl;
        cout << "Index: ";
        for (int i = 0; i < ind.size(); ++i) {
            cout << ind[i] << " ";
        }
        cout << endl;
        return;
    }

    if (index == arr.size()) {
        return;
    }

    ind[index] = 1;
    subset_sum(arr, target, index + 1, current_sum + arr[index], subset, ind);
    ind[index] = 0;
    subset_sum(arr, target, index + 1, current_sum, subset, ind);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int list_size = arr.size();
    vector<int> my_list(list_size, 0);

    int target = 3;
    vector<int> subset;

    subset_sum(arr, target, 0, 0, subset, my_list);

    return 0;
}
