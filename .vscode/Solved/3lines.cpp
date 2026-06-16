#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> pos;
map<int, int> unq; //store x, <value, occurences>
int distinct;

void increase(int a) {
    if (unq[a] == 0) {
        distinct++;
    }
    unq[a]++;
}
void decrease(int a) {
    unq[a]--;
    if (unq[a] == 0) {
        distinct--;
    }
}

int solve() {
    sort(pos.begin(), pos.end());
    distinct = 0;
    unq.clear();
    
    for (pair<int, int> p : pos) {
        increase(p.second); //increase the distinct 
    }
    if (distinct <= 3) return 1;

    int end = 0;
    for (int start = 0; start<N; start++) {
        while (end<N && pos[start].first == pos[end].first) { //increment up to all of pos that have the same values so we know what to remove
            end++;
        }
        for (int i = start; i<end; i++) { //remove elements from start to end
            decrease(pos[i].second);
        }

        if (distinct<=2) return 1; //see if we can go through rest of the points by just using 2 liens
        for (int i = start; i<end; i++) {
            increase(pos[i].second);
        }
        start = end;
    }
    return 0;
}


int main() {
    cin >> N;

    for (int i = 0; i<N; i++) {
        int xVal, yVal;
        cin >> xVal >> yVal;

        pos.push_back({xVal, yVal});
    }
    if (solve) {
        cout << 1;
        return 0;
    } 
    for (int i = 0; i<N; i++) {
        swap(pos[i].first, pos[i].second);
    }
    if (solve) {
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;



    // vector<pair<int, int>> pos(N);

    // for (int i = 0; i<N; i++) {
    //     int xVal, yVal;
    //     cin >> xVal >> yVal;
    //     pos[i] = {xVal, yVal};
    //     xValues.insert(xVal);
    //     yValues.insert(yVal);
    // }

}