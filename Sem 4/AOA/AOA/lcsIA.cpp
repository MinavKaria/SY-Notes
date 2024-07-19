#include <iostream>
#include <string>
#include <queue>
using namespace std;

string longestCommonSubstring(string s1, string s2);
string computeLCS(string s1, string s2);

string longestCommonSubstring(string s1, string s2) {
    return computeLCS(s1, s2);
}

string computeLCS(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[m + 1];
    }
    int maxLength = 0;
    int endIndex = 0;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    if (maxLength > 0) {
        return s1.substr(endIndex - maxLength + 1, maxLength);
    } else {
        return "";
    }
}

int main() {
    string s1 = "helloiam";
    string s2 = "helloi";
    string lcs = longestCommonSubstring(s1, s2);
    cout << "Longest Common Substring: " << lcs << endl;
    return 0;
}
