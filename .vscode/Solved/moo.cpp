#include <bits/stdc++.h>
using namespace std;



string calculateMoo(int digit, int currDigits, string currMoo, int k) {
    if (currDigits > digit) {
        return currMoo;
    }


    string middleMoo = "m";
    for (int i = 0; i<k+2; i++) {
        middleMoo += "o";
    }
    string newMoo = currMoo + middleMoo + currMoo;
    return calculateMoo(digit, newMoo.size(), newMoo, k+1);
}

int main() {
    int N; cin >> N;

    string moo = calculateMoo(N, 3, "moo", 1);
    cout << moo[N-1];
}