#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    // freopen("running.in", "r", stdin);
    // freopen("running.out", "w", stdout);

    ll N, L, C;
    cin >> N >> L >> C;

    vector<ll> speed(N, -1);
    for (ll i = 0; i<N; i++) {
        cin >> speed[i];
    }
    sort(speed.begin(), speed.end());

    vector<ll> distanceOnFastest(N);
    for (ll i = 0; i < N; i++) {
        distanceOnFastest[i] = L * C * speed[i];
    }

    // ll scaledLap = C * speed.back();


    ll overlaps = 0;
    ll prevOverlaps = 0;
    for (ll i = 1; i<N; i++) {
        ll currOverlaps = prevOverlaps + ((distanceOnFastest[i]/(speed.back()*C) - distanceOnFastest[i-1]/(speed.back()*C) ) * i);
        overlaps += currOverlaps;
        prevOverlaps = currOverlaps;
    }

    vector<ll> extra(N);
    for (ll i = 0; i<N; i++) {
        extra[i] = distanceOnFastest[i]/(speed.back()*C) %C;
    }

    vector<ll> temp = extra;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    vector<ll> compressed(N);
    for (ll i = 0; i<N; i++) {
        compressed[i] = lower_bound(temp.begin(), temp.end(), extra[i]) - temp.begin() + 1;
    }

    vector<ll> fenwickTree(temp.size()+1);
    for (ll i = 0; i<N; i++) {
        ll less = 0;
        for (ll j = compressed[i]; j>=1; j -= (j & -j)) {
            less += fenwickTree[j];
        }
        ll more = i - less;
        overlaps -= more;
        for (ll j = compressed[i]; j<=temp.size(); j += (j & -j)) {
            fenwickTree[j]++;
        }
    }
    cout << overlaps;
}