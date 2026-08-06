#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int X, Y, M; cin >> X >> Y >> M;
    vector<int> possibleM(M+1, -1);
    possibleM[0] = 0;
    int mMax = 0;
    for (int i = 1; i<=M; i++) {
        int neededX = i-X;
        int neededY = i-Y;
        if ((neededX >= 0 && possibleM[neededX] != -1) || (neededY >= 0 && possibleM[neededY] != -1)) {
            possibleM[i] = i;
            mMax = i;
        }
    }
    cout << mMax;
}