#include <bits/stdc++.h>
using namespace std;

int n;
int endX, endY;

void bfs(int startX, int startY, vector<vector<int>>& marked) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    marked[startX][startY] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        

        if (y+2<n && x+1<n && marked[x+1][y+2] == -1) {
            marked[x+1][y+2] = marked[x][y]+1;
            q.push({x+1, y+2});
        }
        if (y+2<n && x-1>=0 && marked[x-1][y+2] == -1) {
            marked[x-1][y+2] = marked[x][y]+1;
            q.push({x-1, y+2});
        }
        if (y-2>=0 && x+1<n && marked[x+1][y-2] == -1) {
            marked[x+1][y-2] = marked[x][y]+1;
            q.push({x+1, y-2});
        }
        if (y-2>=0 && x-1>=0 && marked[x-1][y-2] == -1) {
            marked[x-1][y-2] = marked[x][y]+1;
            q.push({x-1, y-2});
        }
        if (x+2<n && y+1<n && marked[x+2][y+1] == -1) {
            marked[x+2][y+1] = marked[x][y]+1;
            q.push({x+2, y+1});
        }
        if (x+2<n && y-1>=0 && marked[x+2][y-1] == -1) {
            marked[x+2][y-1] = marked[x][y]+1;
            q.push({x+2, y-1});
        }
        if (x-2>=0 && y+1<n && marked[x-2][y+1] == -1) {
            marked[x-2][y+1] = marked[x][y]+1;
            q.push({x-2, y+1});
        }
        if (x-2>=0 && y-1>=0 && marked[x-2][y-1] == -1) {
            marked[x-2][y-1] = marked[x][y]+1;
            q.push({x-2, y-2});
        }

    }


}


int main() {
    cin >> n;
    int startX, startY;
    cin >> startX >> startY >> endX >> endY;

    vector<vector<int>> marked(n, vector<int>(n, -1));
    bfs(startX, startY, marked);
    cout << marked[endX][endY];

}