#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int K;
bool sol(ll R, vector<ll> haybales) {
    ll currPos = haybales.front();
    int i = 1;
    while (i <= K) {
        auto it = upper_bound(haybales.begin(), haybales.end(), currPos + (2 * R));
        if (it == haybales.end()) return true;
        currPos = *it;
        i++;
    }
    return false;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N; cin >> N >> K;

    vector<ll> haybales(N);
    for (int i = 0; i<N; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());

    ll left = 0; ll right = haybales.back() - haybales.front();
    while (left < right) {
        ll middle = (left + right)/2;
        if (sol(middle, haybales)) {
            right = middle;
        } else {
            left = middle+1;
        }
    }
    cout << left;
}