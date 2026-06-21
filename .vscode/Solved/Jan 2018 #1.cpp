#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2, X1, Y1, X2, Y2;
    cin >> x1 >> y1 >> x2 >> y2 >> X1 >> Y1 >> X2 >> Y2;

    //x: x2 - x1, y: y2 - y1, X: X2 - X1, Y: Y2 - Y1

    int tarp = (x2-x1)*(y2-y1);


    if (X2 >= x2 && X1 <= x1 && Y2 >= y2 && Y1 <= y1) { //completely covered
        tarp = 0;
    } else if (X2 >= x2 && X1 <= x1 && Y2 < y2 && Y2 > y1 && Y1 <= y1) {
        tarp = (x2-x1)*(y2 - Y2);
    } else if (X2 >= x2 && X1 <= x1 && Y1 > y1 && Y1 < y2 && Y2 >= y2) {
        tarp = (x2-x1)*(Y1-y1);
    } else if (Y2 >= y2 && Y1 <= y1 && X1 < x2 && X1 > x1 && X2 >= x2) {
        tarp = (y2-y1)*(X1 - x1);
    } else if (Y2 >= y2 && Y1 <= y1 && X2 < x2 && X2 > x1 && X1 <= x1) {
        tarp = (y2-y1)*(x2 - X2);
    }
    cout << tarp;
}