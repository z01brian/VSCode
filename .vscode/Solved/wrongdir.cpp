#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> xDir = {0, -1, 0, 1};
vector<int> yDir = {1, 0, -1, 0};

class Displacement {
public:
    int x;
    int y;
    int dir;

    Displacement(int x, int y, int dir) {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }

    Displacement() {
        x = 0;
        y = 0;
        dir = 0;
    }
};

int rotateX (int dir, Displacement& d) {
    if (dir==0) return d.x;
    if (dir==1) return d.y;
    if (dir==2) return -d.x;
     if (dir==3) return -d.y;
}
int rotateY (int dir, Displacement& d) {
  if (dir==0) return d.y;
  if (dir==1) return -d.x;
  if (dir==2) return -d.y;
  if (dir==3) return d.x;
}

vector<Displacement> prefixDisplacement() {
    vector<Displacement> prefix(s.size());
    for (int i = 0; i<s.size(); i++) {
        char command = s[i];

        if (i == 0) {
            Displacement d;
            if (command == 'F') d.y++;
            if (command == 'R') d.dir = 3;
            if (command == 'L') d.dir = 1;
            prefix[i] = d;
            continue;
        }

        Displacement d(prefix[i-1].x, prefix[i-1].y, prefix[i-1].dir);
        if (command == 'F') {
            d.x += xDir[d.dir];
            d.y += yDir[d.dir];
        }
        if (command == 'R') d.dir = (d.dir+3)%4;
        if (command == 'L') d.dir = (d.dir+1)%4;

        prefix[i] = d;
    }
    return prefix;
}

vector<Displacement> suffixDisplacement() {
    vector<Displacement> suffix(s.size()+1);
    suffix[s.size()] = Displacement();

    for (int i = s.size()-1; i>=0; i--) {
        char command = s[i];
        suffix[i] = Displacement();

        if (command == 'F') { 
            suffix[i].x = suffix[i+1].x;  
            suffix[i].y = 1 + suffix[i+1].y; 
        }
        if (command == 'L') { 
            suffix[i].x = suffix[i+1].y; 
            suffix[i].y = -suffix[i+1].x; 
        }
        if (command == 'R') { 
            suffix[i].x = -suffix[i+1].y;  
            suffix[i].y = suffix[i+1].x; 
        }
    }
  
    return suffix;
}

int main() {
    cin >> s;
    set<pair<int, int>> cords;
    vector<Displacement> prefix = prefixDisplacement();
    vector<Displacement> suffix = suffixDisplacement();
    vector<char> cmds = {'F', 'R', 'L'};

    for (int i = 0; i<s.size(); i++) { 
        int x, y, dir;
        if (i == 0) {
            x = 0; y = 0; dir = 0;
        } else {
            x = prefix[i-1].x;
            y = prefix[i-1].y;
            dir = prefix[i-1].dir;
        }
        for (char cmd : cmds) {
            if (cmd == s[i]) continue;
            int newDir = dir;
            int newX = x;
            int newY = y;


            if (cmd == 'F') {
                newX += xDir[newDir];
                newY += yDir[newDir];
            }
            if (cmd == 'L') newDir = (newDir + 1) % 4;
            if (cmd == 'R') newDir = (newDir + 3) % 4;
            int pointX = newX + rotateX(newDir, suffix[i+1]);
            int pointY = newY + rotateY(newDir, suffix[i+1]);

            cords.insert({pointX, pointY});

            
        }
    }
    cout << cords.size();
}
