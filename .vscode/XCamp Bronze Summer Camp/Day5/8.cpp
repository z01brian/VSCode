#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int amt = 0;
    for (int i = 0; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        int count = 0;
        if (a == 1) count++;
        if (b == 1) count++;
        if (c == 1) count++;
        if (count >= 2) {
            amt++;
        }
    }
    cout << amt;
}