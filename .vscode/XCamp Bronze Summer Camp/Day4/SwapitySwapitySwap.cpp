#include <bits/stdc++.h>
using namespace std;

vector<int> swapitySwap(const vector<int>& arr, const vector<int>& order) {
    vector<int> newArr(arr.size());
    for (int i = 0; i<newArr.size(); i++) {
        newArr[i] = order[arr[i]-1];
    }
    return newArr;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int N, M, K; cin >> N >> M >> K;
    vector<pair<int, int>> swaps(M);
    for (int i = 0; i<M; i++) {
        cin >> swaps[i].first >> swaps[i].second;
        swaps[i].first--;
        swaps[i].second--;
    }

    unordered_map<int, vector<int>> allOrders;

    vector<int> currArr(N);
    for (int i = 1; i<N+1; i++) {
        currArr[i-1] = i;
    }

    for (auto i : swaps) {
        reverse(currArr.begin() + i.first, currArr.begin() + i.second + 1);
    }
    allOrders[1] = currArr;
    if (K == 1) {
        for (auto i : currArr) {
            cout << i << "\n";
        }
        return 0;
    }

    for (auto i : swaps) {
        reverse(currArr.begin() + i.first, currArr.begin() + i.second + 1);
    }
    allOrders[2] = currArr;
    if (K == 2) {
        for (auto i : currArr) {
            cout << i << "\n";
        }
        return 0;
    }

    int k = 2;
    while (k * 2 < K) {
        k *= 2;
        currArr = swapitySwap(currArr, currArr);
        allOrders[k] = currArr;
    }

    K -= k; //currArr is a(k)
    while (K > 0) {
        if (K == 1) {
            currArr = swapitySwap(currArr, allOrders[1]);
            K--;
            continue;
        }
        int i = 1;
        while (i*2 < K) {
            i*=2;
        }
        currArr = swapitySwap(currArr, allOrders[i]);
        K -= i;
    }

    for (auto i : currArr) {
        cout << i << "\n";
    }
}
