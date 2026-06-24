#include <bits/stdc++.h>
using namespace std;

int main() {
    int bCap, bCurr, eCap, eCurr, mCap, mCurr;
    cin >> bCap >> bCurr >> eCap >> eCurr >> mCap >> mCurr;

    for (int i = 0; i<33; i++) {
        eCurr += bCurr;
        if (eCurr > eCap) {
            bCurr = eCurr - eCap;
            eCurr = eCap;
        } else {
            bCurr = 0;
        }

        mCurr += eCurr;
        if (mCurr > mCap) {
            eCurr = mCurr - mCap;
            mCurr = mCap;
        } else {
            eCurr = 0;
        }

        bCurr += mCurr;
        if (bCurr > bCap) {
            mCurr = bCurr - bCap;
            bCurr = bCap;
        } else {
            mCurr = 0;
        }
    }
    eCurr += bCurr;
    if (eCurr > eCap) {
        bCurr = eCurr - eCap;
        eCurr = eCap;
    } else {
        bCurr = 0;
    }
    cout << bCurr << "\n" << eCurr << "\n" << mCurr << "\n";

}