#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> shifts(N);
    vector<int> lifeguards(1000);
    for (int i = 0; i<N; i++) {
        int start, end;
        cin >> start >> end;
        lifeguards[start]++;
        lifeguards[end+1]--;
        shifts[i].first = start;
        shifts[i].second = end;
    }

    int onDuty = 0;
    int originalTime = 0;

    for (int i = 0; i<1000; i++) {
        onDuty += lifeguards[i];
        lifeguards[i] = onDuty;
        if (lifeguards[i] != 0) originalTime++;
    }

    int maxTime = 0;

    for (int i = 0; i<N; i++) {
        int start = shifts[i].first;
        int end = shifts[i].second;
        int currTime = originalTime;

        for (int j = start; j<=end; j++) {
            lifeguards[j]--;
            if (lifeguards[j] == 0) currTime--;
        }

        maxTime = max(maxTime, currTime);
    }
    cout << maxTime;
}