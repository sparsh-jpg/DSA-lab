#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val = 0) : data(val), next(nullptr) {}
};

void print(Node* head) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void insert_at_begin(Node*& head, int data) {
    Node* elem = new Node(data);

    if (head == nullptr) {
        head = elem;
        head->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    elem->next = head;
    tail->next = elem;
    head = elem;
}

void insert_at_end(Node*& head, int data) {
    Node* elem = new Node(data);

    if (head == nullptr) {
        head = elem;
        head->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = elem;
    elem->next = head;
}

void insert_at_pos(Node*& head, int data, int pos) {
    if (head == nullptr) {
        if (pos == 1) {
            head = new Node(data);
            head->next = head;
        }
        return;
    }

    if (pos <= 1) {
        insert_at_begin(head, data);
        return;
    }

    Node* temp = head;
    int index = 1;
    while (index < pos - 1 && temp->next != head) {
        temp = temp->next;
        index++;
    }

    if (temp->next == head && pos > index + 1) {
        insert_at_end(head, data);
        return;
    }

    Node* elem = new Node(data);
    elem->next = temp->next;
    temp->next = elem;
}

void delete_node(Node*& head, int pos) {
    if (head == nullptr) {
        return;
    }

    if (head->next == head) {
        if (pos == 1) {
            delete head;
            head = nullptr;
        }
        return;
    }

    if (pos == 1) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;
    }

    Node* temp = head;
    int index = 1;
    while (index < pos - 1 && temp->next != head) {
        temp = temp->next;
        index++;
    }

    if (temp->next == head) {
        return;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    delete node_to_delete;
}

int main() {
    int n;
    cout << "Enter size of linked list : ";
    cin >> n;

    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter element no " << i << ": ";
        cin >> val;
        insert_at_end(head, val);
    }

    cout << "Insert at begin : ";
    insert_at_begin(head, 100);
    print(head);
    cout << "\n";

    cout << "Insert at end : ";
    insert_at_end(head, 200);
    print(head);
    cout << "\n";

    cout << "Insert at pos : ";
    insert_at_pos(head, 300, 2);
    print(head);
    cout << "\n";

    cout << "Delete at begin : ";
    delete_node(head, 1);
    print(head);
    cout << "\n";

    cout << "Delete at pos : ";
    delete_node(head, 3);
    print(head);
    return 0;
}
