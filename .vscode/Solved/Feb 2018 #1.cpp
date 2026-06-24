#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int temp = max(a, b);
    a = min(a, b);
    b = temp;

    temp = max(x, y);
    x = min(x, y);
    y = temp;

    int distance = b-a;
    distance = min(distance, abs(a-x) + abs(b-y));
    cout << distance;
}