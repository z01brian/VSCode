#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    int amt = 0;
    while (n > 0) {
        int digit = n%10;
        if (digit == 4 || digit == 7) amt++;
        n/=10;
    }
    int count = 0;
    int sol = amt > 0;
    while (amt > 0) {
        int digit = amt%10;
        if (digit != 4 && digit != 7) {
            sol = false;
            break;
        }
        amt/=10;
    }
    if (sol) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}


