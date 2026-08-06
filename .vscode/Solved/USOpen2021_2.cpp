#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(M));
    vector<pair<int, int>> grassSquares;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> markedGrass(N, vector<bool>(M));
    set<pair<pair<int, int>, pair<int, int>>> friends;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            if (grid[i][j] == 'G') {
                vector<pair<int, int>> adj;
                if (i+1 < N && grid[i+1][j] == 'C') adj.push_back({i+1, j});
                if (i-1 >= 0 && grid[i-1][j] == 'C') adj.push_back({i-1, j});
                if (j+1 < M && grid[i][j+1] == 'C') adj.push_back({i, j+1});
                if (j-1 >= 0 && grid[i][j-1] == 'C') adj.push_back({i, j-1});
                sort(adj.begin(), adj.end());

                if (adj.size() <= 2) {
                    if (adj.size() == 2) {
                        friends.insert({adj[0], adj[1]});
                    }
                    markedGrass[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            if (grid[i][j] == 'G' && markedGrass[i][j] == false) {
                vector<pair<int, int>> adj;
                if (i+1 < N && grid[i+1][j] == 'C') adj.push_back({i+1, j});
                if (i-1 >= 0 && grid[i-1][j] == 'C') adj.push_back({i-1, j});
                if (j+1 < M && grid[i][j+1] == 'C') adj.push_back({i, j+1});
                if (j-1 >= 0 && grid[i][j-1] == 'C') adj.push_back({i, j-1});
                sort(adj.begin(), adj.end());

                bool found = false;
                for (int a = 0; a<adj.size(); a++) {
                    for (int b = a+1; b<adj.size(); b++) {
                        if (friends.insert({adj[a], adj[b]}).second) {
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
        }
    }
    cout << friends.size();




}