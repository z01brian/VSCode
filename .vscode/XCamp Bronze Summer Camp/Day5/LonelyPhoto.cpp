#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ll N; cin >> N;
    string s; cin >> s;
    vector<int> groupStarts;
    for (int i = 0; i<N; i++) {
        int index = i;
        while (index+1<N && s[index+1] == s[i]) {
            index++;
        }
        groupStarts.push_back(i);
        i = index;
    }

    ll lonelyCows = 0;
    for (ll i = 0; i<groupStarts.size(); i++) {
        char curr = s[groupStarts[i]];
        ll left = 0; ll right = 0;
        ll index = groupStarts[i];
        while (index-1 >= 0 && s[index-1] != curr) {
            left++;
            index--;
        }
        index = groupStarts[i];
        while (index+1 < N && s[index+1] != curr) {
            right++;
            index++;
        }

        if (left == 0 && right >= 2) {
            lonelyCows += right + 1 - 2;
        } else if (left >= 2 && right == 0) { 
            lonelyCows += left + 1 - 2;
        } else if (left >= 1 && right >= 1) {
            lonelyCows += (left+1) * (right+1) - 3;
        }
    }
    
    cout << lonelyCows;
}


// int main() {
//     ll N; cin >> N;
//     string s; cin >> s;

//     ll lonelyCows = 0;
//     for (ll i = 0; i<N; i++) {
//         char curr = s[i];
//         ll left = 0; ll right = 0;
//         ll index = i;
//         while (index-1 >= 0 && s[index-1] != curr) {
//             left++;
//             index--;
//         }
//         index = i;
//         while (index+1 < N && s[index+1] != curr) {
//             right++;
//             index++;
//         }

//         if (left == 0 && right >= 2) {
//             lonelyCows += right + 1 - 2;
//         } else if (left >= 2 && right == 0) { 
//             lonelyCows += left + 1 - 2;
//         } else if (left >= 1 && right >= 1) {
//             lonelyCows += (left+1) * (right+1) - 3;
//         }
//     }
    
//     cout << lonelyCows;
// }