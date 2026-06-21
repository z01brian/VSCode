#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> cows(N);
    int bessieIndex;

    for (int i = 0; i<N; i++) {
        cin >> cows[i];
        if (i >= 1 && cows[i] < cows[i-1]) {
            bessieIndex = i;
        }
    }

    int swaps = 0;
    while (bessieIndex >= 0 && cows[bessieIndex-1] > cows[bessieIndex]) {
        int swapIndex = bessieIndex-1;
        while (swapIndex >= 0 && cows[swapIndex] == cows[swapIndex-1]) {
            swapIndex--;
        }
        int temp = cows[swapIndex];
        cows[swapIndex] = cows[bessieIndex];
        cows[bessieIndex] = temp;
        bessieIndex = swapIndex;
        swaps++;
    }

    cout << swaps;
}