#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int count = 0;
    for (int i : v) {
        if (i % 2 == 0) count++;
    }
    cout << count << "\n";
    return 0;
}
