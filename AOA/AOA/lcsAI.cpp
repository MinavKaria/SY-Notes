#include <iostream>
#include <queue>
#include <string>
#include <chrono>

using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    queue<int> Q;
    int matNum = 0;

    for (int i = 0; i <= n; i++) {
        queue<int> cRow;
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                cRow.push(0);
            } else {
                if (s1[i - 1] == s2[j - 1]) {
                    int diag = Q.front();
                    Q.pop();
                    int pVal = diag + 1;
                    cRow.push(pVal);
                    if (pVal > matNum) {
                        matNum = pVal;
                    }
                } else {
                    int diag = Q.front();
                    Q.pop();
                    int vertVal = cRow.front();
                    int pVal = max(diag, vertVal);
                    cRow.push(pVal);
                }
            }
        }
        Q = cRow;
    }
    return matNum;
}

int main() {
    long avgtime = 0;
    for (int i = 0; i < 1000; i++) {
        string s1 = "helloiam";
        string s2 = "hello";
        auto startTime = chrono::high_resolution_clock::now();
        int lcsLength = lcs(s1, s2);
        auto stopTime = chrono::high_resolution_clock::now();
        // avgtime += chrono::duration_cast<chrono::nanoseconds>(stopTime - startTime).count();
        // cout << lcsLength << endl;
        cout << chrono::duration_cast<chrono::nanoseconds>(stopTime - startTime).count() << endl;
    }
    float avgF = avgtime / 1000000000.0;
    cout << avgF << endl;
    return 0;
}
