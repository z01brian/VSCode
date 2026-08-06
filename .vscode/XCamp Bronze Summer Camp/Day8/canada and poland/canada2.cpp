#include <bits/stdc++.h>
using namespace std;

int main() {
    string N, M; cin >> N >> M;
    int nEat = 0; int mEat = 0;
    int n = 0; int m = 0;
    while (n < N.size() && m < M.size()) {
        if (N[n] == M[m]) {
            n++;
            m++;
            nEat++;
            mEat++;
            continue;
        } else if (N[n] == 'R') {
            if (M[m] == 'G') {
                m++;
                nEat++;
            } else {
                n++;
                mEat++;
            }
        } else if (N[n] == 'G') {
            if (M[m] == 'B') {
                m++;
                nEat++;
            } else {
                n++;
                mEat++;
            }
        } else if (N[n] == 'B') {
            if (M[m] == 'R') {
                m++;
                nEat++;
            } else {
                n++;
                mEat++;
            }
        } else {
            cout << "wrong";
            break;
        }
    }
    if (n < N.size()) {
        nEat += N.size() - n;
    }
    if (m < M.size()) {
        mEat += M.size() - m;
    }
    cout << nEat << "\n" << mEat;
}