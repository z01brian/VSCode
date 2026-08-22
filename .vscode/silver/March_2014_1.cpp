#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points;

int findDistance(int a, int b) {
    return (points[a].first - points[b].first)*(points[a].first - points[b].first)+(points[a].second - points[b].second)*(points[a].second - points[b].second);
}

int main() {
    freopen("irrigation.in", "r", stdin);
    freopen("irrigation.out", "w", stdout);
    int N, C; cin >> N >> C;

    points.resize(N);
    for (int i = 0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int cost = 0;
    int currPoint = 0;
    vector<int> distanceToPartition(N, INT_MAX);
    distanceToPartition[0] = 0;
    for (int i = 1; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (distanceToPartition[j] != 0) {
                int distance = findDistance(currPoint, j);
                if (distance < C) continue;
                distanceToPartition[j] = min(distanceToPartition[j], distance);
            }
        }
        pair<int, int> nextPoint = {currPoint, INT_MAX};
        for (int j = 0; j<N; j++) {
            if (distanceToPartition[j] != 0 && distanceToPartition[j] < nextPoint.second) {
                nextPoint.first = j;
                nextPoint.second = distanceToPartition[j];
            }
        }

        if (nextPoint.first == currPoint) {
            cout << -1;
            return 0;
        }

        currPoint = nextPoint.first;
        cost += nextPoint.second;
        distanceToPartition[nextPoint.first] = 0;
    }
    cout << cost;
}