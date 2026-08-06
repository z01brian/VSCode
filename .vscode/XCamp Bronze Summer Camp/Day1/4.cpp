#include <bits/stdc++.h>
using namespace std;

int sharedArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int left, right, top, bottom;
    left = max(ax1, bx1);
    right = min(ax2, bx2);
    bottom = max(ay1, by1);
    top = min(ay2, by2);
    if (left < right && bottom < top) {
        return (right-left)*(top-bottom);
    }
    return 0;
}

int main() {
    int bx1, by1, bx2, by2;
    int Bx1, By1, Bx2, By2;
    int tx1, ty1, tx2, ty2;
    cin >> bx1 >> by1 >> bx2 >>by2 >> Bx1 >> By1 >> Bx2 >> By2 >> tx1 >> ty1 >> tx2 >> ty2;

    bool overlap = false;
    int Oleft = max(Bx1, bx1);
    int Oright = min(Bx2, bx2);
    int Obottom = max(By1, by1);
    int Otop = min(By2, by2);
    if (Oleft < Oright && Obottom < Otop) {
        overlap = true;
    }


    int area = (bx2-bx1)*(by2-by1) + (Bx2 - Bx1) * (By2 - By1);
    area -= sharedArea(bx1, by1, bx2, by2, Bx1, By1, Bx2, By2); // subtract overlap
    if (overlap) {
        area += sharedArea(Oleft, Oright, Obottom, Otop, tx1, ty1, tx2, ty2);
    }
    area -= sharedArea(bx1, by1, bx2, by2, tx1, ty1, tx2, ty2);
    area -= sharedArea(Bx1, By1, Bx2, By2, tx1, ty1, tx2, ty2);
    cout << area;

}