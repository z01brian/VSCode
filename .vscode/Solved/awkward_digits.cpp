#include <bits/stdc++.h>
using namespace std;

int base10(int num, int base) {
    int ret = 0;
    int power = 0;
    while (num > 0) {
        int digit = num%10;
        ret += pow(base, power)*digit;
        power++;
        num /= 10;
    }
    return ret;
}
 
int main() {
    string base2, base3;
    cin >> base2 >> base3;

    for (int i = 0; i<base2.length(); i++) {
        char original2 = base2[i];
        if (original2 == '1') { 
            base2[i] = '0';
        } else {
            base2[i] = '1';
        }

        int number = base10(stoi(base2), 2);

        for (int j = 0; j<base3.length(); j++) {
            char original3 = base3[j];
            for (int k = 0; k<2; k++) {
                if (base3[j] == '0') {
                    base3[j] = '1';
                } else if (base3[j] == '1') {
                    base3[j] = '2';
                } else {
                    base3[j] = '0';
                }

                if (number == base10(stoi(base3), 3)) {
                    cout << number;
                    return 0;
                }
            }
            base3[j] = original3;
        }
        base2[i] = original2;
    }

}