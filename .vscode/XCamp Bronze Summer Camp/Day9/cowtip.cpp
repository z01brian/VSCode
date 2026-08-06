#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i<N; i++) {
        string s; cin >> s;
        for (int j = 0; j<N; j++) {
            grid[i][j] = s[j] - 48;
        }
    }

    int numTips = 0;
    bool tip = false; // if false search for furthest 1 if true search for furthest 0
    int furthestX = -1; int furthestY = -1;
    
    while (true) {
        int furthestX = -1; int furthestY = -1;
        if (tip) {
            for (int i = N-1; i>=0; i--) {
                for (int j = N-1; j>=0; j--) {
                    if (grid)
                }
            }
        }
    }

}