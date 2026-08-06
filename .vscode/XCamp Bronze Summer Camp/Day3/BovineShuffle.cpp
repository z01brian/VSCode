#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> order(N);
    for (int i = 0; i<N; i++) {
        cin >> order[i];
        order[i]--;
    }
    vector<int> IDs(N);
    for (int i = 0; i<N; i++) {
        cin >> IDs[i];
    }

    for (int i = 0; i<3; i++) {
        vector<int> prevOrder(N);
        for (int j = 0; j<N; j++) {
            prevOrder[j] = IDs[order[j]];
        }
        IDs = prevOrder;
    }
    for (auto i : IDs) {
        cout << i << "\n";
    }

}