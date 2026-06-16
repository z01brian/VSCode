#include <bits/stdc++.h>
using namespace std;

int N;

int flip(vector<vector<char>>& grid, int flips) {
    int row = -1;
    int col = -1;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            if (grid[i][j] == '1') {
                row = i;
                col = j;
            }
        }
    }

    if (row == -1) {
        return flips;
    }

    for (int i = 0; i<=row; i++) {
        for (int j = 0; j<=col; j++) {
            if (grid[i][j] == '0') {
                grid[i][j] = '1';
            } else {
                grid[i][j] = '0';
            }
        }
    }
    return flip(grid, flips+1);
}

int main() {
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N));

    for (int i = 0; i<N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j<N; j++) {
            grid[i][j] = s[j];
        }
    }

    cout << flip(grid, 0);

}