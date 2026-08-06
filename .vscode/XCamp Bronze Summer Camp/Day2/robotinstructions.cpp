#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> numSteps;
int N; int finalX, finalY;
void recurse (int currX, int currY, int index, int steps, vector<pair<int, int>>& commands) {
    if (index == N) {
        if (currX == finalX && currY == finalY) {
            numSteps[steps]++;
        }
        return;
    }
    recurse(currX+commands[index].first, currY + commands[index].second, index+1, steps+1, commands);
    recurse (currX, currY, index+1, steps, commands);
    return;
}   

int main() {

    cin >> N >> finalX >> finalY;

    vector<pair<int, int>> commands(N);
    for (int i = 0; i<N; i++) {
        cin >> commands[i].first >> commands[i].second;
    }
    recurse(0, 0, 0, 0, commands);
    for (int i = 1; i<=N; i++) {
        cout << numSteps[i] << "\n";
    }
}