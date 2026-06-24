#include <bits/stdc++.h>
using namespace std;
int n, k;
bool sum(vector<int>& nums, int currSum, int index) {
    if (currSum == k) {
        return true;
    }
    if (index == n) {
        return false;
    }
    int num = nums[index];
    return sum(nums, currSum+num, index+1) || sum(nums, currSum, index+1);
}

int main() {
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) {
        cin >> nums[i];
    }
    if (sum(nums, 0, 0)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}