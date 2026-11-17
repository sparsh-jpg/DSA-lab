#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};
class Solution {
public:
    void reversingDLL(Node*& head) {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            head = current;
            current = temp;
        }
    }
};

void printDoublyLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(10);
    Node* temp = head;
    int nums[5] = {3, 7, 9, 6, 2};

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }

    Solution s;
    cout << "Original Doubly Linked List: ";
    printDoublyLL(head);

    s.reversingDLL(head);

    cout << "Reversed Doubly Linked List: ";
    printDoublyLL(head);

    return 0;
}