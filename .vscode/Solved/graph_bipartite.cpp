#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

    void dfs(int node, vector<int>& group, int currentGroup) {
        if (group[node] != -1) {
            return;
        }
        group[node] = currentGroup;
        for (int i : adjList[node]) { //go through the nodes adjacent nodes
            if (group[i] != -1) { //if the adjacent node is already marked move on to the next one
                continue; 
            }
            if (currentGroup == 0) {
                dfs(i, group, 1);
            } else {
                dfs(i, group, 0);
            }
        }
        return;
    }

public:
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

    bool isBipartate() {
        vector<int> group(numVertices, -1);
        for (int i = 0; i < numVertices; i++) {  
            if (group[i] == -1) dfs(i, group, 0);
        }


        for (int vertex = 0; vertex < numVertices; vertex++) {
            for (int adjacent = 0; adjacent < adjList[vertex].size(); adjacent++) {
                if (group[vertex] == group[adjList[vertex][adjacent]]) {
                    return false;
                }
            }
        }
        return true;
    }
};





int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);


    cout << (graph.isBipartate() ? "true" : "false") << "\n";
    return 0;
}
