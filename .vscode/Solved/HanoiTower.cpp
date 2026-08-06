#include <bits/stdc++.h>
using namespace std;

void move(int blocks, char start, char end, char other) {
    if (blocks == 1) {
        cout << start << "->" << end << "\n";
        return;
    }
    move(blocks-1, start, other, end);
    cout << start << "->" << end << "\n";
    move(blocks-1, other, end, start);
}

int main() {
    int N; cin >> N;
    move(N, 'A', 'B', 'C');
}