#include <bits/stdc++.h>
using namespace std;

int main() {
    int row = 0; int col = 0;
    for (int i = 1; i<6; i++) {
        for (int j = 1; j<6; j++) {
            int a; cin >> a;
            if (a == 1) {
                row = i;
                col = j;
                break;
            }
        }
    }
    cout << abs(row - 3) + abs(col - 3);
}