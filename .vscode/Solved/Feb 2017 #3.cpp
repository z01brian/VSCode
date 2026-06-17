#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> cows(N); //<arrival time, time spent>

    for (int i = 0; i<N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int time = 0;
    for (int i = 0; i<N; i++) {
        int arrival = cows[i].first;
        int timeTaken = cows[i].second;

        if (arrival >= time) {
            time = arrival;
            time += timeTaken;
            continue;
        }

        if (arrival<time) {
            time += timeTaken;
            continue;
        }
    }
    cout << time;
}