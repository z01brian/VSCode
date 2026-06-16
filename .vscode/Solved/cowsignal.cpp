#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N, K; cin >> M >> N >> K;
    vector<string> signal(M);
    for (int i = 0; i<M; i++) {
        cin >> signal[i];
    }

    vector<vector<char>> enlargedSignal(M*K, vector<char>(N*K));
    for (int i = 0; i<M*K; i++) { //row
        string originalString = signal[i/K]; //length N
        for (int j = 0; j<N*K; j++) {
            char c = originalString[j/K];
            enlargedSignal[i][j] = c;
        }
    }

    for (int i = 0; i<enlargedSignal.size(); i++) {
        for (int j = 0; j<enlargedSignal[0].size(); j++) {
            cout << enlargedSignal[i][j];
        }
        cout << "\n";
    }
}