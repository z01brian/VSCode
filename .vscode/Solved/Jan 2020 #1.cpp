#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;

    vector<string> words(N);
    for (int i = 0; i<N; i++) {
        cin >> words[i];
    }

    for (int i = 0; i<N; i++) {
        int size = words[i].size();
        int lastIndex = i;
        while (lastIndex+1 < N && size + words[lastIndex+1].size() <= K) {
            size += words[lastIndex+1].size();
            lastIndex++;
        }
        for (int j = i; j<=lastIndex; j++) {
            cout << words[j];
            if (j != lastIndex) cout << " ";
        }
        cout << "\n";
        i = lastIndex;
    }
}