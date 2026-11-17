#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}
};

void printList(const Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

int listLength(const Node* head) {
    int length = 0;
    while (head != nullptr) {
        ++length;
        head = head->next;
    }
    return length;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    std::cout << "Linked List of 5 elements: ";
    printList(head);
    std::cout << '\n';

    Node* newHead = new Node(100);
    newHead->next = head;
    head = newHead;

    std::cout << "Linked List of elements after adding at start: ";
    printList(head);
    std::cout << '\n';

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = new Node(200);

    std::cout << "Linked List of elements after adding at end: ";
    printList(head);
    std::cout << '\n';

    int position;
    std::cout << "Enter a position to add: ";
    if (!(std::cin >> position)) {
        deleteList(head);
        std::cerr << "Invalid input.\n";
        return 1;
    }

    const int length = listLength(head);
    if (position < 1 || position > length + 1) {
        std::cout << "Invalid insertion position.\n";
    } else {
        Node* inserted = new Node(300);
        if (position == 1) {
            inserted->next = head;
            head = inserted;
        } else {
            Node* previous = head;
            for (int i = 1; i < position - 1; ++i) {
                previous = previous->next;
            }
            inserted->next = previous->next;
            previous->next = inserted;
        }

        std::cout << "Linked List of elements after adding at position "
                  << position << ": ";
        printList(head);
    }
    std::cout << '\n';

    int deletePosition;
    std::cout << "Enter a position to delete: ";
    if (!(std::cin >> deletePosition)) {
        deleteList(head);
        std::cerr << "Invalid input.\n";
        return 1;
    }

    if (deletePosition < 1 || deletePosition > listLength(head)) {
        std::cout << "Invalid deletion position.\n";
    } else if (deletePosition == 1) {
        Node* removed = head;
        head = head->next;
        delete removed;
    } else {
        Node* previous = head;
        for (int i = 1; i < deletePosition - 1; ++i) {
            previous = previous->next;
        }
        Node* removed = previous->next;
        previous->next = removed->next;
        delete removed;
    }

    std::cout << "Linked List after deleting position " << deletePosition << ": ";
    printList(head);
    deleteList(head);
    return 0;
}
