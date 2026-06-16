#include <bits/stdc++.h>
using namespace std;

struct xValue {
    int x, y1, y2;
    bool start; //true means rectangle starts, false means end
};

int yLength(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end());
    int total = 0;
    int curStart = intervals[0].first;
    int curEnd = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;

        if (start > curEnd) { //no overlap
            total += curEnd - curStart;
            curStart = start;
            curEnd = end;
        } else { //yes overlap so we merge the two
            curEnd = max(curEnd, end);
        }
    }

    total += curEnd - curStart;

    return total;
}



int main() {
    int N; cin >> N;
    int area = 0;
    vector<xValue> xValues;

    for (int i = 0; i<N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        xValues.push_back({x1, y2, y1, true});
        xValues.push_back({x2, y2, y1, false});
    }

    vector<pair<int, int>> activeXValues; //a rectangle is active if the sweepline is currently passing through it
    int area = 0;
    int i = 0;
    int prevX = xValues[0].x;

    while (i < xValues.size()) { //i is the line
        int curX = xValues[i].x;
        int width = curX - prevX;
        int height = yLength(activeXValues);

        area += width*height;

        while (i<xValues.size() && xValues[i].x == curX) {
            xValue p = xValues[i];
            if (p.start) { 
                activeXValues.push_back({p.y1, p.y2});
            } else {
                for (int j = 0; j<activeXValues.size(); j++) {
                    if (activeXValues[j].first == p.y1 && activeXValues[j].second == p.y2) {
                        activeXValues.erase(activeXValues.begin()+j);
                    }
                }
            }
            i++;
        }
        prevX = curX; 
    }
    cout << area;

}