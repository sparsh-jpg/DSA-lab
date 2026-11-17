
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    newNode->lthread = false;
    newNode->rthread = false;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void convert(Node* root, Node*& prev) {
    if (root == nullptr)
        return;

    convert(root->left, prev);

    if (root->left == nullptr) {
        root->left = prev;
        root->lthread = true;
    }

    if (prev != nullptr && prev->right == nullptr) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    convert(root->right, prev);
}

Node* leftmost(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->lthread == false && root->left != nullptr)
        root = root->left;

    return root;
}

void inorder(Node* root) {
    Node* curr = leftmost(root);

    while (curr != nullptr) {
        cout << curr->data << " ";

        if (curr->rthread)
            curr = curr->right;
        else
            curr = leftmost(curr->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    Node* prev = nullptr;
    convert(root, prev);

    if (prev != nullptr && prev->right == nullptr)
        prev->rthread = true;

    inorder(root);

    return 0;
}
