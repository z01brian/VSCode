#include <bits/stdc++.h>  
using namespace std;

int main() {
    string a, b; cin >> a >> b;

    for (int i = 0; i<a.size(); i++) {
        int c1 = tolower(a[i]);
        int c2 = tolower(b[i]);
        if (c1<c2) {
            cout << -1;
            return 0;
        }
        if (c1>c2) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}