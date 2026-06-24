#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> occurences(26);
    for (int i = 0; i<s.size()-1; i++) {
        occurences[s[i]-'a']++;
    }
    for (int i = 0; i<26; i++) {
        cout << occurences[i] << " ";
    }
}