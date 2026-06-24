#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    for (int i = 0; i<3; i++) {
        string row;
        cin >> row;
        for (int j = 0; j<3; j++) {
            board[i][j] = row[j];
        }
    }

    int oneTeams = 0;
    int twoTeams = 0;

    //check for rows
    for (int i = 0; i<3; i++) {
        unordered_set<char> row;
        for (int j = 0; j<3; j++) {
            row.insert(board[i][j]);
        }
        if (row.size() == 1) oneTeams++;
        if (row.size() == 2) twoTeams++;
    }

    //cols
    for (int i = 0; i<3; i++) {
        unordered_set<char> col;
        for (int j = 0; j<3; j++) {
            col.insert(board[j][i]);
        }
        if (col.size() == 1) oneTeams++;
        if (col.size() == 2) twoTeams++;
    }

    //diags
    unordered_set<char> diag1;
    diag1.insert(board[0][0]);
    diag1.insert(board[1][1]);
    diag1.insert(board[2][2]);
    if (diag1.size() == 1) oneTeams++;
    if (diag1.size() == 2) twoTeams++;

    unordered_set<char> diag2;
    diag2.insert(board[2][0]);
    diag2.insert(board[1][1]);
    diag2.insert(board[0][2]);
    if (diag2.size() == 1) oneTeams++;
    if (diag2.size() == 2) twoTeams++;

    cout << oneTeams << "\n" << twoTeams;
}