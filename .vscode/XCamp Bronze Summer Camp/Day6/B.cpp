#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; int Q; cin >> N >> Q;
    vector<int> events(Q);
    for (int i = 0; i<Q; i++) {
        cin >> events[i];
    }

    vector<int> amtAhead(N+1, 1); //1 means they're on the same lap 
    int laps = 0;
    for (int i = 0; i<Q; i++) {
        if (events[i] > 0) {
            if (amtAhead[events[i]] < 1) {
                laps++;
            }
            amtAhead[events[i]]--;
        } else {
            amtAhead[events[i]*(-1)]++;
        }
    }
    cout << laps;
}