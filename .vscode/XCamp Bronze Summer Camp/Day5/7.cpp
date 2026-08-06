#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int amt = 0;
    vector<int> scores(n);
    for (int i = 0; i<n; i++) {
        cin >> scores[i];
    }
    int ans = 0;
    for (int score : scores) {
        if (score >= scores[k-1] && score > 0) ans++;
    }
    cout << ans;
}