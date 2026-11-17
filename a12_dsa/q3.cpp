
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int x) {
        val = x;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void parentMap(Node* root, unordered_map<Node*, Node*>& parent) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

Node* findTarget(Node* root, int target) {
    if (!root) return nullptr;
    if (root->val == target) return root;

    Node* left = findTarget(root->left, target);
    if (left) return left;

    return findTarget(root->right, target);
}

vector<int> distanceK(Node* root, int target, int k) {
    unordered_map<Node*, Node*> parent;
    parentMap(root, parent);

    Node* start = findTarget(root, target);

    queue<Node*> q;
    unordered_map<Node*, bool> visited;

    q.push(start);
    visited[start] = true;

    int dist = 0;

    while (!q.empty()) {
        int size = q.size();

        if (dist == k) {
            vector<int> ans;
            while (!q.empty()) {
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
        }

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if (parent[curr] && !visited[parent[curr]]) {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }

        dist++;
    }

    return {};
}

int main() {
    int n, x;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target, k;
    cin >> target >> k;

    Node* root = buildTree(arr);

    vector<int> ans = distanceK(root, target, k);

    cout << "[ ";
    for (int x : ans)
        cout << x << " ";
    cout << "]";

    return 0;
}
