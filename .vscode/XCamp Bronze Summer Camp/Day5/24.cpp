#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    vector<int> ans;
    for (int i = 0; i<t; i++) {
        int a, b; cin >> a >> b;
        if (a == 1 && b == 2) {
            ans.push_back(3);
            continue;
        } else if (a == 1) {
            ans.push_back(2);
            continue;
        }
        ans.push_back(a-1);
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}