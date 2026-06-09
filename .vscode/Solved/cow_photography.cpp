#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> orderings; 

bool compare(int a, int b) { //must return true if a comes before b (compare positions of a and b so ints)
    int aFirst = 0;
    for (int i = 0; i<5; i++) {
        if (orderings[i][a] < orderings[i][b]) {
            aFirst++;
        }
    }
    return (aFirst >= 3); 
}

int main() {
    int N;
    cin >> N;

    vector<int> cows(N);
    orderings = vector<vector<int>>(5, vector<int>(N+1));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j<N; j++) {
            int id;
            cin >> id;
            orderings[i][id] = j; //set cow's position inside the correct ordering
            if (i == 0) cows[j] = id;
        }
    }

    sort(cows.begin(), cows.end(), compare);
    for (int i = 0; i<N; i++) {
        cout << cows[i] << "\n";
    }
}