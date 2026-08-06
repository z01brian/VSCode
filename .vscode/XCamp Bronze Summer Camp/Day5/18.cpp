#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<pair<int, int>> ans;
    for (int i = 0; i<t; i++) {
        int n; cin >> n;
        int c1 = n/3; int c2 = n/3;
        n%=3;
        if (n == 2) c2++;
        if (n==1)c1++;
        ans.push_back({c1, c2});
    }
    for (auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}