#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int N;
    cin >> N;
    string stalls;
    cin >> stalls;

    int distance1 = 0; int distance2 = 0;
    for (int i = 0; i<N; i++) {
        if (stalls[i] == '1') continue;

        int currDistance = 1;
        while (i+1 < N && stalls[i+1] == '0') {
            i++;
            currDistance++;
        }
        if (currDistance >= distance1) {
            distance2 = distance1;
            distance1 = currDistance;
        } else if (currDistance > distance2) {
            distance2 = currDistance;
        }
    }

    int edge1 = 0; int edge2 = 0;
    for (int i = -1; i<N; i++) {
        while (i+1<N && stalls[i+1] == '0') {
            i++;
            edge1++;
        }
        break;
    }
    for (int i = N; i>=0; i++) {
        while (i-1 >= 0 && stalls[i-1] == '0') {
            i--;
            edge2++;
        }
        break;
    }
    if (edge1 > 0 && edge2 > 0) {
        distance1 = max(distance1, max(edge1, edge2));
        distance2 = max(distance2, min(edge1, edge2));
    } else if (edge1 > 0) {
        distance1 = max(distance1, edge1);
    } else if (edge2 > 0) {
        distance1 = max(distance1, edge2);
    }

    int maxDistance1;
    //both cows in distance1
    if (distance1 % 2 == 1) {
        maxDistance1 = (distance1-2)/2 + 1;
    } else if (distance1 != 2) {
        maxDistance1 = (distance1-2)/2 + 1;
    } else {
        maxDistance1 = 1;
    }

    //one cow in distance1, one in distance2
    int maxDistance2;
    if (distance2 % 2 == 1) {
        maxDistance2 = (distance2-1)/2 + 1;
    } else {
        maxDistance2 = distance2/2;
    }

    int minDistance = max(maxDistance1, maxDistance2);
    cout << minDistance;

}