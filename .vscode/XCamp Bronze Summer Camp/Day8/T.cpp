#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll t; cin >> t;
    vector<string> ans;
    while (t-->0) {
        ll n; cin >>n;
        vector<pair<ll, ll>> dominoes(n);
        for (ll i = 0; i<n; i++) {
            cin >> dominoes[i].first >> dominoes[i].second;
        }

        unordered_map<ll, ll> group1, group2;
        bool sol = true;
        for (auto i : dominoes) {
            if (i.first == i.second) {
                sol = false;
                break;
            }
            if (group1[i.first] == 0 && group1[i.second] == 0) {
                group1[i.first]++; group1[i.second]++;
            } else {
                group2[i.first]++; group2[i.second]++;
            }
        }
        for (auto i : group1) {
            if (i.second > 1) sol = false;
        }
        for (auto i : group2) {
            if (i.second > 1) sol = false;
        }
        if (sol) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}