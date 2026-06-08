#include <bits/stdc++.h>
using namespace std;

vector<int> xDir = {-1, 1, 0, 0};
vector<int> yDir = {0, 0, -1, 1};
int N, M;

void bfs(vector<string>& graph, vector<vector<int>>& marked, vector<pair<int, int>>& spots, int row, int col) {
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    spots.push_back(make_pair(row, col));

    while (!q.empty()) {
        pair<int, int> p = q.front();
        
        q.pop();

        for (int i = 0; i<4; i++) {
            int newRow = p.first + xDir[i];
            int newCol = p.second + yDir[i];

            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                if (marked[newRow][newCol] == 0 && graph[newRow][newCol] == 'X') {
                    spots.push_back(make_pair(newRow, newCol));
                    marked[newRow][newCol] = 1;
                    q.push(make_pair(newRow, newCol));
                }
            }
        }
    }
}


int main() {
    cin >> N >> M;
    vector<string> cow(N);

    for (int i = 0; i<N; i++) {
        cin >> cow[i];
    }

    vector<vector<int>> marked(N, vector<int>(M));
    vector<pair<int, int>> spots1;


    for (int i = 0; i<N; i++) {
            bool started = false;
        for (int j = 0; j<M; j++) {
            if (cow[i][j] == 'X' && marked[i][j] == 0) {
                bfs(cow, marked, spots1, i, j);
                started = true;
                break;
            }
        }
        if (started) break;
    }

    vector<pair<int, int>> spots2;
    for (int i = 0; i<N; i++) {
        bool started = false;
        for (int j = 0; j<M; j++) {
            if (marked[i][j] == 0 && cow[i][j] == 'X') {
                bfs(cow, marked, spots2, i, j);
                started = true;
                break;
            }
        }
        if (started) break;
    }

    int minDistance = INT_MAX;
    for (pair<int, int> i : spots1) {
        for (pair<int, int> j : spots2) {
            int distance = abs(i.first - j.first) + abs(i.second - j.second) - 1;
            minDistance = min(minDistance, distance);
        }
    }

    cout << minDistance;
}