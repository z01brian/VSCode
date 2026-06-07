#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    queue<pair<int, int>> q;
    int trees[M][N] = {};
    int xDir[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int yDir[8] = {0, 0, 1, -1, -1, 1, 1, -1};
    int maxDays = 1;

    while (K-->0) {
        int row, col;
        cin >> row >> col;
        trees[row][col] = 1;
        q.push(make_pair(row, col));
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i<8; i++) {
            int newRow = p.first + xDir[i];
            int newCol = p.second + yDir[i];
            int size = 0;
            if (newRow >= 0 && newRow < M && newCol >= 0 && newCol < N && trees[newRow][newCol] == 0) {
                trees[newRow][newCol] = trees[p.first][p.second] + 1;
                maxDays = max(maxDays, trees[newRow][newCol]);
                q.push(make_pair(newRow, newCol));
            }
        }
    }
    cout << maxDays-1 << "\n";

    return 0;
}