#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> cows(M);
    for (int i = 0; i<M; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    vector<int> pastures(N, -1);
    for (int i = 0; i<M; i++) {
        int pasture1 = cows[i].first;
        int pasture2 = cows[i].second;
        
    }
    for (auto i : pastures) {
        cout << i;
    }
}