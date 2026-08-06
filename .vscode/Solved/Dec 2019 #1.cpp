#include <bits/stdc++.h>
using namespace std;
int N, K;

bool consistent(vector<vector<int>>& performances, int cow1, int cow2) {
    for (int i = 0; i<K; i++) {
        int currIndex1 = 0;
        int currIndex2 = 0;
        for (int j = 0; j<N; j++) {
            if (performances[i][j] == cow1) {
                currIndex1 = j;
            }
            if (performances[i][j] == cow2) {
                currIndex2 = j;
            }
        }
        if (!(currIndex1<currIndex2)) return false;
    }
    return true;
}

int main() {
    cin >> K >> N;

    vector<vector<int>> performances(K, vector<int>(N));
    for (int i = 0; i<K; i++) {
        for (int j = 0; j<N; j++) {
            cin >> performances[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i<N; i++) {
        for (int j = i+1; j<N; j++) {
            if (consistent(performances, performances[0][i], performances[0][j])) count++;
        }
    }
    cout << count;
}