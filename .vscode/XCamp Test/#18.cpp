#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> classTime(n);
    for (int i = 0; i<n; i++) {
        cin >> classTime[i].first >> classTime[i].second;
    }

    int time = 0;
    int classes = 0;
    while (true) {
        int leastTime = INT_MAX;
        for (int i = 0; i<n; i++) {
            if (classTime[i].first < time) continue;
            leastTime = min(leastTime, classTime[i].second - time);
        }
        if (leastTime == INT_MAX) break;
        time += leastTime;
        classes++;
    }
    cout << classes;
}