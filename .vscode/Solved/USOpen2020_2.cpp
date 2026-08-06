#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);

    int N; cin >> N;
    vector<pair<int, int>> cows(N);
    unordered_map<int, int> cowMap;
    for (int i = 0; i<N; i++) {
        cin >> cows[i].first >> cows[i].second;
        cowMap[cows[i].first] = cows[i].second;
    }
    sort(cows.begin(), cows.end());

    int r = INT_MAX;
    for (int i = 0; i<N; i++) {
        if (i+1 < N && cows[i].second != cows[i+1].second) {
            r = min(r, cows[i+1].first - cows[i].first - 1);
        }
    }


    int count = 0;
    int prevInfectedIndex = -1;

    for (int i = 0; i<N; i++) {
        if (cows[i].second == 0) continue;
        if (prevInfectedIndex == -1 || cows[i].first-prevInfectedIndex >r) {
            count++;
        }
        prevInfectedIndex = cows[i].first;

    }
    cout << count;
}