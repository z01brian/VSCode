#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N; //N<10
    vector<vector<int>> painting(N, vector<int>(N));
    unordered_set<int> colors;

    for (int i = 0; i<N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j<N; j++) {
            int color = row[j] - '0';
            painting[i][j] = color;

            if (color != 0) colors.insert(color);
        }
    }

    unordered_set<int> notFirst;
    int possible = 0;
    for (int color : colors) {
        if (notFirst.find(color) != notFirst.end()) continue;

        vector<int> xValues;
        vector<int> yValues;

        for (int i = 0; i<N; i++) {
            for (int j = 0; j<N; j++) {
                if (painting[i][j] == color) {
                    xValues.push_back(i);
                    yValues.push_back(j);
                }
            }
        }

        sort(xValues.begin(), xValues.end());
        sort(yValues.begin(), yValues.end());
        
        for (int row = xValues.front(); row<=xValues.back(); row++) {
            for (int col = yValues.front(); col <= yValues.back(); col++) {
                if (painting[row][col] != color) notFirst.insert(painting[row][col]);
            }
        }
    }
    cout << colors.size() - notFirst.size();
}