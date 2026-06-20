#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int distance = 0;

    int add = 1;
    if (x < y) {
        while (x < y) {
            x += add;
            if (x >= y) {
                distance += y - (x-add);
                break;
            }
            x -= add;
            distance += abs(add*2);
            add *= -2;
        }
    } else {
        while (x > y) {
            x += add;
            if (x <= y) {
                distance += (x-add) - y;
                break;
            }
            x -= add;
            distance += abs(add*2);
            add *= -2;
        }
    }
    cout << distance;
}