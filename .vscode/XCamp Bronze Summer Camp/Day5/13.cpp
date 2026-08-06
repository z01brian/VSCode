#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x = 0;
    cin >> n;
    for (int i = 0; i<n; i++) {
        char a, b, c; cin >> a >> b >> c;
        if ((a == '+' && b == '+') || (a == '+' && b == '+') || (b == '+' && c == '+')) {
            x++;
        }
        if ((a == '-' && b == '-') || (a == '-' && b == '-') || (b == '-' && c == '-')) {
            x--;
        }
    }
    cout << x;
}