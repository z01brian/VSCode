#include <bits/stdc++.h>
using namespace std;

string infected; int N; 

class Handshake {
public:
    int x, y, t;
};

bool comp(Handshake a, Handshake b) {
    return a.t < b.t;
}

bool test(int patient, int K, vector<Handshake>& handshakes) {
    vector<bool> infectedCows(N+1);
    vector<int> shakes(N+1);

    infectedCows[patient] = true;
    for (auto i : handshakes) {
        bool infected1 = infectedCows[i.x];
        bool infected2 = infectedCows[i.y];

        if (infected1 && shakes[i.x] < K) {
            infectedCows[i.y] = true;
            shakes[i.x]++;
        }
        if (infected2 && shakes[i.y] < K) {
            infectedCows[i.x] = true;
            shakes[i.y]++;
        }
    }
    for (int i = 1; i<=N; i++) {
        char c;
        if (infectedCows[i]) {
            c = '1';
        }else {
            c = '0';
        }
        if (c != infected[i-1]) return false;
    }
    return true;
}

int main() {

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int T; cin >> N >> T;

    cin >> infected;

    vector<Handshake> handshakes(T);
    for (int i = 0; i<T; i++) {
        cin >> handshakes[i].t >> handshakes[i].x >> handshakes[i].y;
    }
    sort(handshakes.begin(), handshakes.end(), comp);

    int patients = 0;
    int minK = INT_MAX; int maxK = INT_MIN; bool infinite = false;

    for (int i = 1; i<=N; i++) {
        bool sol = false;

        for (int j = 0; j<=251; j++) {
            if (test(i, j, handshakes)) {
                sol = true;
                minK = min(minK, j);
                if (j == 251) {
                    infinite = true;
                } 
                maxK = max(maxK, j);
            }
        }
        if (sol) patients++;
    }

    cout << patients << " " << minK << " ";
    if (infinite) {
        cout << "Infinity";
        return 0;
    }
    cout << maxK;
}