#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll N;
string s; 

char simulate(ll currLength, ll n) {
    if (n <= s.size()) {
        return s[n-1];
    }

    ll nextN;
    if (n == currLength/2 + 1) {
        nextN = currLength/2;
    } else if (n <= currLength/2) {
        return simulate(currLength/2, n);
    } else {
        nextN = n - currLength/2 - 1;
    }
    return simulate(currLength / 2, nextN);
}

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    cin >> s;
    cin >> N;
    ll currLength = s.size();
    while (currLength<N) currLength*=2;
    cout << simulate(currLength, N);
}