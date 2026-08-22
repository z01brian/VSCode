#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int N;
int currX;

struct Point {
    ll x, y; 
    int segID;
};

struct Segment {
    Point point1, point2;
    int id;
};

bool comp(Point a, Point b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

long double segmentY(Segment a) { //find current Y segment
    if (a.point1.x == a.point2.x) {
        return a.point1.y;
    }
    long double slope = (long double)(a.point1.y - a.point2.y)/(a.point1.x - a.point2.x);
    return a.point1.y + (currX - a.point1.x)*(slope);
}

bool segmentCompare(Segment a, Segment b) {
    long double aY = segmentY(a);
    long double bY = segmentY(b);
    
    if (aY != bY) {
        return aY < bY;
    }
    return a.id < b.id; 
}

ll crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); //negative is left, positive is right, equal is on
}

bool intersect(Segment a, Segment b) {
    if (min(max(a.point1.y, a.point2.y), max(b.point1.y, b.point2.y)) < max(min(a.point1.y, a.point2.y), min(b.point1.y, b.point2.y))) {
        return false;
    }

    ll cross1 = crossProduct(a.point1, a.point2, b.point1);
    ll cross2 = crossProduct(a.point1, a.point2, b.point2);
    ll cross3 = crossProduct(b.point1, b.point2, a.point1);
    ll cross4 = crossProduct(b.point1, b.point2, a.point2);

    if (cross1 * cross2 <= 0 && cross3 * cross4 <= 0) return true;
    return false;
}

int main() {
    freopen("cowjump.in", "r", stdin);
    freopen("cowjump.out", "w", stdout);

    cin >> N;
    vector<Segment> segments(N);
    vector<Point> points;
    for (int i = 0; i<N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point p1 = {x1, y1, i};
        Point p2 = {x2, y2, i};
        if (comp(p2, p1)) swap(p1, p2);

        segments[i] = {p1, p2, i};
        points.push_back(p1);
        points.push_back(p2);
    }
    sort(points.begin(), points.end(), comp);
    

    set<Segment, decltype(&segmentCompare)> active(segmentCompare);
    int intersect1 = -1; int intersect2 = -1;

    for (auto i : points) {
        currX = i.x;
        int segmentID = i.segID;
        auto it = active.find(segments[segmentID]);
        
        if (it == active.end()) { // incoming point
            auto next = active.lower_bound(segments[segmentID]);

            if (next != active.end()) {
                int neighborSegment = next->id;
                if (intersect(segments[segmentID], segments[neighborSegment])) {
                    intersect1 = segmentID;
                    intersect2 = neighborSegment;
                    break;
                }
            }

            if (next != active.begin()) {
                auto previous = prev(next);
                int neighborSegment = previous->id;
                if (intersect(segments[segmentID], segments[neighborSegment])) {
                    intersect1 = segmentID;
                    intersect2 = neighborSegment;
                    break;
                }
            }
            active.insert(segments[segmentID]);

        } else {
            auto next = std::next(it);
            if (it != active.begin() && next != active.end()) {
                auto previous = prev(it);
                if (intersect(segments[previous->id], segments[next->id])) {
                    intersect1 = previous->id;
                    intersect2 = next->id;
                    break;
                }
            }
            active.erase(it);
        }
    }

    int totalIntersections1 = 0;
    int totalIntersections2 = 0;
    for (int i = 0; i<N; i++) {
        if (i != intersect1 && intersect(segments[intersect1], segments[i])) totalIntersections1++;
        if (i != intersect2 && intersect(segments[intersect2], segments[i])) totalIntersections2++;
    }
    
    if (totalIntersections1 > 1) {
        cout << intersect1 + 1;
    } else if (totalIntersections2 > 1) {
        cout << intersect2 + 1;
    } else {
        cout << min(intersect1, intersect2) + 1;
    }
}