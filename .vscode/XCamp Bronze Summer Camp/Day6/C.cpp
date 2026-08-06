#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll maxFactors(ll a, ll b, int factor) {
    ll power = 0;
    while (true) {
        ll multiple = a / pow(factor, power);
        if (multiple * pow(factor, power) < a && (multiple+1) * pow(factor, power) > b) {
            break;
        }
        power++;
    }
    return power-1;
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll factorOfTwos = maxFactors(a, b, 2);
    ll factorOfFives = maxFactors(a, b, 5);
    cout << min(factorOfTwos, factorOfFives);
}