#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cows(N);
    unordered_set<int> uniqueIDS;


    for (int i = 0; i<N; i++) {
        int ID; cin >> ID;
        cows[i] = ID;
        uniqueIDS.insert(ID);
    }

    int maxCount = 0;
    for (auto ID : uniqueIDS) {
        int currID = -1;
        int currCount = 0;
        for (int j = 0; j<N; j++) {
            if (cows[j] == ID) continue;
            if (currID == -1) {
                currID = cows[j];
                currCount++;
            }

            while (j+1<N && (cows[j+1] == currID || cows[j+1] == ID)) {
                if (cows[j] == ID) {
                    j++;
                    continue;
                }
                currCount++;
                j++;
            }


            maxCount = max(maxCount, currCount);
            currCount = 0;
            currID = -1;
        }
    }

    cout << maxCount;
}