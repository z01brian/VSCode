#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> corners(4);

    for (int i = 0; i<4; i++) {
        cin >> corners[i].first >> corners[i].second;
    }

    int A = 0;
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) {
            int xDif = abs(corners[i].first - corners[j].first);
            int yDif = abs(corners[i].second - corners[j].second);
            A = max(A, (max(xDif, yDif)));
        }
    }
    cout << pow(A, 2);


}