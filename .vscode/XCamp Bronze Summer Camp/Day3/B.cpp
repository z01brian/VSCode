#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; long long x; cin >> n >> x;
    vector<pair<long long, int>> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i<n; i++) {
        long long needed = x - nums[i].first;
        int left = 0; int right = n-1;
        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            if (nums[left].first + nums[right].first == needed) {
                cout << nums[left].second << " " << nums[right].second << " " << nums[i].second;
                return 0;
            }
            if (nums[left].first + nums[right].first < needed) {
                left++;
            } else {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE";
}