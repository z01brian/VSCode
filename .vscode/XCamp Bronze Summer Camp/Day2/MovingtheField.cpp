#include <bits/stdc++.h>
using namespace std;

int main() {

    // freopen("mowing.in", "r", stdin);
    // freopen("mowing.out", "w", stdout);

    int N; cin >> N;
    vector<pair<char, int>> commands(N);
    for (int i = 0; i<N; i++) {
        cin >> commands[i].first >> commands[i].second;
    }


    map<pair<int, int>, int> timeVisited;
    timeVisited[{0, 0}] = 0;
    set<pair<int, int>> visited;
    visited.insert({0, 0});

    int time = 0;
    int minTime = INT_MAX;
    int x = 0; int y = 0;
    for (int i = 0; i<N; i++) {
        char dir = commands[i].first;
        int amt = commands[i].second;
        if (dir == 'N') {
            for (int j = 0; j<amt; j++) {
                time++;
                y++;
                if (!visited.insert({x, y}).second) {
                    minTime = min(minTime, time-timeVisited[{x, y}]);
                }
                timeVisited[{x, y}] = time;
            }
        }
        if (dir == 'S') {
            for (int j = 0; j<amt; j++) {
                time++;
                y--;
                if (!visited.insert({x, y}).second) {
                    minTime = min(minTime, time-timeVisited[{x, y}]);
                }
                timeVisited[{x, y}] = time;
            }
        }
        if (dir == 'W') {
            for (int j = 0; j<amt; j++) {
                time++;
                x--;
                if (!visited.insert({x, y}).second) {
                    minTime = min(minTime, time-timeVisited[{x, y}]);
                }
                timeVisited[{x, y}] = time;
            }
        }
        if (dir == 'E') {
            for (int j = 0; j<amt; j++) {
                time++;
                x++;
                if (!visited.insert({x, y}).second) {
                    minTime = min(minTime, time-timeVisited[{x, y}]);
                }
                timeVisited[{x, y}] = time;
            }
        }
        
    }
    if (minTime == INT_MAX) {
        cout << -1; 
        return 0;
    }
    cout << minTime;


}