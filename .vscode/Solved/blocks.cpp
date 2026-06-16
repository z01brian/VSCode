#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<pair<string, string>> boards(N);

    for (int i = 0; i<N; i++) {
        cin >> boards[i].first >> boards[i].second;
    }

    vector<int> letters(26);

    for (int i = 0; i<N; i++) {
        unordered_set<char> addLetters;
        for (int j = 0; j<boards[i].first.size(); j++) {
            addLetters.insert(boards[i].first[j]);         }
        for (int k = 0; k<boards[i].second.size(); k++) {
            addLetters.insert(boards[i].second[k]);
        }
        for (auto c : addLetters) {
            letters[c - 'a']++;
        }
    }
    for (int i = 0; i<letters.size(); i++) {
        cout << letters[i] << "\n";
    }
    
}