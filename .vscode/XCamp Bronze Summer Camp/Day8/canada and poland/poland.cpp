#include <bits/stdc++.h>
using namespace std;

string removePunctuation(string original) {
    string newStr = "";
    for (auto i : original) {
        char c = tolower(i);
        if (c - 0 >= 97 && c - 0 <= 122) {
            newStr.push_back(c);
        }
    }
    return newStr;
}

unordered_map<char, int> getPunctuation(string original) {
    unordered_map<char, int> ans;
    for (auto i : original) {
        char c = tolower(i);
        if (c - 0 < 97 || c - 0 > 122) {
            ans[c]++;
        }
    }
    return ans;
}

int main() {
    int T; cin >> T;
    string s;
    getline(cin, s);
    for (int t = 0; t<T; t++) {
        string str;
        getline(cin, str);
        stringstream ss(str);


        string word;
        bool printed = true;
        int totalWords = 0;
        while (ss >> word) {
            string formatedWord = removePunctuation(word);
            if (formatedWord == "wokulski" || formatedWord == "wokulskiego") {
                cout << "Prus" << "\n";
                printed = false;
                break;
            } else if (formatedWord == "winicjusz" || formatedWord == "winicjusza" || formatedWord == "petroniusz") {
                cout << "Sienkiewicz" << "\n";
                printed = false;
                break;
            }
            totalWords++;
        }
        
        if (printed) {
            unordered_map<char, int> punctuation = getPunctuation(str);
            if (punctuation['-'] >= totalWords/5) {
                cout << "Prus" << "\n";
            } else {
                cout << "Mickiewicz" << "\n";
            }
        }
    }
}