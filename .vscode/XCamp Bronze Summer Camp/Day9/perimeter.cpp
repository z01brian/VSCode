#include <bits/stdc++.h>
using namespace std;

int N;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int isPerimeter(int row, int col, vector<string>& icecream) {
    int border = 0;
    for (int i = 0; i<8; i++) {
        if (row == N-1 || row == 0 || col == N-1 || col == 0) border++;
        if (row + dx[i] < N && row + dx[i] >= 0 && col + dy[i] < N && col + dy[i] >= 0 && icecream[row + dx[i]][col + dy[i]] == '.') {
            border++;
        }
    }
    return border;
}

pair<int, int> bfs(int startRow, int startCol, vector<vector<bool>>& marked, vector<string>& icecream) {
    queue<pair<int, int>> q;
    int area = 0;
    int perimeter = 0;
    q.push({startRow, startCol});
    marked[startRow][startCol] = true;
    int left, right, top, bottom;
    while (!q.empty()) {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        left = min(left, currCol);
        right = max(right, currCol);
        top = min(top, currRow);
        bottom = max(top, currRow);
        area++;

        for (int i = 0; i<4; i++) {
            if (currRow + dx[i] < N && currRow + dx[i] >= 0 && currCol + dy[i] < N && currCol + dy[i] >= 0 && icecream[currRow + dx[i]][currCol + dy[i]] == '#' && !marked[currRow + dx[i]][currCol + dy[i]]) {
                q.push({currRow + dx[i], currCol + dy[i]});
                marked[currRow + dx[i]][currCol + dy[i]] = true;
            }
        }
    }
    return {area, perimeter};
}

int main() {
    cin >> N;
    vector<string> icecream(N);
    for (int i = 0; i<N; i++) {
        cin >> icecream[i];
    }
    vector<vector<bool>> marked(N, vector<bool>(N));
    vector<pair<int, int>> blobs;

    bool found = false;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (icecream[i][j] == '#') {
                blobs.push_back(bfs(i, j, marked, icecream));
                found = true;
                break;
            }
        }
        if (found) break;
    }
    found = false;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (icecream[i][j] == '#' && marked[i][j] == false) {
                blobs.push_back(bfs(i, j, marked, icecream));
                found = true;
                break;
            }
        }
        if (found) break;
    }
    sort(blobs.begin(), blobs.end());
    if (blobs[0].first == blobs[1].first) {
        cout << blobs[0].first << " " << blobs[0].second;
    } else {
        cout << blobs[1].first << " " << blobs[1].second;
    }
}