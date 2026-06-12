#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> haybales(N);
    for (int i = 0; i<K; i++) {
        int r1, r2;
        cin >> r1 >> r2;
        haybales[r1 - 1]++;
        haybales[r2]--;
    }
    
    int count = 0;
    for (int i = 0; i<N; i++) {
        count += haybales[i];
        haybales[i] = count;
    }

    sort(haybales.begin(), haybales.end());
    cout << haybales[N/2];
}