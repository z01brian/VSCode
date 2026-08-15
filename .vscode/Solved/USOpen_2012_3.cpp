#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("islands.in", "r", stdin);
    // freopen("islands.out", "w", stdout);

    int N; cin >> N;
    vector<int> heights(N);
    vector<pair<int, int>> index(N);
    for (int i = 0; i<N; i++) {
        cin >> heights[i];
        index[i] = {heights[i], i};
    }
    sort(index.begin(), index.end());
    int islands = 1;
    int maxIslands = 1;

    vector<bool> marked(N);
    for (int i = 0; i<N; i++) {
        int position = index[i].second;
        bool leftWorks = false;
        bool rightWorks = false;
        if (position != 0 && marked[position-1] == false) leftWorks = true;
        if (position != N-1 && marked[position+1] == false) rightWorks = true;

        marked[position] = true;
        if (leftWorks && rightWorks) {
            islands++;
        }
        if (!leftWorks && !rightWorks) {
            islands--;
        }
        if (i + 1 < N && index[i+1].first != index[i].first) {
            maxIslands = max(maxIslands, islands);
        }
    }
    cout << maxIslands;
}