#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> pos(N, -1);
    vector<int> order(M);
    unordered_map<int, int> setPos;
    
    for (int i = 0; i<M; i++) {
        cin >> order[i];
    }

    for (int i = 0; i<K; i++) {
        int cow, index;
        cin >> cow >> index;
        setPos[cow] = index;
        if (cow == 1) {
            cout << index;
            return 0;
        }
        pos[index-1] = cow;
    }

    for (int i = 0; i<M; i++) {
        if (order[i] == 1) {
            vector<int> leftOrder(order.begin(), order.begin()+i);
            int index = 0;
            int j = 0;
            while (index < leftOrder.size()) {
                if (setPos.count(leftOrder[index])) {
                    j = setPos[leftOrder[index]]-1;
                    index++;
                    j++;
                    continue;
                }
                if (pos[j] != -1) {
                    j++;
                    continue;
                }
                pos[j] = leftOrder[index];
                index++;
                j++;
            }
            while (j < N && pos[j] != -1) {
                j++;
            }
            cout << j+1;
            return 0;
        }
    }

    int index = order.size() - 1;
    int i = N-1;
    while (index >= 0) {
        if (setPos.count(order[index])) {
            i = setPos[order[index]]-1;
            index--;
            i--;
            continue;
        }
        if (pos[i] != -1) {
            i--;
            continue;
        }
        pos[i] = order[index];
        index--;
        i--;
    }
    for (int j = 0; j<N; j++) {
        if (pos[j] == -1) {
            cout << j+1;
            return 0;
        }
    }

}