#include <bits/stdc++.h>
using namespace std;

class Cow {
public:
    int start;
    int end;
    int buckets;
};

int comp(Cow a, Cow b) {
    return a.start < b.start;
}

int main() {
    int N; cin >> N;
    vector<Cow> cows(N);
    vector<int> buckets(1);
    for (int i = 0; i<N; i++) {
        Cow cow;
        cin >> cow.start >> cow.end >> cow.buckets;
        cows[i] = cow;
    }

    sort(cows.begin(), cows.end(), comp);

    for (int i = 0; i<N; i++) {
        int start = cows[i].start;
        int end = cows[i].end;
        int bucketsNeeded = cows[i].buckets;

        int j = 0;
        while (bucketsNeeded > 0) {
            if (j+1 > buckets.size()) {
                buckets.push_back(0);
            }
            if (buckets[j] <= start) {
                bucketsNeeded--;
                buckets[j] = end;
            }
            j++;
        }
    }
    cout << buckets.size();
}