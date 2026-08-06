#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mooomoo.in", "r", stdin);
    freopen("mooomoo.out", "w", stdout);
    int N, B; cin >> N >> B;
    vector<int> breed(B);
    for (int i = 0; i<B; i++) {
        cin >> breed[i];
    }

    vector<int> fieldVolume(N);
    for (int i = 0; i<N; i++) {
        cin >> fieldVolume[i];
    }

    vector<int> neededCows(N);
    neededCows[0] = fieldVolume[0];
    for (int i = N-1; i>=1; i--) {
        if (fieldVolume[i-1] > 0) {
            neededCows[i] = fieldVolume[i] - fieldVolume[i-1] + 1;
        } else {
            neededCows[i] = fieldVolume[i];
        }
    }

    vector<int> dp(100001, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i<dp.size(); i++) {
        for (auto j : breed) {
            int needed = i - j;
            if (needed < 0 || dp[needed] == INT_MAX) continue;
            dp[i] = min(dp[i], 1 + dp[needed]);
        }
    }

    int count = 0;
    for (auto i : neededCows) {
        if (dp[i] == INT_MAX) {
            cout << -1;
            return 0;
        }
        count += dp[i];
    }
    cout << count;
}