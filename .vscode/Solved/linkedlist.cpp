#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value = 0;
    Node* next = nullptr;

    Node(int val): value(val) {
    }
    Node (int val, Node* n) : value(val), next(n) {
    }
};

Node* reverseList(Node* head) {
    if (head->next == nullptr) {
        return head;
    }

    Node* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main() {
    int N;
    cin >> N;

    Node* head;
    int val;
    cin >> val;
    head->value = val;
    head->next = nullptr;

    Node* currNode = head;


    for (int i = 1; i<N; i++) {
        cin >> val;
        Node* node = new Node(val);
        currNode->next = node;
        currNode = node;
    }

    Node* newHead = reverseList(head);
    while (newHead != nullptr) {
        cout << newHead->value << " ";
        newHead = newHead->next;
    }
}