#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<int> ans;
    while (t-->0) {
        int n, m; cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        vector<int> posts(m);
        for (int i = 0; i<m; i++) {
            cin >> posts[i];
        }

        int maxChange = 0;
        vector<int> prefix (n+1);
        prefix[0] = 0;
        for (int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for (auto i : posts) {
            maxChange = max(maxChange, -1*prefix[i]);
        }
        ans.push_back(prefix[n] + 2*maxChange);
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}