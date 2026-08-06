#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int N;
string road;

bool uniqueLen(int len) {
    unordered_set<string> unique;
    bool sol = true;
    for (int start = 0; start+len<=N; start++) {
        string curr = road.substr(start, len);
        if (!unique.insert(curr).second) {
            return false;
        }
    }
    return true;
}

int binarySearch() {
    int start = 1; int end = N;
    while (start != end) {
        int middle = (start+end)/2; 
        if (uniqueLen(middle)) {
            end = middle;
        } else {
            start = middle+1;
        }
    }
    return start;
}

int main() {
    cin >> N;
    cin >> road;
    cout << binarySearch();   
}

int stupidsearch() {
    int N; cin >> N;
    string road; cin >> road;

    for (int len = 1; len<=N; len++) {
        unordered_set<string> unique;
        bool sol = true;
        for (int start = 0; start+len<=N; start++) {
            string curr = road.substr(start, len);
            if (!unique.insert(curr).second) {
                sol = false;
                break;
            }

        }
        if (sol) {
            cout << len;
            return 0;
        }
    }
}