#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> seen;
    for (int i = 2; i<n; i++) {
        bool prime = true;
        for (int j = 0; j<seen.size(); j++) {
            if (i%seen[j] == 0) prime = false;
        }
        if (prime) cout << i << " ";
        seen.push_back(i);
    }
}