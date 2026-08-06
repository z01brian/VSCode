#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, A, B; cin >> T >> A >> B;
    vector<int> dp(T+1, -1);
    dp[0] = 0;

    vector<int> validDP;
    vector<int> dpWater;
    validDP.push_back(0); dpWater.push_back(0);

    int beforeWaterMax = 0;
    for (int i = 1; i<=T; i++) {
        int neededA = i-A;
        int needB = i-B;
        if ((neededA >= 0 && dp[neededA] != -1) || (needB >= 0 && dp[needB] != -1)) {
            dp[i] = i;
            validDP.push_back(i);
            dpWater.push_back(i/2);
        }
    }
    sort(dpWater.begin(), dpWater.end());
    int afterWaterMax = 0;
    int leftIndex = 0; int rightIndex = dpWater.size()-1;
    while (leftIndex < validDP.size() && rightIndex >= 0) {
        if (validDP[leftIndex] + dpWater[rightIndex] <= T) {
            afterWaterMax = max(afterWaterMax, validDP[leftIndex] + dpWater[rightIndex]);
            leftIndex++;
        } else {
            rightIndex--;
        }
    }



    cout << max(beforeWaterMax, afterWaterMax);

}

