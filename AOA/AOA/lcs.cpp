#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void lcsAlgo(const string& S1, const string& S2) {
    int m = S1.length();
    int n = S2.length();

    vector<vector<int>> LCS_table(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (S1[i - 1] == S2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
        }
    }

    int index = LCS_table[m][n];

    string lcsAlgo(index, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (S1[i - 1] == S2[j - 1]) {
            lcsAlgo[--index] = S1[i - 1];
            i--;
            j--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "S1 : " << S1 << "\nS2 : " << S2 << "\n";
    cout << "LCS: " << lcsAlgo << "\n";
    cout << "Length of LCS: " << lcsAlgo.length() << "\n";
}

int main() {
    string S1, S2;

    cout << "Enter first string: ";
    cin >> S1;
    cout << "Enter second string: ";
    cin >> S2;

    lcsAlgo(S1, S2);

    return 0;
}
