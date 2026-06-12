#include <bits/stdc++.h>
using namespace std;

int base10(int num) {
    int ans = 0;
    int power = 0;
    while (num > 0) {
        int digit = num%10;
        ans += pow(2, power) * digit;
        power++;
        num/=10;
    }
    return ans;
}

string binary(int n) {
    string num = "";
    while (n > 0) {
        int digit = n % 2;
        num = to_string(digit) + num;
        n /= 2;
    }
    return num;
}

int main() {
    int N; cin >> N;

    int N10 = base10(N);
    N10*=17;
    cout << binary(N10);



}