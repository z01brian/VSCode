#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;

    vector<ll> nums(N);
    for (int i = 0; i<N; i++) {
        cin >> nums[i];
    }

    vector<long long> prefixSum(N+1);
    prefixSum[0] = 0;
    for (int i = 0; i<N; i++) {
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }

    vector<int> firstSeen(7, -1);
    for (int i = 0; i<N; i++) {
        int mod = prefixSum[i]%7;
        if (firstSeen[mod] == -1) firstSeen[mod] = i;
    }

    vector<int> lastSeen(7, -1);
    for (int i = N-1; i>=0; i--) {
        int mod = prefixSum[i]%7;
        if (lastSeen[mod] == -1) lastSeen[mod] = i;
    }

    int maxLength = 0;
    for (int i = 0; i<7; i++) {
        maxLength = max(maxLength, lastSeen[i] - firstSeen[i]);
        if (firstSeen[i] == lastSeen[i]) maxLength = max(maxLength, 1);
    }
    cout << maxLength;
}

