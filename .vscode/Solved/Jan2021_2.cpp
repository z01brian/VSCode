#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> nums(N);

    int odd = 0; int even = 0;
    for (int i = 0; i<N; i++) {
        cin >> nums[i];
        if (nums[i]%2==0) {
            even++;
        } else {
            odd++;
        }
    }

    while (odd > even && odd >=2) {
        odd -=2;
        even++;
    }
    if (even > odd + 1) {
        even = odd + 1;
    }
    cout << even + odd;




}