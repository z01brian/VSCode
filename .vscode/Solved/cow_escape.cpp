#include <bits/stdc++.h>
using namespace std;

int N;

int canAdd(int a, int b) {
    while (a>0 && b>0) {
        if (a%10 + b%10 >= 10) {
            return -1;
        }
        a/=10;
        b/=10;
    }
    return a+b;
}

int recurse(vector<int>& weights, int currWeight, int index) { //starting weight should already be marked, return currWeight
    if (index == N) return currWeight;

    int maxWeight = recurse(weights, currWeight, index+1); //dont add weights[i]
    if (canAdd(currWeight, weights[index]) != -1) {
        maxWeight = max(maxWeight, recurse(weights, currWeight + weights[index], index+1));
    }

    return maxWeight;
}

int main() {
    cin >> N;
    vector<int> weights(N);
    for (int i = 0; i<N; i++) {
        cin >> weights[i];
    }

    cout << recurse(weights, 0, 0);
}