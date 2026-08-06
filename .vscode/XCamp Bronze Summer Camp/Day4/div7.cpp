#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    vector<long long> prefixSum(n+1);
    prefixSum[0] = 0;
    for (int i = 0; i<n; i++) {
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }

    int maxLength = 0;
    for (int i = 0; i<n+1; i++) {
        for (int j = i+1; j<n+1; j++) {
            if ((prefixSum[j] - prefixSum[i]) % 7 == 0) {
                maxLength = max(maxLength, j-i);
            }
        }
    }
    cout << maxLength;
}