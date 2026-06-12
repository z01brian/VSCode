#include <bits/stdc++.h>
using namespace std;

pair<int, int> simulate(string intended) {
    int x = 0;
    int y = 0;
    int currDir = 0; //north, west, south, east

    vector<int> xDir = {0, 1, 0, -1};
    vector<int> yDir = {1, 0, -1, 0};

    for (char c : intended) {
        if (c == 'F') {
            x += xDir[currDir];
            y += yDir[currDir];
        } else if (c == 'L') {
            currDir = (currDir+3)%4;
        } else {
            currDir = (currDir+1)%4;
        }
    }
    return make_pair(x, y);
}

int main() {
    string intended; cin >> intended;

    set<pair<int, int>> cords;
    vector<char> dirs = {'F', 'L', 'R'};

    for (int i = 0; i<intended.size(); i++) {
        char c = intended[i];
        for (auto dir : dirs) {
            if (dir == c) continue;
            intended[i] = dir;
            pair<int, int> newPosition = simulate(intended);
            cords.insert(newPosition);
            intended[i] = c;
        }
    }
    cout << cords.size();
}