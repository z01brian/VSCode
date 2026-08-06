#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(nums.begin(), nums.end());
    int i = 0; int j = nums.size()-1;
    while (i<j) {
        if (nums[i].first + nums[j].first == x) {
            cout << nums[i].second << " " << nums[j].second;
            return 0;
        }
        if (nums[i].first+nums[j].first < x) {
            i++;
        } else {
            j--;
        }
    }
    cout << "IMPOSSIBLE";
}