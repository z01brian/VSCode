#include <bits/stdc++.h>
using namespace std;

struct Cow {
    char dir;
    int x;
    int y;
};

struct Intersection {
    int cow1Index, cow2Index;
    int x, y;
    int time;

    Intersection(int cow1Index, int cow2Index, int x, int y, int time) : cow1Index(cow1Index), cow2Index(cow2Index), x(x), y(y), time(time) {}
};

bool comp(Intersection a, Intersection b) {
    return a.time < b.time;
}

int main() {
    int N; cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i<N; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
    }

    vector<Intersection> intersections;

    for (int i = 0; i<N; i++) {
        Cow cow1 = cows[i];
        for (int j = 0; j<N; j++) {
            Cow cow2 = cows[j];
            if (cow1.dir == cow2.dir) continue;

            pair<int, int> intersection;
            if (cow1.dir == 'E') {
                intersection.second = cow1.y;
            } else {
                intersection.first = cow1.x;
            }
            if (cow2.dir == 'E') {
                intersection.second = cow2.y;
            } else {
                intersection.first = cow2.x;
            }

            int cow1Distance = intersection.first - cow1.x + intersection.second - cow1.y;
            int cow2Distance = intersection.first - cow2.x + intersection.second - cow2.y;

            if (cow1Distance < 0 || cow2Distance < 0) continue;
            
            //Intersections maintain that cow1 was furthest (cow2 reached first so cow1 should stop)
            //Also doesn't add if distance are equal
            if (cow1Distance > cow2Distance) {
                intersections.emplace_back(i, j, intersection.first, intersection.second, max(cow1Distance, cow2Distance));
            }
        }
    }

    sort(intersections.begin(), intersections.end(), comp);

    vector<int> stopped(N, -1);
    
    for (auto i : intersections) {
        int cow1 = i.cow1Index;
        int cow2 = i.cow2Index;

        if (stopped[cow1] != -1) continue;

        int distance;
        if (cows[cow2].dir == 'E') {
            distance = i.x - cows[cow2].x;
        } else {
            distance = i.y - cows[cow2].y;
        }

        if (stopped[cow2] == -1 || stopped[cow2]>distance) {
            stopped[cow1] = i.time;
        }

    }

    for (auto i : stopped) {
        if (i != -1) {
            cout << i << "\n";
        } else {
            cout << "Infinity\n";
        }
    }
}