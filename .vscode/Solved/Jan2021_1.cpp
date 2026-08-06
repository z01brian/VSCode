#include <bits/stdc++.h>
using namespace std;

int main() {
    string alphabet; cin >> alphabet;
    string heard; cin >> heard;


    int count = 1;
    int prevIndex = -1;
    for (int i = 0; i<heard.size(); i++) {
        char c = heard[i];

        int currIndex;
        for (int j = 0; j<26; j++) {
            if (alphabet[j] == c) {
                currIndex = j;
                break;
            }
        }
        if (currIndex <= prevIndex) {
            count++;
        }
        prevIndex = currIndex;
    }
    cout << count;
}