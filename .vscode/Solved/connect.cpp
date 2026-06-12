#include <bits/stdc++.h>
using namespace std;

int N;
int routes;

bool dir(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first || p1.second == p2.second) {
        return true;
    }
    return false;
}

void permutation(vector<pair<int, int>>& cords) {
    sort(cords.begin(), cords.end());
    do {
        bool solution = true;
        for (int i = 0; i<N+1; i++) {
            pair<int, int> start;
            pair<int, int> end;

            if (i == 0) {
                start = {0, 0};
            } else {
                start = cords[i-1];
            }

            if (i == N) {
                end = {0, 0};
            } else {
                end = cords[i];
            }

            if (!dir(start, end)) {
                solution = false;
                break;
            }
        }
        if (solution) routes++; 

    } while (next_permutation(cords.begin(), cords.end()));
}

int main() { //find permutations and check if they work
    cin >> N;
    vector<pair<int, int>> cords(N);
    for (int i = 0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        cords[i] = {x, y};
    }

    permutation(cords);
    cout << routes;
}