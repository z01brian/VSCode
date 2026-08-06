#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> numFreq;
    vector<int> nums(7);
    for (int i = 0; i<7; i++) {
        int num; cin >> num;
        numFreq[num]++;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i<7; i++) {
        int A = nums[i];
        for (int j = i+1; j<7; j++) {
            int B = nums[j];
            for (int k = j+1; k<7; k++) {
                unordered_map<int, int> freq = numFreq;
                int C = nums[k];
                freq[C]--; freq[A]--; freq[B]--;
                int sol = true;

                if (numFreq[A+B] == 0) {
                    sol = false;
                }
                freq[A+B]--;

                if (numFreq[B+C] == 0) {
                    sol = false;
                }
                freq[B+C]--;

                if (numFreq[A+C] == 0) {
                    sol = false;
                }
                freq[A+C]--;

                if (numFreq[A+B+C] == 0) {
                    sol = false;
                }
                freq[A+B+C]--;

                if (sol) {
                    cout << A << " " << B << " " << C;
                    return 0;
                }
            }
        }
    }
}