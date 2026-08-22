#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<pair<int, int>> fav(N);
    for (int i = 0; i<N; i++) {
        cin >> fav[i].first >> fav[i].second;
    }

    vector<int> taken(M+1, -1);
    vector<int> ans(N);
    int takenCount = 0;

    for (int i = N-1; i>=0; i--) {
        int curr = i;
        int currCereal = fav[curr].first;
        while (true) {
            if (taken[currCereal] == -1) {
                taken[currCereal] = curr;
                takenCount++;
                break;
            }
            if (taken[currCereal] < curr) break;
            int nextCow = taken[currCereal];
            taken[currCereal] = curr;

            if (currCereal == fav[nextCow].second) break;

            curr = nextCow;
            currCereal = fav[curr].second;
        }
        ans[i] = takenCount;
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}