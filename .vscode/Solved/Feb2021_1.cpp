#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> zodiacs = {
        {"Ox", 1}, {"Tiger", 2}, 
        {"Rabbit", 3}, {"Dragon", 4}, 
        {"Snake", 5}, {"Horse", 6}, 
        {"Goat", 7}, {"Monkey", 8}, 
        {"Rooster", 9}, {"Dog", 10},
        {"Pig", 11}, {"Rat", 12}
    };

int main() {
    int N; cin >> N;
    
    unordered_map<string, int> yearAgo;
    unordered_map<string, string> zodiac;

    yearAgo["Bessie"] = 0;
    zodiac["Bessie"] = "Ox";

    for (int i = 0; i<N; i++) {
        string cow1, order, animal, cow2;
        cin >> cow1 >> order >> order >> order >> animal >> cow2 >> cow2 >> cow2;
        zodiac[cow1] = animal;

        int zodiac1 = zodiacs[animal];
        int zodiac2 = zodiacs[zodiac[cow2]];
        if (order == "previous") {
            int i = zodiac2 - zodiac1;
            if (i <= 0) i+=12;
            yearAgo[cow1] = yearAgo[cow2] - i;
        } else {
            int i = zodiac1-zodiac2;
            if (i <= 0) {
                i+=12;
            }

            yearAgo[cow1] = yearAgo[cow2] + i;
        }

    }
    cout << abs(yearAgo["Elsie"]);

}