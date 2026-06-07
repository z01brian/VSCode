#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, C;
    cin >> N;

    vector<int> notes(N);
    for (int i = 0; i<N; i++) {
        int note;
        cin >> note;
        notes[i] = note;
    }

    cin >> C;
    vector<int> chord(C);
    for (int i = 0; i<C; i++) {
        int note;
        cin >> note;
        chord[i] = note;
    }
    sort(chord.begin(), chord.end());

    vector<int> solutions;

    for (int start = 0; start+C-1<N; start++) {
        vector<int> window(notes.begin()+start, notes.begin()+start+C);
        sort(window.begin(), window.end());
        int difference = chord[0] - window[0];
        bool equal = true;
        for (int i = 1; i<C; i++) {
            if (chord[i] - window[i] != difference){
                equal = false;
                break;
            }
        }
        if (equal) {
            solutions.push_back(start+1);
        }
    }

    cout << solutions.size() << "\n";
    for (auto i : solutions) {
        cout << i << "\n";
    }
}