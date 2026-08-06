#include <bits/stdc++.h>
using namespace std;


int main() {
    long long N, finalX, finalY;
    cin >> N >> finalX >> finalY;

    vector<pair<int, int>> commandsLeft(N/2);
    vector<pair<int, int>> commandsRight(N-N/2);
    for (int i = 0; i<N/2; i++) {
        cin >> commandsLeft[i].first >> commandsLeft[i].second;
    }
    for (int i = 0; i<N-N/2; i++) {
        cin >> commandsRight[i].first >> commandsRight[i].second;
    }

    map<pair<int, int>, vector<int>> left; //pair stores x, y; int stores count

    for (int i = 0; i < (1<<(N/2)); i++) {
        int currX = 0; int currY = 0; int time = 0;
        for (int j = 0; j<N/2; j++) {
            if (i & (1<<j)) {
                currX += commandsLeft[j].first;
                currY += commandsLeft[j].second;
                time++;
            }
        }
        if (left.count({currX, currY}) == 0) {
            left[{currX, currY}].resize(N+1);
        }
        left[{currX, currY}][time]++;
    }

    unordered_map<int, int> sol;
    for (int i = 0; i < (1<<(N-N/2)); i++) {
        int currX = 0; int currY = 0; int time = 0;
        for (int j = 0; j<N-N/2; j++) {
            if (i & (1<<(j))) {
                currX += commandsRight[j].first;
                currY += commandsRight[j].second;
                time++;
            }
        }
        int neededX = finalX - currX; int neededY = finalY - currY;
        if (left.find({neededX, neededY}) != left.end()) {
            for (int i = 1; i<=N; i++) {
                sol[i] += left[{neededX, neededY}][i];
            }
        }
    }
    for (int i = 1; i<=N; i++) {
        cout << sol[i] << "\n";
    }


}