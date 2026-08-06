#include <bits/stdc++.h>
using namespace std;

int main() {
    int D; cin >> D;
    int amtLoop = 0;
    
    int hrs = 12;
    int minutesTen = 0;
    int minutesOne = 0;

    int loops = D / 720;

    for (int i = 0; i<=720; i++) {
        if (hrs >= 10) {
            int dif = hrs%10 - 1;
            if (minutesTen - hrs%10 == dif && minutesOne - minutesTen == dif) amtLoop++;
        } else {
            int dif = minutesTen - hrs;
            if (minutesOne - minutesTen == dif) amtLoop++;
        }
        minutesOne++;
        if (minutesOne == 10) {
            minutesOne = 0;
            minutesTen++;
        }
        if (minutesTen == 6) {
            minutesTen = 0;
            hrs++;
        }
        if (hrs > 12) {
            hrs %= 12;
        }
    }
    hrs = 12; minutesOne = 0;

    int amt = loops * amtLoop;
    for (int i = 0; i<=D%720; i++) {
        if (hrs >= 10) {
            int dif = hrs%10 - 1;
            if (minutesTen - hrs%10 == dif && minutesOne - minutesTen == dif) amt++;
        } else {
            int dif = minutesTen - hrs;
            if (minutesOne - minutesTen == dif) amt++;
        }
        minutesOne++;
        if (minutesOne == 10) {
            minutesOne = 0;
            minutesTen++;
        }
        if (minutesTen == 6) {
            minutesTen = 0;
            hrs++;
        }
        if (hrs > 12) {
            hrs %= 12;
        }
    }
    cout << amt;



}