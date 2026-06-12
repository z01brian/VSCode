#include <bits/stdc++.h>
using namespace std;

int findArea(int x1, int y1, int x2, int y2, set<pair<int, int>>& marked) {
    int area = 0;
    for (int y = y1; y > y2; y--) {
        for (int x = x1; x < x2; x++) {
            pair<int, int> cords = {x, y};
            if (marked.find(cords) == marked.end()) {
                area++;
                marked.insert(cords);
            }
        }
    }
    return area;
}

int main() {
    int N; cin >> N;
    int area = 0;
    set<pair<int, int>> marked;//x, y

    for (int i = 0; i<N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        area += findArea(x1, x2, y1, y2, marked);
    }
    cout << area;
}