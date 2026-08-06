#include <bits/stdc++.h>
using namespace std;

int findChange(vector<vector<pair<char, int>>> optimalSquare, int N) {
    int ans = 0;
    for (int i = 0; i<N/2; i++) {
        for (int j = 0; j<N/2; j++) {
            ans += 4-optimalSquare[i][j].second;
        }
    }
    return ans;
}

int main() {
    int N, U; cin >> N >> U;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<pair<char, int>>> optimalSquare(N/2, vector<pair<char, int>>(N/2));

    int needChange = 0;
    for (int i = 0; i<N/2; i++) {
        for (int j = 0; j<N/2; j++) {
            int dots = 0;
            if (grid[i][j] == '.') dots++;
            if (grid[N-i-1][j] == '.') dots++;
            if (grid[i][N-j-1] == '.') dots++;
            if (grid[N-i-1][N-j-1] == '.') dots++;
            if (dots >= 2) {
                optimalSquare[i][j] = {'.', dots};
            } else {
                optimalSquare[i][j] = {'#', 4-dots};
            }
            needChange += 4-optimalSquare[i][j].second;
        }
    }
    cout << needChange << "\n";


    while (U-- > 0) {
        int row, col; cin >> row >> col; 
        row--; col--;

        int optimalRow = row; int optimalCol = col;
        if (row >= N/2) {
            optimalRow = N - row - 1;
        }
        if (col >= N/2) {
            optimalCol = N - col - 1;
        }
        needChange -= 4-optimalSquare[optimalRow][optimalCol].second;

        if (grid[row][col] == '.') {
            grid[row][col] = '#';
            if (optimalSquare[optimalRow][optimalCol].first == '.') {
                optimalSquare[optimalRow][optimalCol].second--;
                // needChange++;
            } else {
                optimalSquare[optimalRow][optimalCol].second++;
                // needChange--;
            }
        } else {
            grid[row][col] = '.';
            if (optimalSquare[optimalRow][optimalCol].first == '#') {
                optimalSquare[optimalRow][optimalCol].second--;
                // needChange++;
            } else {
                optimalSquare[optimalRow][optimalCol].second++;
                // needChange--;
            }
        }
        if (optimalSquare[optimalRow][optimalCol].second < 2) {
            if (optimalSquare[optimalRow][optimalCol].first == '.') {
                optimalSquare[optimalRow][optimalCol].first = '#';
                optimalSquare[optimalRow][optimalCol].second = 3; 
            } else {
                optimalSquare[optimalRow][optimalCol].first = '.';
                optimalSquare[optimalRow][optimalCol].second = 3; 
            }
        }
        // needChange = findChange(optimalSquare, N);
        // needChange += 4-optimalSquare[optimalRow][optimalCol].second;
        // for (int i = 0; i<N; i++) {
        //     for (int j = 0; j<N; j++) {
        //         cout << grid[i][j];
        //     }
        //     cout << "\n";
        // }
        needChange += (4 - optimalSquare[optimalRow][optimalCol].second);
        cout << needChange << "\n";
    }
}