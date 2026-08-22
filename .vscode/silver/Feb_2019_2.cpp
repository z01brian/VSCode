#include <bits/stdc++.h>
using namespace std;

map<pair<int, bool>, int> activeY; //{y value, in}, freqency
int K;

struct event {
    int x, y1, y2;
    bool in;
};

bool comp(event a, event b) {
    return a.x < b.x;
}

int findOptimalY() {
    if (activeY.empty()) return 0;
    int ans = 0;
    int k = 0;
    int prev = activeY.begin()->first.first;
    for (auto i : activeY) {
        int curr = i.first.first;
        if (k == K) {
            ans += curr - prev;
        }

        if (i.first.second) {
            k += i.second;
        } else {
            k -= i.second;
        }
        prev = curr;
    }
    return ans;
}

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int N; cin >> N >> K;
    vector<event> events;
    for (int i = 0; i<N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, true});
        events.push_back({x2, y1, y2, false});
    }
    sort(events.begin(), events.end(), comp);

    int prevX = events[0].x;
    int areaK = 0;
    for (int i = 0; i<2*N;) {
        int currX = events[i].x;
        int optimalY = findOptimalY();
        areaK += (events[i].x - prevX) * optimalY;

        while (i<2*N && events[i].x == currX) {
            if (events[i].in) {
                activeY[{events[i].y1, true}]++;
                activeY[{events[i].y2, false}]++;
            } else {
                activeY[{events[i].y1, true}]--;
                activeY[{events[i].y2, false}]--;
            }
            i++;
        }
        prevX = currX;
    }
    cout << areaK;
}