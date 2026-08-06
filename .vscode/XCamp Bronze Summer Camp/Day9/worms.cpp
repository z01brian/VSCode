#include <bits/stdc++.h>
using namespace std;

int comp(pair<int, int> a, int target) {
    return a.first < target;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> piles(n+1);
    piles[0] = {0, 0};
    for (int i = 1; i<n+1; i++) {
        int x; cin >> x;
        piles[i].first = piles[i-1].first + x;
        piles[i].second = i;
    }
    int m; cin >> m;
    vector<int> juicyWorms(m);
    for (int i = 0; i<m; i++) {
        cin >> juicyWorms[i];
        auto it = lower_bound(piles.begin(), piles.end(), juicyWorms[i], comp);
        pair<int, int> found;
        if (it == piles.end()) {
            found = {0, n};
        } else {
            found = *it;
        }
        cout << found.second << "\n";
    }
}