#include <bits/stdc++.h>
using namespace std;

unordered_set<int> amt;

void recurse(int currBarn1, int currBarn2, vector<int>& barn1, vector<int>& barn2, int day) { //start tuesday to friday
    if (day == 5) {
        amt.insert(currBarn1);
        return;
    }
    if (day%2 == 1) { //1->2
        for (int i = 0; i<barn1.size(); i++) {
            int bucketSize = barn1[i];

            barn1.erase(barn1.begin() + i);
            barn2.push_back(bucketSize);

            recurse(currBarn1-bucketSize, currBarn2+bucketSize, barn1, barn2, day+1);

            barn2.erase(barn2.end()-1);
            barn1.insert(barn1.begin() + i, bucketSize);
        }
    } else { //2->1
        for (int i = 0; i<barn2.size(); i++) {
            int bucketSize = barn2[i];

            barn2.erase(barn2.begin() + i);
            barn1.push_back(bucketSize);

            recurse(currBarn1+bucketSize, currBarn2-bucketSize, barn1, barn2, day+1);

            barn1.erase(barn1.end()-1);
            barn2.insert(barn2.begin() + i, bucketSize);
        }
    }
}


int main() {
    vector<int> barn1(10);
    vector<int> barn2(10);
    
    for (int i = 0; i<10; i++) {
        cin >> barn1[i];
    }
    for (int i = 0; i<10; i++) {
        cin >> barn2[i]; 
    }
    recurse(1000, 1000, barn1, barn2, 1);

    cout << amt.size();
}