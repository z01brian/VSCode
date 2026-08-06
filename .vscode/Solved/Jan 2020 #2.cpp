#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cows(N-1);
    for (int i = 0; i<N-1; i++) {
        cin >> cows[i];
    }

    for (int i = 1; i<=N; i++) {
        unordered_set<int> used;
        vector<int> sol(N);

        sol[0] = i;
        used.insert(i);
        bool unique = true;
        for (int j = 1; j<N; j++) {
            sol[j] = cows[j-1] - sol[j-1];
            if (!used.insert(sol[j]).second) {
                unique = false;
                break;
            }
        }
        if (unique) {
            for (int j = 0; j<N; j++) {
                cout << sol[j];
                if (j != N-1) cout << " ";
            }
            return 0;
        }
    }
}