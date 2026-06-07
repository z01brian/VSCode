#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
};

Node* construct(vector<int> &v1, int start1, int end1, unordered_map<int, int>& v2, int start2, int end2) {
    if (start1 > end1 || start2 > end2) {
        return nullptr;
    }

    Node* root = new Node();
    root->val = v1[start1];
    root->left = nullptr;
    root->right = nullptr;

    int rootPos = v2[root->val]; //index of root

    root->left = construct(v1, start1 + 1, start1 + rootPos-start2, v2, start2, rootPos-1);
    root->right = construct(v1, start1 + rootPos - start2 + 1, end1, v2, rootPos+1, end2);

    return root;
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    int N;
    cin >> N;
    vector<int> v1(N);
    unordered_map<int, int> v2; //<value, index>

    for (int i = 0; i<N; i++) {
        int x;
        cin >> x;
        v1[i] = x;
    }

    for (int i = 0; i<N; i++) {
        int x;
        cin >> x;
        v2[x] = i;
    }

    postOrder(construct(v1, 0, N-1, v2, 0, N-1));
}