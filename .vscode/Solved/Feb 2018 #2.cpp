#include <bits/stdc++.h>
using namespace std;
int N;

int goTo(int index, vector<int>& cows) {
    if (index == 0) {
        return 1;
    }
    if (index == N-1) {
        return N-2;
    }
    int leftDistance = cows[index] - cows[index-1];
    int rightDistance = cows[index+1] - cows[index];
    if (leftDistance <= rightDistance) {
        return index-1;
    } else {
        return index+1;
    }
}

int main() {
    cin >> N;
    vector<int> cows(N);
    for (int i = 0; i<N; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    vector<int> passesTo(N);
    for (int i = 0; i<N; i++) {
        passesTo[goTo(i, cows)]++;
    }

    int balls = 0;
    for (int i = 0; i<N; i++) {
        if (passesTo[i] == 0) {
            balls++; 
            continue;
        }
        if (i<N-1 && goTo(i, cows) == i+1 && goTo(i+1, cows) == i && passesTo[goTo(i, cows)] == 1 && passesTo[goTo(i+1, cows)] == 1) {
            balls++;
        }
    }
    cout << balls;

}