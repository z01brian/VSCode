#include <bits/stdc++.h>
using namespace std;

class Board {
public:
    int x1, y1, x2, y2;
};
class xValue {
public:
    int x, y1, y2;
    bool block;

    xValue(int x, int y1, int y2, bool block) {
        this->x = x;
        this->y1 = y1;
        this->y2 = y2;
        this->block = block;
    }
};

bool comp(xValue a, xValue b) {
    return a.x < b.x;
}

int main() {
    Board b1, b2, t;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    vector<xValue> xValues;
    xValues.push_back(xValue(b1.x1, b1.y1, b1.y2, false));
    xValues.push_back(xValue(b1.x2, b1.y1, b1.y2, false));
    xValues.push_back(xValue(b2.x1, b2.y1, b2.y2, false));
    xValues.push_back(xValue(b2.x2, b2.y1, b2.y2, false));
    xValues.push_back(xValue(t.x1, t.y1, t.y2, true));
    xValues.push_back(xValue(t.x2, t.y1, t.y2, true));
    sort(xValues.begin(), xValues.end(), comp);

    int area = (b1.x2 - b1.x1)*(b1.y2 - b1.y1) + (b2.x2 - b2.x1)*(b2.y2 - b1.y1);

    int i = 0;
    bool truck = false;
    int xPrev = xValues[0].x;
    while (i < xValues.size()) {
        int curX = xValues[i].x;
        if (truck == false) {
            truck = xValues[i].block;
            i++;
            xPrev = curX;
        }

        //calculate area to subtract
        int length = curX - xPrev;
        // int height = max(0, min(xValues[i].y2, xValues)



    }

    
}