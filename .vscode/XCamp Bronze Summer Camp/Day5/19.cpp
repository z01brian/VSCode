#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<string> ans;
    for (int i = 0; i<t; i++) {
        int n; cin >> n;
        vector<int> nums1(n);
        int maxNums1 = 0;
        for (int j = 0; j<n; j++) {
            cin >> nums1[i];
            if (nums1[i] > nums1[maxNums1]) {
                maxNums1 = i;
            }
        }

        vector<int> nums2(n);
        int maxNums2 = 0;
        for (int j = 0; j<n; j++) {
            cin >> nums2[i];
            if (nums2[i] > nums2[maxNums2]) {
                maxNums1 = i;
            }
        }

        if (maxNums1 == n && maxNums2 == n) {

        }
        



    }
}