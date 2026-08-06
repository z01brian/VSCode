#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int N;
vector<vector<int>> treeAdjList;
vector<vector<pair<int, ll>>> edges;
vector<tuple<int, int, ll>> ans;

ll dfs(int currNode, int parentNode, vector<ll>& hay, ll avg) {
    ll weight = hay[currNode];
    for (int i: treeAdjList[currNode]) {
        if (i == parentNode) {
            continue;
        }
       ll difference = dfs(i, currNode, hay, avg);
       if (difference > 0) {
        edges[i].push_back({currNode, difference});
       } else if (difference < 0) {
        edges[currNode].push_back({i, -1*difference});
       }
       weight += difference;
    }
    return weight-avg;
}

void topologicalSortDFS(vector<bool>& marked, int currNode) {
    marked[currNode] = true;
    for (auto i : edges[currNode]) {
        if (!marked[i.first]) {
            topologicalSortDFS(marked, i.first);
        }
        ans.push_back({currNode, i.first, i.second});
    }
}

void toplogicalSort() {
    vector<bool> marked(N+1);
    for (int i = 1; i<N+1; i++) {
        if (!marked[i]) {
            topologicalSortDFS(marked, i);
        }
    }
    
}

int main() {
    cin >> N;
    treeAdjList.resize(N+1);
    edges.resize(N+1);
    vector<ll> hay(N+1);
    ll avg = 0;
    for (int i = 1; i<N+1; i++) {
        cin >> hay[i];
        avg += hay[i];
    }
    avg /= N;

    
    for (int i = 0; i<N-1; i++) {
        int node1, node2; 
        cin >> node1 >> node2;
        treeAdjList[node1].push_back({node2});
        treeAdjList[node2].push_back({node1});
    }
    dfs(1, 0, hay, avg);
    toplogicalSort();
    cout << ans.size() << "\n";
    if (ans.size() == 0) return 0;
    for (int i = ans.size()-1; i>=0; i--) {
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << "\n";
    }
}