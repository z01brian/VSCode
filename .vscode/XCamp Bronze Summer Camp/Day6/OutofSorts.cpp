#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sort.in", "r", stdin);
    // freopen("sort.out", "w", stdout);
    int N; cin >> N;
    vector<pair<int, int>> nums(N+1);
    for (int i = 1; i<N+1; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
    int maxSwaps = 0;
    for (int i = 1; i<N+1; i++) {
        maxSwaps = max(maxSwaps, nums[i].second - i);
    }
    cout << maxSwaps+1;
}