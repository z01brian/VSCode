#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("moobuzz.in", "r", stdin);
    // freopen("moobuzz.out", "w", stdout);

    int N; cin >> N;
    int div = N/8;
    int rem = N%8;
  
    for (int i = 1; i<=15; i++) {
        if ((i%3 == 0 || i%5 == 0) && rem >=i) rem++;
    }
    if (rem == 0) {
        cout << 15*(div-1) + 14;
        return 0;
    }
    cout << div*(15)+rem;
}