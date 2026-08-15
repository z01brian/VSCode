#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);

    int N; cin >> N;
    int currX = 0; int currY = 0;
    set<pair<int, int>> reachedPoints;
    set<pair<pair<int, int>, pair<int, int>>> reachedSegments;
    reachedPoints.insert({0, 0});
    int gatesNeeded = 0;
    string s;
    cin >> s;

    for (int i = 0; i<N; i++) {
        int prevX = currX; int prevY = currY;
        char dir = s[i];
        if (dir == 'N') {
            currY++;
        } else if (dir == 'S') {
            currY--;
        } else if (dir == 'W') {
            currX--;
        } else {
            currX++;
        }
        vector<pair<int, int>> segmentPoints = {{prevX, prevY}, {currX, currY}};
        sort(segmentPoints.begin(), segmentPoints.end());
        if (!reachedPoints.insert({currX, currY}).second && reachedSegments.insert({segmentPoints[0], segmentPoints[1]}).second) gatesNeeded++;
        reachedSegments.insert({segmentPoints[0], segmentPoints[1]});
    }
    cout << gatesNeeded;
}