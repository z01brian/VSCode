#include <bits/stdc++.h>
using namespace std;

bool isRightTurn(char initialDir, char finalDir) {
    if (initialDir == 'N') {
        if (finalDir == 'E') return true;
        return false;
    }
    if (initialDir == 'S') {
        if (finalDir == 'W') return true;
        return false;
    }
    if (initialDir == 'W') {
        if (finalDir == 'N') return true;
        return false;
    }
    if (initialDir == 'E') {
        if (finalDir == 'S') return true;
        return false;
    }
    return false;
}

int main() {
    int N; cin >> N;
    vector<string> fence(N);
    for (int i = 0; i<N; i++) {
        cin >> fence[i];
    }

    for (int i = 0; i<N; i++) {
        string s = fence[i];
        char prev = s[0];
        int r = 0; int l = 0;
        for (int j = 1; j<s.size(); j++) {
            if (prev != s[j]) {
                if (isRightTurn(prev, s[j])) {
                    r++;
                } else {
                    l++;
                }
            }
            prev = s[j];
        }
        if (r > l) {
            cout << "CW\n";
        } else {
            cout << "CCW\n";
        }

    }
}