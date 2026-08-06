#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> citations(N);
    for (int i = 0; i<N; i++) {
        cin >> citations[i];
    }
    sort(citations.begin(), citations.end());

    int currH = 0;
    for (int i = 0; i<N; i++) {
        int val = citations[i];
        if (N-i >= val) {
            currH = val;
        }
    }

    while (L > 0) {
        int wantedH = currH+1;
        int possible = true;

        if (wantedH > N) break;
        for (int i = N-1; i >= N-wantedH; i--) {
            if (citations[i] >= wantedH) continue;
            if (wantedH - citations[i] > L) {
                possible = false;
                break;
            }
            L -= wantedH - citations[i];
            citations[i] = wantedH;
        }

        if (possible) {
            currH++;
        } else {
            break;
        }
    }
    cout << currH;
}