#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> swaps(N, vector<int>(3));
    for (int i = 0; i<N; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swaps[i][0] = a-1;
        swaps[i][1] = b-1;
        swaps[i][2] = g-1;
    }
    int maxCounter = 0;
    for (int i = 0; i<3; i++) {
        vector<int> shells(3);
        shells[i] = 1;
        int counter = 0;

        for (int j = 0; j<N; j++) {
            swap(shells[swaps[j][0]], shells[swaps[j][1]]);
            if (shells[swaps[j][2]] == 1) counter++;
        }
        maxCounter = max(counter, maxCounter);
    }
    cout << maxCounter;
}