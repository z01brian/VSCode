#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> a(N);
    vector<long long> b(N);
    for (int i = 0; i<N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i<N; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());

    long long count = 0;
    do {
        bool sol = true;
        for (int i = 0; i<N; i++) {
            if (a[i] <= b[i]) {
                continue;
            }
            sol = false;
        }
        if (sol) count++;

    } while (next_permutation(a.begin(), a.end()));
    cout << count;
}