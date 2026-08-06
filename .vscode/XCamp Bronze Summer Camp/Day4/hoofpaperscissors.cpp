#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N; cin >> N;
    vector<char> FJmoves(N);
    for (int i = 0; i<N; i++) {
        cin >> FJmoves[i];
    }

    vector<vector<int>> bessie (N+1, vector<int>(3)); //H P S
    bessie[0] = {0, 0, 0};
    for (int i = 0; i<N; i++) {
        bessie[i+1] = bessie[i];
        if (FJmoves[i] == 'H') {
            bessie[i+1][1]++;
        } else if (FJmoves[i] == 'P') {
            bessie[i+1][2]++;
        } else {
            bessie[i+1][0]++;
        }
    }

    int maxWins = 0;
    for (int i = 0; i<N+1; i++) { //i is where the cut is made/ the swap
        char left; int leftMax; int secondLeftMax;
        if (bessie[i][0] >= bessie[i][1] && bessie[i][0] >= bessie[i][2]) {
            left = 'H';
            leftMax = bessie[i][0];
            secondLeftMax = max(bessie[i][1], bessie[i][2]);
        } else if (bessie[i][1] >= bessie[i][0] && bessie[i][1] >= bessie[i][2]) {
            left = 'P';
            leftMax = bessie[i][1];
            secondLeftMax = max(bessie[i][0], bessie[i][2]);
        } else {
            left = 'S';
            leftMax = bessie[i][2];
            secondLeftMax = max(bessie[i][0], bessie[i][1]);
        }
        char right; int rightMax; int secondRightMax;
        if (bessie[N][0] - bessie[i][0] >= bessie[N][1] - bessie[i][1] && bessie[N][0] - bessie[i][0] >= bessie[N][2] - bessie[N][2]) {
            right = 'H';
            rightMax = bessie[N][0] - bessie[i][0];
            secondRightMax = max(bessie[N][1] - bessie[i][1], bessie[N][2] - bessie[i][2]);
        } else if (bessie[N][1] - bessie[i][1] >= bessie[N][0] - bessie[i][0] && bessie[N][1] - bessie[i][1] >= bessie[N][2] - bessie[N][2]) {
            right = 'P';
            rightMax = bessie[N][1] - bessie[i][1];
            secondRightMax = max(bessie[N][0] - bessie[i][0], bessie[N][2] - bessie[i][2]);
        } else {
            left = 'S';
            leftMax = bessie[i][2];
            secondRightMax = max(bessie[N][1] - bessie[i][1], bessie[N][0] - bessie[i][0]);
        }

        if (right == left) {
            if (leftMax == rightMax) {
                if (secondLeftMax > secondRightMax) {
                    leftMax = secondLeftMax;
                } else {
                    rightMax = secondRightMax;
                }
            } else {
                maxWins = max(maxWins, max(leftMax + secondRightMax, rightMax + secondLeftMax));
            }
        }
        maxWins = max(maxWins, leftMax + rightMax);
    }
    cout << maxWins;
}