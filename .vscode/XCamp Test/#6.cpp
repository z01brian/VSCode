#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
    int friendly = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (col < m-1) {
                if (matrix[row][col] == matrix[row][col+1]) friendly++;
            }
            if (row < n-1) {
                if (matrix[row][col] == matrix[row+1][col]) friendly++;
            }
        }
    }

    cout << friendly;
}