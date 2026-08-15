#include <bits/stdc++.h>
using namespace std;

struct allMoves {
    int h, p, s;
};

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N; cin >> N;
    vector<char> moves(N);
    for (int i = 0; i<N; i++) {
        cin >> moves[i];
    }

    vector<allMoves> prefixSum(N+1);
    prefixSum[0] = {0, 0, 0};
    for (int i = 1; i<N+1; i++) {
        prefixSum[i] = prefixSum[i-1];
        char move = moves[i-1];
        if (move == 'P') prefixSum[i].p++;
        if (move == 'H') prefixSum[i].h++;
        if (move == 'S') prefixSum[i].s++;
    }

    vector<allMoves> suffixSum(N+1);
    suffixSum[N] = {0, 0, 0};
    for (int i = N-1; i>=0; i--) {
        suffixSum[i] = suffixSum[i+1];
        char move = moves[i];
        if (move == 'P') suffixSum[i].p++;
        if (move == 'H') suffixSum[i].h++;
        if (move == 'S') suffixSum[i].s++;
    }

    int maxWins = 0;
    for (int i = 0; i<N+1; i++) {
        int maxPrefix = max(max(prefixSum[i].h, prefixSum[i].p), prefixSum[i].s);
        int maxSuffix = max(max(suffixSum[i].h, suffixSum[i].p), suffixSum[i].s);
        maxWins = max(maxWins, maxPrefix + maxSuffix);
    }
    cout << maxWins;
}