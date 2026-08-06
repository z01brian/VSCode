#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
    }

    sort(coins.begin(), coins.end());
    coins.erase(unique(coins.begin(), coins.end()), coins.end());

    auto start = chrono::steady_clock::now();

    const int INF = x + 1;
    vector<int> sol(x + 1, INF);
    sol[0] = 0;

    for (int coin : coins) {
        if (coin > x) break;

        for (int sum = coin; sum <= x; sum++) {
            sol[sum] = min(sol[sum], sol[sum - coin] + 1);
        }
    }

    auto finish = chrono::steady_clock::now();

    cout << (sol[x] == INF ? -1 : sol[x]) << '\n';

    double seconds =
        chrono::duration<double>(finish - start).count();

    cerr << fixed << setprecision(6);
    cerr << "Runtime: " << seconds << " seconds\n";
}