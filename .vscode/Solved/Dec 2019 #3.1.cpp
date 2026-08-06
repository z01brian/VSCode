#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    vector<vector<string>> commands(N, vector<string>(6));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<6; j++) {
            cin >> commands[i][j];
        }
    }

    do {
        unordered_map<string, int> pos;
        for (int i = 0; i<8; i++) {
            pos[cows[i]] = i;
        }

        bool sol = true;
        for (int i = 0; i<N; i++) {
            string cow1 = commands[i][0];
            string cow2 = commands[i][5];
            if (!(abs(pos[cow1]-pos[cow2]) == 1)) {
                sol = false;
                break;
            }
        }
        if (sol) {
            for (int i = 0; i<8; i++) {
                cout << cows[i] << "\n";
            }
            return 0;
        }
    } while (next_permutation(cows.begin(), cows.end()));
}