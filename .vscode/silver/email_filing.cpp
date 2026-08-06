#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T-- > 0) {
        int M, N, K; cin >> M >> N >> K;
        vector<int> passed; //keeps indexes that we've passed and aren't used
        list<int> visible; //keeps the elements we can file rn
        vector<list<int>::iterator> positions(N+1); //keeps iterator for current visible
        set<pair<int, int>> emailToFolder; //keeps {folder, index}
        vector<int> remaining(M+1); //for every folder keeps remaining unfiled
        vector<int> emails(N); //input

        auto addToBack = [&](int index) {
            visible.push_back(index);
            emailToFolder.insert({emails[index], index});
            positions[index] = prev(visible.end());
        };
        auto addToFront = [&](int index) {
            visible.push_front(index);
            emailToFolder.insert({emails[index], index});
            positions[index] = visible.begin();
        };

        for (int i = 0; i<N; i++) {
            cin >> emails[i];
            remaining[emails[i]]++;
        }

        for (int i = 0; i<K; i++) {
            addToBack(i);
        }
        // int emailWindowStart = 0;
        int nextEmail = K;
        int filed = 0;
        bool sol = true;
        for (int i = 1; i <= M+1-K; i++) {
            if (!sol) break;
            while (true) {
                auto it = emailToFolder.lower_bound({i, -1});

                if (it != emailToFolder.end() && it->first <= i+K-1) { //email in the current window that needs to be filed
                    int tempIndex = it->second;
                    visible.erase(positions[it->second]);
                    emailToFolder.erase(it);
                    remaining[emails[tempIndex]]--;

                    filed++;
                    if (nextEmail < N) {
                        addToBack(nextEmail);
                        nextEmail++;
                        // emailWindowStart++;
                    } else if (!passed.empty()){
                        int newIndex = passed.back();
                        passed.pop_back();
                        addToFront(newIndex);
                    }
                } else {
                    if (i == M+1-K) {
                        if (filed == N) break;
                    } else {
                        if (remaining[i] == 0) break;
                    }
                    if (nextEmail < N) { //not end so we can scroll down
                        int index = visible.front();
                        visible.pop_front();
                        passed.push_back(index);
                        addToBack(nextEmail);
                        nextEmail++;
                        // emailWindowStart++;
                        emailToFolder.erase({emails[index], index});
                    } else {
                        sol = false;
                        break;
                    }
                }
            }
        }
        if (sol) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }
}