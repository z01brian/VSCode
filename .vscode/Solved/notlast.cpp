#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    int N; cin >> N; //<100
    map<string, int> cows = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    for (int i = 0; i<N; i++) {
        string name;
        int amt;
        cin >> name >> amt;
        cows[name] += amt;
    }

    vector<pair<string, int>> v(cows.begin(), cows.end());
    sort(v.begin(), v.end(), comp);

    int smallestAmt = v[0].second;

    for (int i = 0; i<N; i++) {
        if (v[i].second == smallestAmt) continue;
        if (i+1 < N && (v[i+1].second != v[i].second)) {
            cout << v[i].first;
            return 0;
        } else {
            break;
        }
    }

    cout << "tie";
    return 0;
}