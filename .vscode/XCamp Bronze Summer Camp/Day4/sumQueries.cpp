#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<long long> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    vector<long long> prefixSum(n+1);
    prefixSum[0] = 0;
    for (int i = 0; i<n; i++) {
        prefixSum[i+1] = prefixSum[i] + nums[i];
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i<q; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; queries[i].second--;
    }
    for (auto i : queries) {
        cout << prefixSum[i.second+1] - prefixSum[i.first] << "\n";
    }
}