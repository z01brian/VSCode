#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int N; long long K; 
    cin >> K >> N;

    vector<int> xValues(N);
    for (int i = 0; i<N; i++) {
        cin >> xValues[i];
    }

    for (int i = 0; i<N; i++) {
        int X = xValues[i];
        long long sum = 0; long long time = 0; long long currSpeed = 0;
        while (sum < K) {
            if (currSpeed+1 <= X) {
                currSpeed++;
                sum += currSpeed;
                time++;
                continue;
            } else {
                if (sum + currSpeed + currSpeed + 1 < K) {
                    currSpeed++;
                    time += 2;
                    sum += currSpeed + currSpeed -1;
                    continue;
                }
            }
            sum += currSpeed;
            time++;
        }
        cout << time << "\n";
    }
    return 0;
}