#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N; cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }


    int area = 0;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            for (int k = 0; k<N; k++) {
                if (points[i].first == points[j].first && points[i].second == points[k].second) {
                    area = max(area, abs(points[i].second - points[j].second)*abs(points[i].first-points[k].first));
                }
            }
        }
    }
    cout << area;

    
}