#include <bits/stdc++.h>
using namespace std;

int N, T;

bool sol(int K, vector<int> durations) {
    priority_queue<int, vector<int>, greater<int>> pq;

    int time = 0;

    for (int i = 0; i<N; i++) {
        if (pq.size() == K) {
            time = pq.top();
            pq.pop();
        }

        if (time + durations[i] <= T) {
            pq.push(time + durations[i]);
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> N >> T;
    vector<int> durations(N);
    for (int i = 0; i<N; i++) {
        cin >> durations[i];
    }

    int left = 1;
    int right = N;
    while (left < right) {
        int middle = (left+right)/2;
        if (sol(middle, durations)) {
            right = middle;
        } else {
            left = middle+1;
        }
    }
    cout << right;
}