#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> flowers(N);
    for (int i = 0; i<N; i++) {
        cin >> flowers[i];
    }
    int count = 0;

    for (int i = 0; i<N; i++) {
        for (int j = i; j<N; j++) {
            unordered_set<int> pedals;
            int sum = 0;
            for (int k = i; k<=j; k++) {
                sum += flowers[k];
                pedals.insert(flowers[k]);
            }
            if (sum % (j-i+1) == 0) {
                int avg = sum / (j-i+1);
                if (pedals.find(avg) != pedals.end()) count++;
            } 
        }
    }
    cout << count;
}