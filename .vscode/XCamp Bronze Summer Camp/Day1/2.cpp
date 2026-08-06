#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("promote.in", "r", stdin);
    // freopen("promote.out", "w", stdout);

    vector<pair<int, int>> contestants(4);
    for (int i = 0; i<4; i++) {
        cin >> contestants[i].first >> contestants[i].second;
    }

    vector<int> newContestants(4);
    for (int i = 0; i<4; i++) {
        newContestants[i] = contestants[i].second-contestants[i].first;
    }

    vector<int> ans(3, 0);
    for (int i = 3; i>=1; i--) {
        int amt = newContestants[i];
        for (int j = i-1; j>=0; j--) {
            ans[j] += amt;
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
    return 0;
}