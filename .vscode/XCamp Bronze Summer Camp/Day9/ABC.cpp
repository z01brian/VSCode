#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums(7);
    for (int i = 0; i<7; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int A = nums[0];
    int B = nums[1];
    int C = nums[6] - A - B;
    cout << A << " " << B << " " << C;
}