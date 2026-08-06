#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    vector<int> ans;
    for (int i = 0; i<t; i++) {
        int length; cin >> length;
        int sum = 0;
        for (int j = 0; j<length; j++) {
            int a; cin >> a;
            sum += a;
        }
        if (sum > length) {
            int x = 0;
            while (sum != length) {
                length++;
                x++;
            }
            ans.push_back(x);
            continue;
        }
        if (sum < length) {
            ans.push_back(1);
            continue;
        }
        ans.push_back(0);
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}