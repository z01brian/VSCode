#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> breakouts(N);

    for (int i = 0; i<N; i++) {
        cin >> breakouts[i];
    }

    if (breakouts[0] > 0) {
        cout << -1;
        return 0;
    }
    breakouts[0] = 0;
    for (int i = N-1; i>=0; i--) {
        if (breakouts[i] >= 0) {
            for (int j = 1; j <= breakouts[i]; j++) {
                if (breakouts[i-j] == -1) breakouts[i-j] = breakouts[i] - j;
                if (breakouts[i-j] != breakouts[i]-j) {
                    cout << -1;
                    return 0;
                }
            }
            i-=breakouts[i];
        }
    }

    int most = 0; int least = 0;
    for (int i = 0; i<N; i++) {
        if (breakouts[i] == 0) {
            most++;
            least++;
        }
        if (breakouts[i] == -1) {
            most++;
        }
    }
    cout << least << " " << most;

}