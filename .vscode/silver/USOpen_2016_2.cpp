#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int N; ll K;
    cin >> N >> K;

    vector<ll> diamonds(N);
    for (int i = 0; i<N; i++) {
        cin >> diamonds[i];
    }
    sort(diamonds.begin(), diamonds.end());

    vector<int> prefixSum(N);
    vector<int> suffixSum(N);

    int left = 0;
    for (int i = 0; i < N; i++) {
        while (diamonds[i] - diamonds[left] > K) {
            left++;
        }
        int curr = i - left + 1;
        prefixSum[i] = curr;
        if (i > 0) {
            prefixSum[i] = max(prefixSum[i], prefixSum[i - 1]);
        }
    }

    int right = N - 1;
    for (int i = N - 1; i >= 0; i--) {
        while (diamonds[right] - diamonds[i] > K) {
            right--;
        }
        int curr = right - i + 1;
        suffixSum[i] = curr;
        if (i < N - 1) {
            suffixSum[i] = max(suffixSum[i], suffixSum[i + 1]);
        }
    }

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans = max(ans, prefixSum[i] + suffixSum[i + 1]);
    }
    // ans = max(ans, prefixSum[N - 1]);

    cout << ans;

}