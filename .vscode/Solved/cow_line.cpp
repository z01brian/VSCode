#include  <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_set<int> ids(N);
    int maxConsecutive = 0;

    for (int i = 0; i<N; i++) {
        int id;
        cin >> id;
        ids.insert(id);
    }

    for (int id : ids) {
        int consecutive = 1;
        int i = 1;
        if (ids.find(id-1) != ids.end()) {
            continue;
        }
        while (ids.count(id + i) != 0) {
            i++;
            consecutive++;
        }
        maxConsecutive = max(maxConsecutive, consecutive);
    }

    cout << maxConsecutive;
    return 0;
}