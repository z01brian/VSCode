#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, minK;
    cin >> N;
    minK = N;
    string mailboxes;
    cin >> mailboxes;

    for (int k = 1; k < N; k++) {
        unordered_set<string> substrings;
        bool solution = true;
        for (int start = 0; start + k - 1 < N; start++) {
            string sub = mailboxes.substr(start, k);
            if (substrings.count(sub)) {
                solution = false;
                break;
            }
            substrings.insert(sub);
        }
        if (solution) {
            cout << k;
            return 0;
        }
    }
    
}