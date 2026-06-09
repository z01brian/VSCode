#include <bits/stdc++.h>
using namespace std;

int main() {
    int D, H, M;
    cin >> D >> H >> M;
    int mins = 0;

    mins += M - 11;
    mins += 60*(H-11);
    mins += 24*60*(D-11);

    if (mins >= 0) {
        cout << mins;
    } else {
        cout << -1;
    }


    //11/11/11 11:11 am
}