#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> cities(5);
    cities[0] = 0;
    for (int i = 1; i<5; i++) {
        int d; cin >> d;
        cities[i] = cities[i-1] + d;
    }

    for (auto i : cities) {
        for (auto j : cities) {
            cout << abs(j-i) << " ";
        }
        cout << "\n";
    }
}