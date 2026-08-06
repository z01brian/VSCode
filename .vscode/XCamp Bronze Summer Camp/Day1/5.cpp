#include <bits/stdc++.h>
using namespace std;
int N;

bool bfs(vector<vector<int>>& adjList, int startNode) {
    int numMarked = 1;
    vector<bool> marked(N);

    queue<int> q;
    marked[startNode] = true;
    q.push(startNode);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : adjList[node]) {
            if (marked[i] == false) {
                q.push(i);
                marked[i] = true;
                numMarked++;
            }
        }
    }
    if (numMarked == N) return true;
    return false;
}

int main() {
    cin >> N;

    vector<vector<int>> adjList(N);
    for (int i = 0; i<N-1; i++) {
        int v1, v2; cin >> v1 >> v2;
        v1--; v2--;
        adjList[v2].push_back(v1);
    }
    for (int i = 0; i<N; i++) {
        if (bfs(adjList, i)) {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;

}