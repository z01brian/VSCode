#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    vector<int> alphabet(26);
    for (int i = 0; i<s.size(); i++) {
        char c = s[i];
        alphabet[c-'A']++;
    }

    int maxAmt = 0;
    for (int i = 0; i<26; i++) {
        maxAmt = max(maxAmt, alphabet[i]);
    }
    if (maxAmt > (s.size()+1)/2) {
        cout << -1;
        return 0;
    }

    int prevIndex = -1;
    for (int i = s.size()-1; i>=0; i--) {
        int maxAmt = 0;
        int maxIndex = 0;
        for (int j = 0; j<26; j++) {
            if (alphabet[j] > maxAmt) {
                maxAmt = alphabet[j];
                maxIndex = j;
            }
        }
        int character = -1;
        if (maxAmt == (i+1)/2 && maxIndex != prevIndex) {
            character = maxIndex;
        } else {
            for (int j = 0; j<26; j++) {
                if (alphabet[j]>0 && j!=prevIndex) {
                    character = j;
                    break;
                }
            }
        }
        cout << char('A' + character);
        alphabet[character]--;
        prevIndex = character;
    }
}