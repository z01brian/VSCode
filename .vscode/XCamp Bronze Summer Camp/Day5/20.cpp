#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<char> ans;
    for (int i = 0; i<t; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a + b == c) {
            ans.push_back('+');
        } else {
            ans.push_back('-');
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}