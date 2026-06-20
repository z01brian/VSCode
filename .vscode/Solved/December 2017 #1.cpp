#include <bits/stdc++.h>
using namespace std;

class Board {
public:
    int x1, y1, x2, y2;
};

int main() {
    Board b1, b2, t;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;


    int area = (b1.x2 - b1.x1)*(b1.y2 - b1.y1) + (b2.x2 - b2.x1)*(b2.y2 - b2.y1);

    int overlap1X = max(0, min(b1.x2, t.x2) - max(b1.x1, t.x1));
    int overlap1Y = max(0, min(b1.y2, t.y2) - max(b1.y1, t.y1));
    int overlap2X = max(0, min(b2.x2, t.x2) - max(b2.x1, t.x1));
    int overlap2Y = max(0, min(b2.y2, t.y2) - max(b2.y1, t.y1));

    area = area - (overlap1X * overlap1Y + overlap2X * overlap2Y);
    cout << area;
}