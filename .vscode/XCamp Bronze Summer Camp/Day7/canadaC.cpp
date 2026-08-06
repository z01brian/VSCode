//just swap l and m to correct places bc then s must be in the correct order, make sure to subtract overlaps
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int numL = 0; int numM = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'L') numL++;
        if (s[i] == 'M') numM++;
    }

    int missplacedL = 0; int missplacedM = 0; int LinM = 0; int MinL = 0;
    for (int i = 0; i<s.size(); i++) {
        if (s[i] == 'L' && i > numL - 1) {
            missplacedL++;
            if (i > numL - 1 && i <= numL + numM - 1) {
                LinM++;
            }
        }
        if (s[i] == 'M' && ((i <= numL - 1) || (i > numL + numM - 1))) {
            missplacedM++;
            if (i <= numL - 1) MinL++;
        }
    }
    cout << missplacedL + missplacedM - min(LinM, MinL);
}