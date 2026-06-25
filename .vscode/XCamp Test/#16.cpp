#include <bits/stdc++.h>
using namespace std;

int n;
int recurse(int x, vector<int>& nums, int sum, int index) {
    if (index == n) {
        if (sum == x) {
            return 1;
        }
        return 0;
    }
    int ans = recurse(x, nums, sum+nums[index], index+1) + recurse(x, nums, sum, index+1);
    return ans;
}

int main() {
    int x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }


    cout << recurse(x, nums, 0, 0);
}