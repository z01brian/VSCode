#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while (t-- > 0) {
        int n; cin >> n;
        vector<int> teeth(n);
        for (int i = 0; i<n; i++) {
            cin >> teeth[i];
        }
        unordered_map<int, int> map;
        bool sol = true;
        for (int i = 0; i<n; i++) {
            map[teeth[i]]++;
            if (map[teeth[i]] > 1) {
                cout << "YES" << "\n";
                sol = false;
                break;
            }
        }
        if (sol) cout << "NO" << "\n";


    }
}