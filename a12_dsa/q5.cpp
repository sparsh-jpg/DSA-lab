
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

Node* createNode(int x) {
    Node* node = new Node;
    node->data = x;
    node->left = node->right = nullptr;
    node->lthread = false;
    node->rthread = false;
    return node;
}

Node* insert(Node* root, int x) {
    if (root == nullptr)
        return createNode(x);

    if (x < root->data) {
        if (root->lthread)
            root->left = insert(nullptr, x);
        else
            root->left = insert(root->left, x);
    }
    else {
        if (root->rthread)
            root->right = insert(nullptr, x);
        else
            root->right = insert(root->right, x);
    }

    return root;
}

void convert(Node* root, Node*& prev) {
    if (!root)
        return;

    Node* left = root->left;
    Node* right = root->right;

    convert(left, prev);

    if (!root->left) {
        root->left = prev;
        root->lthread = true;
    }

    if (prev && !prev->right) {
        prev->right = root;
        prev->rthread = true;
    }

    prev = root;

    convert(right, prev);
}

Node* leftmost(Node* root) {
    if (!root)
        return nullptr;

    while (!root->lthread && root->left)
        root = root->left;

    return root;
}

Node* rightmost(Node* root) {
    if (!root)
        return nullptr;

    while (!root->rthread && root->right)
        root = root->right;

    return root;
}

Node* successor(Node* root) {
    if (root->rthread)
        return root->right;

    return leftmost(root->right);
}

Node* predecessor(Node* root) {
    if (root->lthread)
        return root->left;

    return rightmost(root->left);
}

Node* search(Node* root, int x) {
    while (root) {
        if (root->data == x)
            return root;

        if (x < root->data) {
            if (root->lthread)
                return nullptr;
            root = root->left;
        }
        else {
            if (root->rthread)
                return nullptr;
            root = root->right;
        }
    }

    return nullptr;
}

void rangeQuery(Node* root, int L, int R) {
    Node* curr = root;

    while (curr && curr->data < L) {
        if (curr->rthread)
            curr = curr->right;
        else
            curr = curr->right;
    }

    if (curr) {
        while (curr && curr->data <= R) {
            cout << curr->data << " ";
            curr = successor(curr);
        }
    }
}

void kthSmallest(Node* root, int k) {
    Node* curr = leftmost(root);

    if (k <= 0) {
        cout << "NULL";
        return;
    }

    while (curr && k > 1) {
        curr = successor(curr);
        k--;
    }

    if (curr)
        cout << curr->data;
    else
        cout << "NULL";
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

    if (prev)
        prev->rthread = true;

    int q;
    cin >> q;

    while (q--) {
        string op;
        cin >> op;

        if (op == "NEXT") {
            cin >> x;
            Node* curr = search(root, x);
            Node* ans = curr ? successor(curr) : nullptr;

            cout << "NEXT " << x << " = ";
            if (ans)
                cout << ans->data;
            else
                cout << "NULL";
            cout << endl;
        }
        else if (op == "PREV") {
            cin >> x;
            Node* curr = search(root, x);
            Node* ans = curr ? predecessor(curr) : nullptr;

            cout << "PREV " << x << " = ";
            if (ans)
                cout << ans->data;
            else
                cout << "NULL";
            cout << endl;
        }
        else if (op == "RANGE") {
            int L, R;
            cin >> L >> R;

            cout << "RANGE = [";
            bool first = true;

            Node* curr = root;
            while (curr) {
                if (curr->data >= L) {
                    if (!curr->lthread && curr->left)
                        curr = curr->left;
                    else
                        break;
                }
                else {
                    if (!curr->rthread)
                        curr = curr->right;
                    else
                        curr = curr->right;
                }
            }

            while (curr && curr->data <= R) {
                if (!first)
                    cout << ",";
                cout << curr->data;
                first = false;
                curr = successor(curr);
            }

            cout << "]" << endl;
        }
        else if (op == "KTH") {
            int k;
            cin >> k;
            cout << "KTH " << k << " = ";
            kthSmallest(root, k);
            cout << endl;
        }
    }

    return 0;
}
