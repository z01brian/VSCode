#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minArea = INT_MAX;
int N;

struct Bound{
    int minX, minY, maxX, maxY;
};

bool sortY(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void recurse(int removedPoints, vector<pair<int, int>> xValues, vector<pair<int, int>> yValues, vector<bool> marked) {
    if (removedPoints == 3) {
        int minX, maxX, minY, maxY;
        for (int i = 0; i<N; i++) {
            if (!marked[xValues[i].second]) {
                minX = xValues[i].first;
                break;
            }
        }
        for (int i = N-1; i>=0; i--) {
            if (!marked[xValues[i].second]) {
                maxX = xValues[i].first;
                break;
            }
        }
        for (int i = 0; i<N; i++) {
            if (!marked[yValues[i].second]) {
                minY = yValues[i].first;
                break;
            }
        }
        for (int i = N-1; i>=0; i--) {
            if (!marked[yValues[i].second]) {
                maxY = yValues[i].first;
                break;
            }
        }

        minArea = min(minArea, (maxX-minX)*(maxY-minY));
        return;
    } 

    int temp;
    for (int i = 0; i<N; i++) {
        if (!marked[xValues[i].second]) {
            marked[xValues[i].second] = true;
            temp = xValues[i].second;
            break;
        }
    }
    recurse(removedPoints+1, xValues, yValues, marked);
    marked[temp] = false;

    for (int i = N-1; i>=0; i--) {
        if (!marked[xValues[i].second]) {
            marked[xValues[i].second] = true;
            temp = xValues[i].second;
            break;
        }
    }
    recurse(removedPoints+1, xValues, yValues, marked);
    marked[temp] = false;

    for (int i = 0; i<N; i++) {
        if (!marked[yValues[i].second]) {
            marked[yValues[i].second] = true;
            temp = yValues[i].second;
            break;
        }
    }
    recurse(removedPoints+1, xValues, yValues, marked);
    marked[temp] = false;

    for (int i = N-1; i>=0; i--) {
        if (!marked[yValues[i].second]) {
            marked[yValues[i].second] = true;
            temp = yValues[i].second;
            break;
        }
    }
    recurse(removedPoints+1, xValues, yValues, marked);
    marked[temp] = false;
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<bool> marked(N);
    vector<pair<int, int>> xValues;
    vector<pair<int, int>> yValues;
    
    for (int i = 0; i<N; i++) {
        xValues.push_back({points[i].first, i});
        yValues.push_back({points[i].second, i});
    }
    sort(xValues.begin(), xValues.end());
    sort(yValues.begin(), yValues.end());

    recurse(0, xValues, yValues, marked);
    cout << minArea;

}