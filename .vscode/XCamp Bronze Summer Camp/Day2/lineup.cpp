#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int N; cin >> N;
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());
    vector<vector<string>> commands (N, vector<string>(6));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<6; j++) {
            cin >> commands[i][j];
        }
    }

    do {
        bool sol = true;
        for (int i = 0; i<N; i++) {
            string cow1 = commands[i][0];
            string cow2 = commands[i][5];
            int cow1index, cow2index;
            for (int j = 0; j<cows.size(); j++) {
                if (cows[j] == cow1) {
                    cow1index = j;
                }
                if (cows[j] == cow2) {
                    cow2index = j;
                }
            }
            if (abs(cow1index-cow2index) != 1) sol = false;
        }
        if (sol) {
            for (int i = 0; i<cows.size(); i++) {
                cout << cows[i] << "\n";
                
            }
            return 0;
        }

    } while (next_permutation(cows.begin(), cows.end()));
}