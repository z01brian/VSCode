#include <bits/stdc++.h>
using namespace std;

int oddComp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i<10; i++) {
        int a; cin >> a;
        if (a%2 == 0) {
            even.push_back(a);
        } else {
            odd.push_back(a);
        }
    }

    sort(odd.begin(), odd.end(), oddComp);
    sort(even.begin(), even.end());
    for (int i = 0; i<odd.size(); i++) {
        cout << odd[i] << " ";
    }
    for (int i = 0; i<even.size(); i++) {
        cout << even[i] << " ";
    }
}