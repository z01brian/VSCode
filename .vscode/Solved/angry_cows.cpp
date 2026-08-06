#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N; cin >> N;
    vector<int> haybales(N);
    for (int i = 0; i<N; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());

    int count = 0;
    for (int i = 0; i<N; i++) {
        int currCount = 1;
        int rightIndex = i;
        int blast = 1;
        while (rightIndex+1 < N && haybales[rightIndex+1] - haybales[rightIndex] <= blast) {
            int r = rightIndex;
            rightIndex++;
            while (rightIndex+1 < N && haybales[rightIndex+1] - haybales[r] <= blast) {
                rightIndex++;
                currCount++;
            }
            blast++;
            currCount++;
        }
        blast = 1;
        int leftIndex = i;
        while (leftIndex-1 >= 0 && haybales[leftIndex] - haybales[leftIndex-1] <= blast) {
            int l = leftIndex;
            leftIndex--;
            while (leftIndex - 1 >= 0 && abs(haybales[leftIndex-1] - haybales[l]) <= blast) {
                leftIndex--;
                currCount++;
            }
            blast++;
            currCount++;
        }
        count = max(count, currCount);
    }
    cout << count;
}