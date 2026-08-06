#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    vector<bool> marked(8);
    unordered_map<string, int> cowPos;
    for (int i = 0; i<8; i++) {
        cowPos[cows[i]] = i;
    }
    vector<vector<string>> commands(N, vector<string>(6));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<6; j++) {
            cin >> commands[i][j];
        }
    }

    for (int i = 0; i<N; i++) {
        string cow1 = commands[i][0];
        string cow2 = commands[i][5];
        if (cowPos[cow1] - 1 >= 0 && !marked[cowPos[cow1]-1]) {
            string change = cows[cowPos[cow1]-1];

            swap(cows[cowPos[cow2]], cows[cowPos[cow1]-1]);
            marked[cowPos[cow2]] = true; marked[cowPos[cow1]-1] = true;

            int temp = cowPos[cow2];
            cowPos[cow2] = cowPos[cow1]-1;
            cowPos[change] = temp;
        } else {
            string change = cows[cowPos[cow1]+1];

            swap(cows[cowPos[cow2]], cows[cowPos[cow1]+1]);
            marked[cowPos[cow2]] = true; marked[cowPos[cow1]+1] = true;

            int temp = cowPos[cow2];
            cowPos[cow2] = cowPos[cow1]+1;
            cowPos[change] = temp;
        }
    }

    unordered_map<string, string> groups;
    set<string> orderedCows;
    for (int i = 0; i<8; i++) {
        if (!marked[i]) {
            orderedCows.insert(cows[i]);
            groups[cows[i]] = cows[i] + "\n";
            continue;
        }
        int index = i;
        while (index+1 < 8 && marked[index+1]) {
            index++;
        }
        if (index-i == 1) {
            sort(cows.begin()+i, cows.begin()+index+1);
            orderedCows.insert(cows[i]);
            groups[cows[i]] = cows[i] + "\n" + cows[index] + "\n";
        } else {
            orderedCows.insert(cows[i]);
            for (int j = i; j<=index; j++) {
                groups[cows[i]] += cows[j] + "\n";
            }
        }
        i = index;
    }

    for (auto cow : orderedCows) {
        cout << groups[cow];
    }
}