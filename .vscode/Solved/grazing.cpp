#include <bits/stdc++.h>
using namespace std;

int K;
vector<vector<int>> grass(5, vector<int>(5, 1));  //1 for grass, 0 for no grass

int recurse(int row, int col) {
    int c;
    if (row < 0 || row > 4 || col < 0 || col > 4 || grass[row][col] == 0) {
        return 0;
    }
    grass[row][col] = 0;
    K++;
    if (row == 4 && col == 4 && K == 25) {
        c = 1;
    } else {
        c = recurse(row-1, col) + recurse(row+1, col) + recurse(row, col-1) + recurse(row, col+1);
    }
    grass[row][col] = 1;
    K--;
    return c;
    
}

int main() {
    cin >> K;
    for (int i = 0; i<K; i++) {
        int row, col;
        cin >> row >> col;
        grass[row-1][col-1] = 0;
    }

    cout << recurse(0, 0);
}