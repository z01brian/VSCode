#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> logs(N);
    int minLog = INT_MAX;
    for (int i = 0; i<N; i++) {
        int log;
        cin >> log;
        logs[i] = log;
        minLog = min(minLog, log);
        
    }

    while (minLog-->=0) {
        int amt = 0;
        for (int i = 0; i<N; i++) {
            amt += logs[i]/minLog;
        }
        if (amt >= K) {
            cout << minLog;
            return 0;
        }
    }
}