#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> cowLocation(11);
    int crossings = 0;

    for (int i = 0; i<N; i++) {
        int index, curr;
        cin >> index >> curr;
        if (cowLocation[index] > 0 && cowLocation[index] != curr) crossings++;
        cowLocation[index] = curr;
    }
    cout << crossings;
}