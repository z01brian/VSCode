#include <bits/stdc++.h>
using namespace std;


class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    pair<int, int> lengthBFS(int start) {
        queue<pair<int, int>> q; //first = index, second = length
        vector<int> distance(numVertices, -1);
        q.push(make_pair(start, 0));
        distance[start] = 0;
        pair<int, int> maxVertex = make_pair(start, 0);

        while (!q.empty()) {
            int vertex = q.front().first;
            int length = q.front().second;
            q.pop();

            for (int i : adjList[vertex]) {
                if (distance[i] == -1) {
                    distance[i] = length+1;
                    q.push(make_pair(i, length + 1));
                    int maxLength = maxVertex.second;
                    if (length + 1 > maxLength) {
                        maxVertex = make_pair(i, length+1);
                    }
                }
            }
        }
        return maxVertex;
    }


    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjList.resize(numVertices);
    }

    void addEdge(int vertex1, int vertex2) {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    int getVertices() {
        return numVertices;
    }
};


int main() { //bfs twice to get diameter then divide by 2
    int N;
    cin >> N;
    Graph graph(N);
    for (int i = 0; i<N-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph.addEdge(v1-1, v2-1);
    }
    
    pair<int, int> v1 = graph.lengthBFS(0);
    pair<int, int> v2 = graph.lengthBFS(v1.first);

    cout << (v2.second + 1 )/ 2 << "\n";
    return 0;
}

