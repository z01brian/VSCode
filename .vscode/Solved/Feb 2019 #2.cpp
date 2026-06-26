#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> favorites(M);
    for (int i = 0; i<M; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        if (p1 > p2) swap(p1, p2);
        favorites[i].first = p1;
        favorites[i].second = p2;
    }
    sort(favorites.begin(), favorites.end());

    vector<int> pastures(N+1);
    vector<unordered_set<int>> cannotAdd(N+1);
    for (int i = 1; i<=N; i++) {
        int addedPasture;
        if (cannotAdd[i].empty()) {
            pastures[i] = 1;
            addedPasture = 1;
        } else {
            for (int j = 1; j<=4; j++) {
                if (cannotAdd[i].find(j) == cannotAdd[i].end()) {
                    pastures[i] = j;
                    addedPasture = j;
                    break;
                }
            }
        }
        for (int j = 0; j<M; j++) {
            if (favorites[j].first == i) {
                cannotAdd[favorites[j].second].insert(addedPasture);
            }
        }
    }
    for (int i = 1; i<=N; i++) {
        cout << pastures[i];
    }

}