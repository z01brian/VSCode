#include <bits/stdc++.h>
using namespace std;

int N, A, B;

void bfs(int start, vector<int>& marked, vector<int>& goTo) {
    marked[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int index = q.front();
        int add = goTo[index];
        q.pop();

        if (index + add < N && marked[index+add] == -1) {
            marked[index+add] = marked[index]+1;
            q.push(index+add);
        }
        if (index - add >= 0 && marked[index-add] == -1) {
            marked[index-add] = marked[index]+1;
            q.push(index - add);
        }
    }
}


int main() {
    while (cin >> N && N!=0) {
        cin >> A >> B;
        A--; B--;
        vector<int> goTo(N);
        for (int i = 0; i<N; i++) {
            cin >> goTo[i];
        }
    

        vector<int> marked(N, -1);
        bfs(A, marked, goTo);
        cout << marked[B] << "\n";
    }
}