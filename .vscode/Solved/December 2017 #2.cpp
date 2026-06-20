#include <bits/stdc++.h>
using namespace std;

int N;

void backtrack(vector<int>& shuffle, vector<int>& positions) {
    vector<int> newPositions(N);

    for (int i = 0; i<N; i++) {
        newPositions[i] = positions[shuffle[i]-1];
    }
    positions = newPositions;
}


int main() {
    cin >> N;
    vector<int> shuffle(N);
    for (int i = 0; i<N; i++) {
        cin >> shuffle[i];
    }

    vector<int> positions(N);
    for (int i = 0; i<N; i++) {
        cin >> positions[i];
    }

    backtrack(shuffle, positions);
    backtrack(shuffle, positions);
    backtrack(shuffle, positions);

    for (int i = 0; i<N; i++) {
        cout << positions[i] << "\n";
    }


}