#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N; cin >> N;
    string A, B;
    cin >> A >> B;

    int correct = 0; int incorrect = 0;
    for (int i = 0; i<N; i++) {
        if (A[i] == B[i]) {
            while (i<N && A[i+1] == B[i+1]) {
                i++;
            }
            correct++;
        } else {
            while (i<N && A[i+1] != B[i+1]) {
                i++;
            }
            incorrect++;
        }
    }
    cout << min(incorrect, correct);
}