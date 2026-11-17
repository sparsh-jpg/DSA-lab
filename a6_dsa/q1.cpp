#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    void reversingCLL(Node*& head) {
        if (head == nullptr || head->next == head) {
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        Node* nextNode = nullptr;

        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        head->next = prev;
        head = prev;
    }
};

void printCircularLL(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* temp = head;
    int nums[5] = {3, 7, 9, 6, 2};

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    temp->next = head;

    Solution s;
    cout << "Original Circular Linked List: ";
    printCircularLL(head);

    s.reversingCLL(head);

    cout << "Reversed Circular Linked List: ";
    printCircularLL(head);

    return 0;
}