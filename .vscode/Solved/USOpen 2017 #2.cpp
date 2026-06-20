#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> plain(N, vector<char>(M));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> plain[i][j];
        }
    }

    vector<vector<char>> spots(N, vector<char>(M));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> spots[i][j];
        }
    }


    int locations = 0;
    for (int col = 0; col<M; col++) {
        bool possible = true;
        unordered_set<char> duplicates;
        for (int row = 0; row<N; row++) {
            duplicates.insert(plain[row][col]);
        }
        for (int r = 0; r < N; r++) {
            if (duplicates.find(spots[r][col]) != duplicates.end()){
                possible = false;
                break;
            }
        }
        if (possible) {
            locations++;
        }
    }
    cout << locations;
}