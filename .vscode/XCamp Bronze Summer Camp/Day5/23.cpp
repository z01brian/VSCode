#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<vector<int>> ans;
    for (int i = 0; i<t; i++) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int j = 0; j<n; j++) {
            cin >> nums[j];
        }
        vector<int> answer(n);
        for (int j = 0; j<n; j++) {
            answer[j] = n+1-nums[j];
        }
        ans.push_back(answer);
    }
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
}