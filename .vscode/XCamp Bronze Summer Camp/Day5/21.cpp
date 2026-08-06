#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<string> ans;
    for (int i = 0; i<t; i++) {
        int n; cin >> n;
        int a = 0; int b = 0;
        for (int j = 0; j<n; j++) {
            int x; cin >> x;
            if (x%2 == 0) {
                a += x;
            } else {
                b+=x;
            }
        }
        if (a > b) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}