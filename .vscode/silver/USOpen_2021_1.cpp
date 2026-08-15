#include <bits/stdc++.h>
using namespace std;

bool isWin(int index) {
    vector<vector<int>> winningPositions = {
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {2, 4, 6},
        {0, 4, 8}
    };

    vector<int> currGrid(9); //nothing = 0, M = 1, O = 2
    for (int i = 0; i<9; i++) {
        currGrid[i] = (index/static_cast<int>(pow(3, i))) % 3;
    }

    for (int i = 0; i < 8; i++) {
        int first = currGrid[winningPositions[i][0]];
        int second = currGrid[winningPositions[i][1]];
        int third = currGrid[winningPositions[i][2]];
        if ((first == 1 && second == 2 && third == 2) || (first == 2 && second == 2 && third == 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int N; cin >> N;
    int startRow, startCol;

    vector<vector<vector<char>>> grid (N, vector<vector<char>>(N, vector<char>(3)));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> grid[i][j][0] >> grid[i][j][1] >> grid[i][j][2];
            if (grid[i][j][0] == 'B') {
                startRow = i;
                startCol = j;
            }
        }
    }

    vector<vector<vector<bool>>> markedStates(N, vector<vector<bool>>(N, vector<bool>(static_cast<int>(pow(3, 9)))));
    vector<bool> winningBoards(static_cast<int>(pow(3, 9)));

    markedStates[startRow][startCol][0] = true;
    queue<pair<pair<int, int>, int>> q;

    q.push({{startRow, startCol}, 0});
    while (!q.empty()) {
        int currX = q.front().first.first;
        int currY = q.front().first.second;
        int index = q.front().second;
        int currIndex = index;
        q.pop();

        // vector<int> currGrid(9); //nothing = 0, M = 1, O = 2
        // for (int i = 0; i<9; i++) {
        //     currGrid[i] = (index/static_cast<int>(pow(3, i))) % 3;
        // }

        int xDir[] = {0, 0, -1, 1};
        int yDir[] = {1, -1, 0, 0};
        for (int i = 0; i<4; i++) {
            int newX = currX + xDir[i];
            int newY = currY + yDir[i];

            if (grid[newX][newY][0] == '#') {
                continue;
            }
            
            // vector<int> newGrid = currGrid;
            int newIndex = index;

            if (grid[newX][newY][0] == 'M' || grid[newX][newY][0] == 'O') {
                int row = grid[newX][newY][1] - '1';
                int col = grid[newX][newY][2] - '1';
                int position = row*3 + col;
                int currValue = (index/static_cast<int>(pow(3, position))) % 3;
                if (currValue == 0) {
                    int value = 0;
                    if (grid[newX][newY][0] == 'M') {
                        value = 1;
                    } else {
                        value = 2;
                    }

                    newIndex += value * static_cast<int>(pow(3, position));
                    if (isWin(newIndex)) {
                        winningBoards[newIndex] = true;
                        continue;
                    }
                }
            }

            if (!markedStates[newX][newY][newIndex]) {
                markedStates[newX][newY][newIndex] = true;
                q.push({{newX, newY}, newIndex});
            }
        }
    }
    int count = 0;
    for (auto i : winningBoards) {
        if (i) count++;
    }
    cout << count;
}