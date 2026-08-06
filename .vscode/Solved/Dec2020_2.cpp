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
            unordered_set<double> nums;
            int sum = 0;
            for (int k = i; k<=j; k++) {
                sum += flowers[k];
                nums.insert(flowers[k]);
            }
            double avg = static_cast<double>(sum) / (j-i+1);
            if (nums.find(avg) != nums.end()) count++;
        }
    }
    cout << count;
}