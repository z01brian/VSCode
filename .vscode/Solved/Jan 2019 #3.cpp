#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    string name;
    int num;
    unordered_set<string> characteristics;
};

int main() {
    int N; cin >> N;
    vector<Animal> animals(N);

    for (int i = 0; i<N; i++) {
        Animal a;
        string name; int num;
        cin >> name >> num;
        for (int j = 0; j<num; j++) {
            string c;
            cin >> c;
            a.characteristics.insert(c);
        }
        a.name = name;
        a.num = num;
        animals[i] = a;
    }

    int maxSimilar = -1;
    int animal1, animal2;
    for (int i = 0; i<N; i++) {
        for (int j = i+1; j<N; j++) {
            int similar = 0;
            for (auto k : animals[i].characteristics) {
                if (animals[j].characteristics.find(k) != animals[j].characteristics.end()) similar++;
            }
            if (similar > maxSimilar) {
                maxSimilar = similar;
                animal1 = i;
                animal2 = j;
            }
        }
    }

    cout << maxSimilar+1;

}