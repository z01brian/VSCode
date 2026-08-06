#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    set<pair<int, int>> visited;
    visited.insert({0, 0});
    int currX = 0; int currY = 0;
    int amt = 0;
    for (int i = 0; i<M; i++) {
        char dir; cin >> dir;
        int moves; cin >> moves;
        if (dir == 'S') {
            for (int j = 0; j<moves; j++) {
                currY--;
                if (!visited.insert({currX, currY}).second) amt++;
            }
        } else if (dir == 'N') {
            for (int j = 0; j<moves; j++) {
                currY++;
                if (!visited.insert({currX, currY}).second) amt++;
            }
        } else if (dir == 'W') {
            for (int j = 0; j<moves; j++) {
                currX--;
                if (!visited.insert({currX, currY}).second) amt++;
            }
        } else if (dir == 'E') {
            for (int j = 0; j<moves; j++) {
                currX++;
                if (!visited.insert({currX, currY}).second) amt++;
            }
        }
    }
    cout << amt;
}