#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<string> ans;
    for (int i =0; i<t; i++) {
        int n;
        cin >> n;
        int odd = 0; int even = 0;
        for (int j = 0; j<2*n; j++) {
            int a; cin >> a;
            if (a%2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (even == odd) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}