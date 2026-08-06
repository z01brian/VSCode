#include <bits/stdc++.h>
using namespace std;

    int N, K, A1, A2, B1, B2;

int simulate(int i) {
    if (A1 <= i && i <= A2) {
        i = A2+A1-i;
    }
    if (B1 <= i && i <= B2) {
        i = B2+B1-i;
    }
    return i;
}

int main() {

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    A1--; A2--; B1--; B2--;
    vector<int> ans(N);

    for (int i = 0; i<N; i++) {
        int count = 1;
        int index = simulate(i);
        while (index != i) {
            index = simulate(index);
            count++;
        }

        int j = K%count;
        while (j-->0) {
            index = simulate(index);
        }
        ans[index] = i+1;
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}