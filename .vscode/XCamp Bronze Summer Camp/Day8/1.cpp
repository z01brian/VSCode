#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    vector<int> ans;
    for (int i = 0; i<t; i++) {
        int n; cin >> n;
        string s; cin >> s;
        int maxLength = 0;
        for (int j = 0; j<s.size(); j++) {
            if (s[j] == '*') continue;
            int length = 1;
            while (j+1<s.size() && s[j+1] != '*') {
                length++;
            }
            j += length - 1;
            maxLength = max(maxLength, length);
        }
        ans.push_back(maxLength);
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}