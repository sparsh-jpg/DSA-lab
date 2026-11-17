
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root, vector<int>& arr) {
    if (root == nullptr)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int kthSmallest(vector<int>& arr, int k) {
    if (k <= 0 || k > arr.size())
        return -1;

    return arr[k - 1];
}

int main() {
    Node* root = nullptr;
    int n, x, q, k;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    vector<int> arr;
    inorder(root, arr);

    cin >> q;

    while (q--) {
        cin >> k;
        cout << kthSmallest(arr, k) << " ";
    }

    return 0;
}
