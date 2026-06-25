#include <bits/stdc++.h>
using namespace std;
int n;

int bfs(int x, int y, vector<vector<bool>>& marked, vector<vector<int>>& board) {
    queue<pair<int, int>> q;
    q.push({x, y});
    marked[x][y] = true;
    int counter = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int value = board[x][y];
        if (x+1 < n && !marked[x+1][y] && board[x+1][y] == (value+1)%2) {
            marked[x+1][y] = true;
            counter++;
            q.push({x+1, y});
        }
        if (x-1 >= 0 && !marked[x-1][y] && board[x-1][y] == (value+1)%2) {
            marked[x-1][y] = true;
            counter++;
            q.push({x-1, y});
        }
        if (y+1 < n && !marked[x][y+1] && board[x][y+1] == (value+1)%2) {
            marked[x][y+1] = true;
            counter++;
            q.push({x, y+1});
        }
        if (y-1 >= 0 && !marked[x][y-1] && board[x][y-1] == (value+1)%2) {
            marked[x][y-1] = true;
            counter++;
            q.push({x, y-1});
        }
    }
    return counter;
}


int main() {
    int m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i<n; i++) {
        string row; cin >> row;
        for (int j = 0; j<n; j++) {
            board[i][j] = row[j] - '0';
        }
    }
    vector<int> answers;
    while (m-->0) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        vector<vector<bool>> marked(n, vector<bool>(n, false));
        answers.push_back(bfs(i, j, marked, board));
    }
    for (auto i : answers) {
        cout << i << "\n";
    }
}