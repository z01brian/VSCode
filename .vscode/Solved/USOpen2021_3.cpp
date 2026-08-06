#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N; cin >> K >> N;
    unordered_map<string, int> names;

    for (int i = 0; i<N; i++) {
        string name;
        cin >> name;
        names[name] = i;
    }

    vector<vector<char>> ans(N, vector<char>(N, '?'));
    for (int i = 0; i<N; i++) {
        ans[i][i] = 'B';
    }

    vector<vector<string>> input(K, vector<string>(N));
    for (int i = 0; i<K; i++) {
        for (int j = 0; j<N; j++) {
            cin >> input[i][j];
        }
    }

    for (int i = 0; i<K; i++) {
        for (int j = 0; j<N; j++) {
            bool inOrder = true;
            for (int k = j+1; k<N; k++) {
                if (input[i][k-1] > input[i][k]) {
                    inOrder = false;
                }
                if (!inOrder) {
                    int x = names[input[i][j]];
                    int y = names[input[i][k]];
                    ans[x][y] = '0';
                    ans[y][x] = '1';
                }
            }
            
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            bool inOrder = true;
            for (int k = j + 1; k < N; k++) {
                if (input[i][k-1]> input[i][k]) {
                    inOrder = false;
                }
                if (!inOrder) {
                    int x = names[input[i][j]];
                    int y = names[input[i][k]];
                    ans[x][y] = '0';
                    ans[y][x] = '1';
                }
            }
        }
    }
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

}