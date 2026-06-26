#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cows;
    for (int i = 0; i<3; i++) {
        int location;
        cin >> location;
        cows.push_back(location);
    }
    sort(cows.begin(), cows.end());

    if (cows[2] - cows[1] == cows[1]-cows[0] && (cows[1]-cows[0] == 0 || cows[1] - cows[0] == 1) ) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
    cout << max(cows[2] - cows[1], cows[1] - cows[0]) - 1;
}