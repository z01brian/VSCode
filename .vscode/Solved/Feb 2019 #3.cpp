#include <bits/stdc++.h>
using namespace std;

class Segment {
public:
    string type;
    int lower, upper;
};

bool comp(Segment a, Segment b) {
    if (a.lower != b.lower) return a.lower < b.lower;
    return a.upper < b.upper;
}

int main() {
    int N; cin >> N;
    vector<Segment> segments(N);
    int firstNone = -1;
    int lastNone = -1;
    for (int i = 0; i<N; i++) {
        Segment s;
        cin >> s.type >> s.lower >> s.upper;
        segments[i] = s;
        if (firstNone == -1 && s.type == "none") {
            firstNone = i;
        }
        if (s.type == "none") lastNone = max(lastNone, i);
    }

    int frontLower = 0;
    int frontUpper = 99999999;
    for (int i = lastNone; i>=0; i--) {
        if (segments[i].type == "none") {
            frontLower = max(frontLower, segments[i].lower);
            frontUpper = min(frontUpper, segments[i].upper);
        }
        if (segments[i].type == "on") {
            frontLower = max(0, frontLower - segments[i].upper);
            frontUpper -= segments[i].lower;
        }
        if (segments[i].type == "off") {
            frontLower += segments[i].lower;
            frontUpper += segments[i].upper;
        }
    }
    cout << frontLower << " " << frontUpper << "\n";

    int backLower = 0;
    int backUpper = 99999999;
    for (int i = firstNone; i<N; i++) {
        if (segments[i].type == "none") {
            backLower = max(backLower, segments[i].lower);
            backUpper = min(backUpper, segments[i].upper);
        }
        if (segments[i].type == "on") {
            backLower += segments[i].lower;
            backUpper += segments[i].upper;
        }
        if (segments[i].type == "off") {
            backLower = max(0, backLower - segments[i].upper);
            backUpper -= segments[i].lower;
        }
    }
    cout << backLower << " " << backUpper << "\n";


}