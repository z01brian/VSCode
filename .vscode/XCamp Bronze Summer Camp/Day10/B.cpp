#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<vector<vector<bool>>> carved(N, vector<vector<bool>>(N, vector<bool>(N)));
    int ans = 0;
    for (int q = 0; q<Q; q++) {
        int x, y, z; cin >> x >> y >> z;
        carved[x][y][z] = true;
        bool sol = true;
        for (int Z = 0; Z < N; Z++) {
            if (carved[x][y][Z] == false) {
                sol = false;
                break;
            }
        }
        if (sol) ans++;
        sol = true;
        for (int X = 0; X < N; X++) {
            if (carved[X][y][z] == false) {
                sol = false;
                break;
            }
        }
        if (sol) ans++;
        sol = true;
        for (int Y = 0; Y < N; Y++) {
            if (carved[x][Y][z] == false) {
                sol = false;
                break;
            }
        }
        if (sol) ans++;
        sol = true;
        cout << ans << "\n";
    }
}