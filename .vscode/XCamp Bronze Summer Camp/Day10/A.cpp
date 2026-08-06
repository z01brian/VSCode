#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int T; cin >> T;

    while (T-- > 0) {
        ll N; cin >> N;
        ll ans = 0;
        ll startCount = 45;
        ll powerOf10 = 10;

        while(startCount <= N) {
            ans += min(N, 5*powerOf10 - 1)-startCount+1;
            startCount = startCount*10 - 5;
            powerOf10 *= 10;
        }
        cout << ans << '\n';
    }
}