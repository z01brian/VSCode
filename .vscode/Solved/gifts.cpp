#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, budget; cin >> N >> budget;
    map<int, int> gifts; //<totalprice, price> sorted by totalprice not price
    int spent = 0;
    vector<int> taken;

    for (int i = 0; i<N; i++) {
        int p, s;
        cin >> p >> s;
        gifts[s+p] = p;
    }

    for (auto& gift : gifts) { 
        if (gift.first + spent <= budget) {
            taken.push_back(gift.first);
            spent += gift.first;
        }
    }

    for (int gift : taken) { //gift is totalprice
        spent -= gifts[gift]/2;
        auto g = next(gifts.begin(), taken.size()-1); //iterates until the element not added
        if (g->first + spent <= budget) { //do -> because iterator is just a pointer
            cout << taken.size() + 1;
            return 0;
        }
        spent += gifts[gift]/2;
    }

    auto g = next(gifts.begin(), taken.size());
    if (spent + (g->first - (g->second)/2) <= budget) {
        cout << taken.size() + 1;
        return 0;
    }
    

    cout << taken.size();
}