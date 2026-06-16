#include <bits/stdc++.h>
using namespace std;

int N;

int rps(int rock, int paper, int scissors, vector<pair<int, int>>& games) {
    int victories = 0;
    for (int i = 0; i<N; i++) {
        int first = games[i].first;
        int second = games[i].second;
        if (first == rock && second == scissors) victories++;
        if (first == paper && second == rock) victories++;
        if (first == scissors && second == paper) victories++;
    }
    return victories;
}

int main() { //recursive 
    cin >> N;
    vector<pair<int, int>> games(N);

    for (int i = 0; i<N; i++) {
        cin >> games[i].first >> games[i].second;
    }

    int maxVictories = 0;
    maxVictories = max(maxVictories, rps(1, 2, 3, games));
    maxVictories = max(maxVictories, rps(1, 3, 2, games));
    maxVictories = max(maxVictories, rps(2, 1, 3, games));
    maxVictories = max(maxVictories, rps(2, 3, 1, games));
    maxVictories = max(maxVictories, rps(3, 1, 2, games));
    maxVictories = max(maxVictories, rps(3, 2, 1, games));

    cout << maxVictories;
}