#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    if (N==1 || N==2) {
        cout << 1;
        return 0;
    }

    vector<int> sequence;
    sequence.push_back(1);
    sequence.push_back(1);

    for (int i = 2; i<=N; i++) {
        sequence.push_back((sequence[i-1]+sequence[i-2])%1000000007);
    }
    cout << sequence[N];

}