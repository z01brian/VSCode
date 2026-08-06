#include <bits/stdc++.h>
using namespace std;

int N;

char constructMoo(int sideLength, int middleLength, int k) {
    if (sideLength*2 + middleLength < N) {
        return constructMoo(sideLength*2 + middleLength, k+4, k+1);
    }

    if (N > sideLength && N <= sideLength+middleLength) {
        N -= sideLength;
        if (N == 1) return 'm';
        return 'o';
    }

    if (N <= sideLength) {
        return constructMoo((sideLength - (k+2))/2, k+2, k-1);
    }

    if (N > sideLength + middleLength) {
        N -= sideLength + middleLength;
        return constructMoo((sideLength - (k+2))/2, k+2, k-1);
    }

    return 'a';
}

int main() {
    cin >> N;
    char c = constructMoo(0, 3, 0);
    cout << c;
}