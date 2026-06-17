#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int crossings = 0;

    vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<pair<int, int>> letterLocations(26, {-1, -1});

    for (int i = 0; i<52; i++) {
        int index = s[i] - 'A';
        if (letterLocations[index].first != -1) {
            letterLocations[index].second = i;
        } else {
            letterLocations[index].first = i;
        }
    }

    for (int i = 0; i<26; i++) {
        char letter = letters[i];
        int index1 = letterLocations[letter-'A'].first;
        int index2 = letterLocations[letter-'A'].second;

        unordered_set<char> cross;
        for (int j = index1+1; j<index2; j++) {
            if (!cross.insert(s[j]).second) {
                cross.erase(s[j]);
            } else {
                cross.insert(s[j]);
            }
        }
        crossings += cross.size();
    }
    crossings/=2;
    cout << crossings;
}