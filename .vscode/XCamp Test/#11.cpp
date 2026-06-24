#include <bits/stdc++.h>
using namespace std;
int n, m;

void possiblePositions(int currRow, int currCol, vector<vector<char>>& map, vector<vector<int>>& marked) {
    char c = map[currRow][currCol];
    if (c == '#' || marked[currRow][currCol] == 1) {
        return;
    }
    if (c == '.' || c == '@') {
        marked[currRow][currCol] = 1;
    }
    if (currRow < m-1) possiblePositions(currRow+1, currCol, map, marked);
    if (currRow > 0) possiblePositions(currRow-1, currCol, map, marked);
    if (currCol < n-1) possiblePositions(currRow, currCol+1, map, marked);
    if (currCol > 0) possiblePositions(currRow, currCol-1, map, marked);
}

int main() {
    cin >> n >> m;
    vector<vector<char>> map(m, vector<char>(n));
    vector<vector<int>> marked(m, vector<int>(n));
    int startRow, startCol;

    for (int i = 0; i<m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j<n; j++) {
            map[i][j] = row[j];
            if (row[j] == '@') {
                startRow = i; startCol = j;
            }
        }
    }

    possiblePositions(startRow, startCol, map, marked);
    int counter = 0;
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            if (marked[i][j] == 1) counter++;
        }
    }
    cout << counter;

}