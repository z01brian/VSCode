#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> nums(N);
    unordered_map<int, int> marked;
    for (int i = 0; i<N; i++) {
        cin >> nums[i];
        int y = X - nums[i];
        if (marked.count(y)) {
            cout << marked[y] << " " << i;
            return 0;
        }
        marked.insert({nums[i], i});
    }
    cout << -1;
    return 0;


    
}