#include <bits/stdc++.h> 
using namespace std; 
struct TreeNode { 
int val; 
TreeNode* left; 
TreeNode* right; 
TreeNode(int x) { 
val = x; 
left = nullptr; 
right = nullptr; 
} 
}; 
void inorderTraversal(TreeNode* root, vector<int>& inorder) { 
if (root == nullptr) 
return; 
inorderTraversal(root->left, inorder); 
inorder.push_back(root->val); 
inorderTraversal(root->right, inorder); 
} 
int main() { 
vector<int> inorder; 
TreeNode* root = new TreeNode(5); 
root->left = new TreeNode(3); 
root->right = new TreeNode(7); 
root->left->left = new TreeNode(2); 
root->left->right = new TreeNode(4); 
root->right->left = new TreeNode(6); 
root->right->right = new TreeNode(8); 
inorderTraversal(root, inorder); 
int k = 2; 
cout << "Inorder array: "; 
for (int x : inorder) 
cout << x << " "; 
cout << "\nKth smallest = " << inorder[k - 1]; 
cout << "\nKth largest = " << inorder[inorder.size() - k]; 
return 0; 
}