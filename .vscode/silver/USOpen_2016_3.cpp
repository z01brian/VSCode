#include <bits/stdc++.h>
using namespace std;

vector<int> par;

int findRoot(int barn) {
    int temp = barn;
    while (par[temp] != temp) {
        temp = par[temp];
    }
    while (par[barn] != barn) {
        int parent = par[barn];
        par[barn] = temp;
        barn = parent;
    }
    return temp;
}

bool combine(int barn1, int barn2) {
    int rootBarn1 = findRoot(barn1);
    int rootBarn2 = findRoot(barn2);
    if (rootBarn1 == rootBarn2) {
        return false;
    }
    par[rootBarn2] = rootBarn1;
    return true;
}


int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<pair<int, int>> paths(M);
    for (int i = 0; i<M; i++) {
        cin >> paths[i].first >> paths[i].second;
    }

    vector<int> order(N);
    for (int i = 0; i<N; i++) {
        cin >> order[i];
    }

    vector<int> orderOnBarns(N);
    for (int i = 0; i<N; i++) {
        orderOnBarns[order[i]-1] = i;
    }

    vector<vector<int>> adjList(N+1);
    for (int i = 0; i<M; i++) {
        int barn1 = paths[i].first;
        int barn2 = paths[i].second;
        if (orderOnBarns[barn1 - 1] < orderOnBarns[barn2 - 1]) {
            adjList[barn1].push_back(barn2);
        } else {
            adjList[barn2].push_back(barn1);
        }
    }

    par.resize(N+1);
    for (int i = 1; i<=N; i++) {
        par[i] = i;
    }

    vector<bool> ans(N);
    int components = 0;

    for (int i = N-1; i>=0; i--) {
        int newBarn = order[i];
        components++;

        for (auto j : adjList[newBarn]) {
            if (combine(newBarn, j)) {
                components--;
            }
        }
        ans[i] = components == 1;
    }

    for (int i = 0; i<N; i++) {
        if (ans[i]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}