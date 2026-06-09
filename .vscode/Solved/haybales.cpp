#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> piles(N);
    int sum = 0;

    for (int i = 0; i<N; i++) {
        cin >> piles[i];
        sum += piles[i];
    }

    int avg = sum/N;
    int moves = 0;
    
    for (auto i : piles) {
        if (i > avg) {
            moves += i-avg;
        }
    }

    cout << moves;
    
} //O(N) baseline, solution is O(N)