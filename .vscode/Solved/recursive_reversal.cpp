#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* next; //pointer to next node
};

Node* reverseList(Node* head) { //head points to the given node
    if (head->next == nullptr) { // -> changes it back to non pointer and gives you the value
        return head;
    }

    Node* reversedHead = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return reversedHead;
};


int main() {
    int N;
    cin >> N;
    
    int val;
    cin >> val;
    Node* head = new Node();
    head->value = val;
    head->next = nullptr;

    Node* currNode = head;
    
    for (int i = 1; i<N; i++) {
        cin >> val;
        Node* node = new Node();
        node->value = val;
        node->next = nullptr;

        currNode->next = node;
        currNode = node;
    }

    Node* node = reverseList(head);
    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }
    cout << "\n";


}

