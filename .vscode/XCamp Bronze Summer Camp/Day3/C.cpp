#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<long long, int>> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i<nums.size(); i++) {
        for (int j = i+1; j<nums.size(); j++) {
            int needed = x - nums[i].first - nums[j].first;
            int left = j+1; int right = nums.size()-1;
            while (left < right) {
                if (nums[left].first + nums[right].first == needed) {
                    cout << nums[left].second << " " << nums[right].second << " " << nums[i].second << " " << nums[j].second;
                    return 0;
                }
                if (nums[left].first + nums[right].first < needed) {
                    left++;
                } else {
                    right--;
                }
            }

        }
    }
    cout << "IMPOSSIBLE";
}