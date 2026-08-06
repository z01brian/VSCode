#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int curr = 0;
    int maxppl = 0;
    for (int i = 0; i<n; i++) {
        int a, b; cin >> a >> b;
        curr -= a;
        curr += b; 
        maxppl = max(maxppl, curr);
    }
    cout << maxppl;
}