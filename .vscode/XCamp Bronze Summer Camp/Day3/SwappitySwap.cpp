#include <bits/stdc++.h>
using namespace std;

vector<int> swap(int a1, int a2, int b1, int b2, vector<int>& arr) {
    vector<int> newArr = arr;
    int aIndex = 0;
    for (int i = a1; i<=a2; i++) {
        newArr[i] = arr[a2 - aIndex];
        aIndex++;
    }
    vector<int> newNewArr = newArr;
    int bIndex = 0;
    for (int i = b1; i<=b2; i++) {
        newNewArr[i] = newArr[b2 - bIndex];
        bIndex++;
    }
    return newNewArr;
}

int main() {
    int N, K; cin >> N >> K;
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    a1--; a2--; b1--; b2--;
    vector<int> arr(N);
    for (int i = 1; i<=N; i++) {
        arr[i-1] = i;
    }

    vector<int> newArr = swap(a1, a2, b1, b2, arr);
    int mod = 1;
    while (newArr != arr) {
        newArr = swap(a1, a2, b1, b2, newArr);
        mod++;
    }

    K %= mod;
    for (int i = 0; i<K; i++) {
        arr = swap(a1, a2, b1, b2, arr);
    }
    for (auto i : arr) {
        cout << i << "\n";
    }
}