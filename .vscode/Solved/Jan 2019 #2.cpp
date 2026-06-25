#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cows(N);
    for (int i = 0; i<N; i++) {
        cin >> cows[i];
    }
    vector<int> sortedCows(cows.begin(), cows.end());
    sort(sortedCows.begin(), sortedCows.end());

    for (int i = 0; i<N; i++) {
        if (cows == sortedCows) {
            cout << i;
            return 0;
        }
        if (cows[i] == i+1) {
            continue;
        }
        int cow = cows[i];
        cows.erase(cows.begin() + i);
        cows.insert(cows.begin() + cow - 1, cow);
    }
}