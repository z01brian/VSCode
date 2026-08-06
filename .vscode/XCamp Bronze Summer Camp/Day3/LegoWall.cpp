#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int w, h; cin >> w >> h;

    if (w==2) {
        if (h == 1) {
            cout << 1;
            return 0;
        } else if (h == 2) {
            cout << 3;
            return 0;
        }
        //sum starting with 2x1
        ll sum1 = 2;
        int x = h-1;
        bool oneMore = true;
        if (x%2 == 0) oneMore = false;
        if (oneMore) x--;
        while (x > 1) {
            sum1 *= sum1;
            sum1 %= 1000000007;
            x /= 2;
        }
        if (oneMore) sum1 *= 2;

        //sum starting with 2 1x1
        ll sum2 = 2;
        x = h-2;
        oneMore = true;
        if (x%2 == 0) oneMore = false;
        if (oneMore) x--;
        while (x > 1) {
            sum2 *= sum2;
            sum1 %= 1000000007;
            x /= 2;
        }
        if (oneMore) sum2 *= 2;
        sum2 *= h-1;

        cout << (sum1+sum2)%1000000007;
        return 0;
    }
    cout << 1;
    if (h == 2) {

    }
}