#include <bits/stdc++.h>
using namespace std;
int counter = 0;
int n, m;

void recurse(int currRow, int currCol) {
    if (currRow == n && currCol == m) {
        counter++;
        return;
    }
    if (currRow < n) {
        recurse(currRow+1, currCol);
    }
    if (currCol < m) {
        recurse(currRow, currCol+1);
    }
}

int main() {
    cin >> n >> m;
    recurse(0, 0);
    cout << counter;

}