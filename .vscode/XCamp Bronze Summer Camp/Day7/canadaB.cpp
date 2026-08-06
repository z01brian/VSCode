#include <bits/stdc++.h>
using namespace std;

int main() {
    string original, modified;
    cin >> original >> modified;

    vector<int> originalFreq(26);
    vector<int> modifiedFreq(26);
    
    for (int i = 0; i<original.size(); i++) {
        originalFreq[original[i] - 'a']++;
    }
    for (int i = 0; i<modified.size(); i++) {
        modifiedFreq[modified[i] - 'a']++;
    }

    vector<char> possibleSilly;
    char wrong;
    for (int i = 0; i<26; i++) {
        if (originalFreq[i] > 0 && modifiedFreq[i] == 0) {
            possibleSilly.push_back('a' + i);
        } else if (modifiedFreq[i] > 0 && originalFreq[i] == 0) {
            wrong = 'a' + i;
        }
    }

    if (possibleSilly.size() == 1) possibleSilly.push_back('-');
    string testModified = "";
    for (int i = 0; i<original.size(); i++) {
        if (original[i] == possibleSilly[0]) {
            testModified.push_back(wrong);
            continue;
        }
        if (original[i] == possibleSilly[1]) continue;
        testModified.push_back(original[i]);
    }

    if (testModified == modified) {
        cout << possibleSilly[0] << " " << wrong << "\n" << possibleSilly[1];
    } else {
        cout << possibleSilly[1] << " " << wrong << "\n" << possibleSilly[0];
    }
}