#include <bits/stdc++.h>
using namespace std;

unordered_set<int> readings;
map<int, int> barn1;
map<int, int> barn2;

void simulate(int barn1curr, int barn2curr, int day) {
    if (day == 6) {
        readings.insert(barn1curr);
        return;
    }
    if (day % 2 == 0) { //barn1 to barn2
        for (auto i : barn1) {
            int amt = i.first;
            if (i.second == 0) continue;
            barn1[amt]--;
            barn2[amt]++;
            simulate(barn1curr - amt, barn2curr + amt, day+1);
            barn1[amt]++;
            barn2[amt]--;
        }
    } else {
        for (auto i : barn2) {
            int amt = i.first;
            if (i.second == 0) continue;
            barn1[amt]++;
            barn2[amt]--;
            simulate(barn1curr + amt, barn2curr - amt, day+1);
            barn1[amt]--;
            barn2[amt]++;
        }
    }
}


int main() {
    // freopen("backforth.in", "r", stdin);
    // freopen("backforth.out", "w", stdout);
    for (int i = 0; i<10; i++) {
        int a; cin >> a;
        barn1[a]++;
    }
    for (int i = 0; i<10; i++) {
        int a; cin >> a;
        barn2[a]++;
    }

    simulate(1000, 1000, 2);
    int x = readings.size();
    cout << readings.size();
    return 0;
    
}