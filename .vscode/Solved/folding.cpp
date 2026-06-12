#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, length; cin >> N >> length;
    length++;
    int amt = 0;

    vector<int> rope(length); //0 for no knot, 1 for knot
    for (int i = 0; i<N; i++) {
        int knot; cin >> knot;
        rope[knot] = 1;
    }

    vector<int> left = {rope[0]};
    vector<int> right(rope.begin()+2, rope.end());
    bool found = true;

    for (int fold = 1; fold<length-1; fold++) {
        found = true;
        int minLength = min(left.size(), right.size());
        reverse(left.begin(), left.end());
        for (int i = 0; i<minLength; i++) {
            if (left[i] != right[i]) found = false;
        }
        if (found) amt++;
        reverse(left.begin(), left.end());
        left.push_back(rope[fold]);
        right.erase(right.begin());
    }
    cout << amt;

} //O(L*N)