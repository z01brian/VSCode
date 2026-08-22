#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int xDir[] = {0, 0, 1, -1};
    int yDir[] = {-1, 1, 0, 0};


    int cows = 0;
    map<pair<int, int>, int> grid;
    set<pair<int, int>> marked;
    for (int i = 0; i<N; i++) {
        int x, y; cin >> x >> y;
        if (marked.count({x,y})) {
            cout << cows - i - 1 << "\n";
            continue;
        }
        queue<pair<int, int>> q;
        q.push({x,y});

        while (!q.empty()) {
            pair<int, int> newCow = q.front();
            q.pop();
            if (marked.count(newCow)) continue;
            marked.insert(newCow);
            cows++;

            for (int j = 0; j<4; j++) {
                grid[{newCow.first + xDir[j], newCow.second + yDir[j]}]++;
            }

            if (grid[newCow] == 3) {
                for (int j = 0; j<4; j++) {
                    if (!marked.count({newCow.first + xDir[j], newCow.second + yDir[j]})) {
                        q.push({newCow.first + xDir[j], newCow.second + yDir[j]});
                        break;
                    }
                }
            }

            for (int j = 0; j<4; j++) {
                if (!marked.count({newCow.first + xDir[j], newCow.second + yDir[j]})) continue;

                if (grid[{newCow.first + xDir[j], newCow.second + yDir[j]}] == 3) {
                    for (int a = 0; a<4; a++) {
                        int aX = newCow.first + xDir[j] + xDir[a];
                        int aY = newCow.second + yDir[j] + yDir[a];
                        if (!marked.count({aX, aY})) {
                            q.push({aX, aY});
                            break;
                        }
                    }
                }
            }
        }
        cout << cows - i - 1 << "\n";
    }
}