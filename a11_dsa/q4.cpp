#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

struct Info {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

int ans = 0;

Info solve(Node* root) {
    if (root == NULL) {
        return {true, INT_MAX, INT_MIN, 0};
    }

    Info left = solve(root->left);
    Info right = solve(root->right);

    if (!left.isBST || !right.isBST) {
        return {false, 0, 0, 0};
    }

    if ((root->left != NULL && left.maxVal >= root->data) ||
        (root->right != NULL && right.minVal <= root->data)) {
        return {false, 0, 0, 0};
    }

    int subtreeSum = left.sum + right.sum + root->data;
    ans = max(ans, subtreeSum);

    return {
        true,
        min(root->data, left.minVal),
        max(root->data, right.maxVal),
        subtreeSum
    };
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    solve(root);
    cout << "Maximum sum BST: " << ans << endl;
    return 0;
}