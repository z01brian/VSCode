#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; cin >> K;
    string s; cin >> s;
    vector<char> alphabet(26);
    for (int i = 0; i<26; i++) {
        alphabet[i] = 'A' + i;
    }
    for (int i = 1; i<=s.size(); i++) {
        char c = s[i-1];
        int s = 3 * i + K;
        s = c - s;
        if (s < 65) s+=26;
        cout << alphabet[s - 65];
    }
}