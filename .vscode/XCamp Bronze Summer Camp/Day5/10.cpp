#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int amt = 0;
    for (int i = 0; i<s.size(); i++) {
        char curr = s[i];
        while (i+1 < s.size() && s[i+1] == curr) {
            i++;
            amt++;
        }
    }
    cout << amt;
}