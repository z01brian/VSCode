#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string, string> relationships;
unordered_map<string, bool> marked;

string mother(string cow) {
    if (relationships.count(cow)) {
        return relationships[cow];
    }
    return "";
}

int distance(string cow1, string cow2) { //finds how far apart they are
    int c = 0;
    while (cow2 != "") {
        if (cow1 == cow2) {
            return c;
        }
        c++;
        cow2 = mother(cow2);
    }
    return -1;
}

int main() {
    string bessie, elsie;
    cin >> N >> bessie >> elsie;

    for (int i = 0; i<N; i++) {
        string daughter, mother;
        cin >> mother >> daughter;
        relationships[daughter] = mother;
    }

    string cow1 = bessie;
    string cow2 = elsie;

    while (cow1 != "") { //go up until common ancestor
        marked[cow1] = true;
        cow1 = mother(cow1);
    }

    string ancestor = "";
    while (cow2 != "") {
        if (marked[cow2]) {
            ancestor = cow2;
            break;
        }
        cow2 = mother(cow2);
    }

    if (ancestor == "") { //couldn't find CA
        cout << "NOT RELATED";
        return 0;
    }

    //distance from bessie and elsie to ancestor
    int distanceBessie = distance(ancestor, bessie);
    int distanceElsie = distance(ancestor, elsie);

    if (distanceElsie == 1 && distanceBessie == 1) {
        cout << "SIBLINGS";
        return 0;
    }
    if (distanceElsie > 1 && distanceBessie > 1) {
        cout << "COUSINS";
        return 0;
    }
    if (distanceElsie > distanceBessie) { //bc bessie always first
        swap(elsie, bessie);
        swap(distanceElsie, distanceBessie);
    }
    cout << elsie << " is the ";
    for (int i = 0; i<distanceBessie - 2; i++) {
        cout << "great-";
    }
    if (distanceBessie > 1 && distanceElsie == 0) {
        cout << "grand-";
    }
    if (distanceElsie == 0) {
        cout << "mother";
    } else {
        cout << "aunt";
    }
    cout << " of " << bessie;


}