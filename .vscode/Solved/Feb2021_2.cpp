#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> points (N);
    for (int i = 0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }


    map<pair<int, int>, int> cows;
    int count = 0;

    for (int i = 0; i<N; i++) {
        pair<int, int> p = points[i];
        cows.insert({p, 0});
        if (cows.find({p.first+1, p.second}) != cows.end()) {
            cows[{p.first+1, p.second}]++;
            cows[p]++;
            if (cows[{p.first+1, p.second}] == 3) count++;
            if (cows[{p.first+1, p.second}] == 4) count--;
        }
        if (cows.find({p.first-1, p.second}) != cows.end()) {
            cows[{p.first-1, p.second}]++;
            cows[p]++;
            if (cows[{p.first-1, p.second}] == 3) count++;
            if (cows[{p.first-1, p.second}] == 4) count--;
        }
        if (cows.find({p.first, p.second+1}) != cows.end()) {
            cows[{p.first, p.second+1}]++;
            cows[p]++;
            if (cows[{p.first, p.second+1}] == 3) count++;
            if (cows[{p.first, p.second+1}] == 4) count--;
        }
        if (cows.find({p.first, p.second-1}) != cows.end()) {
            cows[{p.first, p.second-1}]++;
            cows[p]++;
            if (cows[{p.first, p.second-1}] == 3) count++;
            if (cows[{p.first, p.second-1}] == 4) count--;
        }
        cout << count << "\n";
    }
}