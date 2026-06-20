#include <bits/stdc++.h>
using namespace std;

class Measurement {
public:
    int day;
    string Name;
    int change;
};

bool compare(Measurement m, Measurement n) {
    return m.day < n.day;
}

int main() {
    int N; cin >> N;
    vector<Measurement> measurements(N);

    for (int i = 0; i<N; i++) {
        Measurement m;

        cin >> m.day >> m.Name >> m.change;

        measurements[i] = m;
    }

    int changes = 0;
    int maxOutput = 7;
    unordered_map<string, int> cows = {{"Mildred", 7}, {"Elsie", 7}, {"Bessie", 7}};  //<name, production>
    sort(measurements.begin(), measurements.end(), compare);
    unordered_set<string> currDisplay = {"Mildred", "Elsie", "Bessie"};
    
    for (int i = 0; i<N; i++) {
        Measurement curr = measurements[i];
        cows[curr.Name] += curr.change;

        for (auto cow : cows) {
            maxOutput = max(maxOutput, cow.second);
        }

        unordered_set<string> newDisplay;
        for (auto cow : cows) {
            if (cow.second == maxOutput) newDisplay.insert(cow.first);
        }

        if (newDisplay != currDisplay) changes++;
        currDisplay = newDisplay;
    }
    cout << changes;
}